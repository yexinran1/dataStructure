#include<stdio.h>
#include <stdlib.h>
#include"LinkList.h"
#include<string.h>
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 链表初始化 */
int LinkListInit(LinkList **pList)
{
    int ret;
    LinkList *list = (LinkList*)malloc(sizeof(LinkList) * 1);
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list, 0, sizeof(LinkList) * 1);
    list->head = (LinkList *)malloc(sizeof(LinkNode) * 1);
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list->head, 0, sizeof(LinkNode) * 1);
    list->head->data = 0;
    list->head->next = 0;
    /* 初始化的时候尾指针 = 头指针 */
    list->tail = list->head;
    
    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针 */
    *pList = list;
    return ret;
    

}

/* 链表头插 */
int LinkListHeadInsert(LinkList *pList, ELEMEMTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int LinkListTailInsert(LinkList *pList, ELEMEMTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMEMTTYPE val)
{
    int ret;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 封装结点 */
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(newNode, 0, sizeof(LinkNode) * 1);

    /* 赋值 */
    newNode->data = val;

#if 1
    LinkNode * travelNode = pList->head;
#else
    LinkNode * travelNode = pList->head->next;
#endif
    int flag = 0;
    //这种情况下需要更改指针
    if(pos == pList->len)
    {
        travelNode = pList->tail;
        flag = 1;
    }
    else{
        while(pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }
    /* 修改结点指向 */
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if(flag)
    {
        pList->tail = newNode;
    }
    /* 修改链表长度*/
    (pList->len)++;
    return ret;
}

/* 头删除 */
int LinkListHeadDel(LinkList *pList)
{
    LinkListDelAppointPos(pList, 1);
}

/* 尾删除 */
int LinkListTailDel(LinkList *pList)
{
    LinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList *pList, int pos)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if(pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
#if 1
    LinkNode * travelNode = pList->head;
#else
#endif
    while(--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
        //pos--;
    }
    //跳出循环找到的是哪一个结点 
    LinkNode * needDelNode = travelNode->next;;
    travelNode->next = needDelNode->next;

    /* 释放内存 */
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;                                                            
    }
    /* 链表长度减一 */
    (pList->len)--;
    return ret;
}

/* 删除指定数据 */
int LinkListDelAppointData(LinkList *pList, ELEMEMTTYPE val)
{

}

/* 获取链表长度 */
int LinkListGetLength(LinkList *pList, int *pSize)
{
    //int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    if(pSize)
    {
        *pSize = pList->len;
    }
    /* 返回链表的长度 */
    return pList->len;

}
/* 链表的销毁 */
int LinkListDestory(LinkList *pList)
{
    int ret = 0;
    /* 使用头删 */
    int size = 0;
    while(LinkListGetLength(pList, &size))
    {
        LinkListHeadDel(pList);
    }
    if(pList->head != NULL)
    {
        free(pList->head);
        /* 指针位置置为NULLL */
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ret;
}

/* 链表遍历接口 */
int LinkListForeach(LinkList *pList)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    /* travelNode指向虚拟头结点 */
    LinkNode * travelNode = pList->head;
    while(travelNode->next != NULL)
    {
        travelNode = travelNode->next;
       printf("travelNode->data:%d\n", travelNode->data);
    } 
#else
    /* travelNode指向链表第一个元素 */
    LinkNode * travelNode = pList->head;
    while(travelNode != NULL)
    {
       printf("travelNode->data:%d\n", travelNode->data);
       travelNode = travelNode->next;
    } 
#endif
    return ret;
}
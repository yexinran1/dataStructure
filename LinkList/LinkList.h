#ifndef _LINKLIST_H_
#define _LINKLIST_H_   

#define ELEMEMTTYPE int

/* 链表结点取别名*/
typedef struct LinkNode
{
    ELEMEMTTYPE data;
    /* 指向下一个节点的指针 */
    struct LinkNode *next;  /* 指针的类型 */
}LinkNode;

/* 链表 */
typedef struct LinkList
{
    /* 链表的虚拟头结点*/
    LinkList * head;
    /* 链表长度 */
    int len;
}LinkList;

/* 链表初始化 */
int LinkListInit();

/* 链表头插 */
int LinkListHeadInsert();

/* 链表尾插 */
int LinkListTailInsert();

/* 链表指定位置插入 */
int LinkListAppointPosInsert();

/* 头删除 */
int LinkListHeadDel();

/* 尾删除 */
int LinkListTailDel();

/* 链表指定位置删除 */
int LinkListDelAppointPos();

/* 删除指定数据 */
int LinkListDelAppointData();

/* 获取链表长度 */
int LinkListGetLength();

/* 链表的销毁 */
int LinkListDestory();

#endif
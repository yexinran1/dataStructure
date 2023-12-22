#ifndef _LINKLIST_H_
#define _LINKLIST_H_   

#define ELEMEMTTYPE void*

/* 链表结点取别名 */
typedef struct LinkNode
{
    ELEMEMTTYPE data;
    /* 指向下一个结点的指针 */
    struct  LinkNode * next;
}LinkNode;


/* 链表 */
typedef struct LinkList
{
    /* 链表的虚拟头结点*/
    LinkNode * head;
    LinkNode * tail;    /* 为什么尾指针不需要分配空间 */
    /* 链表长度 */
    int len;
}LinkList;

/* 链表初始化 */
int LinkListInit(LinkList **pList);

/* 链表头插 */
int LinkListHeadInsert(LinkList *pList, ELEMEMTTYPE val);

/* 链表尾插 */
int LinkListTailInsert(LinkList *pList, ELEMEMTTYPE val);

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMEMTTYPE val);

/* 头删除 */
int LinkListHeadDel(LinkList *pList);

/* 尾删除 */
int LinkListTailDel(LinkList *pList);

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList *pList, int pos);

/* 删除指定数据 */
int LinkListDelAppointData(LinkList *pList, ELEMEMTTYPE val, int(*compareFunc)(ELEMEMTTYPE, ELEMEMTTYPE));

/* 获取链表长度 */
int LinkListGetLength(LinkList *pList, int *pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList *pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList *pList, int (*printFunc)(ELEMEMTTYPE));

#endif
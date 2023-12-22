#ifndef _DOUBLELINKLIST_H_
#define _DOUBLELINKLIST_H_   

#define ELEMEMTTYPE void*

/* 链表结点取别名 */
typedef struct DoubleLinkNode
{ 
    ELEMEMTTYPE data;
    /* 指向前一个结点的指针 */
    struct DoubleLinkNode * prev;
    /* 指向下一个结点的指针 */
    struct  DoubleLinkNode * next;
}DoubleLinkNode;


/* 链表 */
typedef struct doubleLinkList
{
    /* 链表的虚拟头结点*/
    DoubleLinkNode * head;
    DoubleLinkNode * tail;    /* 为什么尾指针不需要分配空间 */
    /* 链表长度 */
    int len;
} doubleLinkList;

/* 链表初始化 */
int doubleLinkListInit(doubleLinkList **pList);

/* 链表头插 */
int doubleLinkListHeadInsert(doubleLinkList *pList, ELEMEMTTYPE val);

/* 链表尾插 */
int doubleLinkListTailInsert(doubleLinkList *pList, ELEMEMTTYPE val);

/* 链表指定位置插入 */
int doubleLinkListAppointPosInsert(doubleLinkList *pList, int pos, ELEMEMTTYPE val);

/* 头删除 */
int doubleLinkListHeadDel(doubleLinkList *pList);

/* 尾删除 */
int doubleLinkListTailDel(doubleLinkList *pList);

/* 链表指定位置删除 */
int doubleLinkListDelAppointPos(doubleLinkList *pList, int pos);

/* 删除指定数据 */
int doubleLinkListDelAppointData(doubleLinkList *pList, ELEMEMTTYPE val, int(*compareFunc)(ELEMEMTTYPE, ELEMEMTTYPE));

/* 获取链表长度 */
int doubleLinkListGetLength(doubleLinkList *pList, int *pSize);

/* 链表的销毁 */
int doubleLinkListDestory(doubleLinkList *pList);

/* 链表遍历接口 */
int doubleLinkListForeach(doubleLinkList *pList, int (*printFunc)(ELEMEMTTYPE));

#endif
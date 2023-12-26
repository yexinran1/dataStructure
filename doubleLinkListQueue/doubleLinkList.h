#ifndef _DOUBLELINKLIST_H_
#define _DOUBLELINKLIST_H_   

#include"commom.h"

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


int doubleLinkListReverseForeach(doubleLinkList *pList, int (*printFunc)(ELEMEMTTYPE));

/* 获取头位置的值 */
int doubleLinkListGetHeadVal(doubleLinkList *pList, ELEMEMTTYPE *pVal);

/* 获取链表头位置的值 */
int doubleLinkListGetTailVal(doubleLinkList *pList, ELEMEMTTYPE *pVal);

/* 获取链表指定位置的值 */
int doubleLinkListGetAppointVal(doubleLinkList *pList, int pos, ELEMEMTTYPE *pVal);
#endif
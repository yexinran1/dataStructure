#ifndef __DYNAMIC_ARRAY_STACK_H_
#define __DYNAMIC_ARRAY_STACK_H_

//#include"dynamicArray.h"
#include"common.h"
/* 取别名 */
typedef dynamicArray dynamicArrayStACK;

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStACK *pStack);

/* 压栈 */
int dynamicArrayStackPush(dynamicArrayStACK *pStack, ELEMENTTYPE val);

/* 查看栈顶元素 */
int dynamicArrayStackTop(dynamicArrayStACK *pStack, ELEMENTTYPE *pVal);

/* 出栈 */
int dynamicArrayStackPop(dynamicArrayStACK *pStack);

/* 栈是否为空 */
int dynamicArrayStackIsEmpty(dynamicArrayStACK *pStack);

/* 获得栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStACK *pStack, int *pSize);

/* 销毁 */
int dynamicArrayStackDestory(dynamicArrayStACK *pStack);





#endif
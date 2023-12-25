#include"dynamicArray.h"
#include"dynamicArrayStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_SIZE 10

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStACK *pStack)
{
    return dynamicArrayInit(pStack, DEFAULT_SIZE);
}

/* 压栈 */
int dynamicArrayStackPush(dynamicArrayStACK *pStack, ELEMENTTYPE val)
{
    /* 调用动态数组的尾插 */
    return dynamicArrayInsertData(pStack, val);
}

/* 查看栈顶元素 */
int dynamicArrayStackTop(dynamicArrayStACK *pStack, ELEMENTTYPE *pVal)
{
    /* 获取指定位置的元素（末尾 */
    return dynamicArrayGetAppointPosVal(pStack, pStack->len - 1, pVal);
}

/* 出栈 */
int dynamicArrayStackPop(dynamicArrayStACK *pStack)
{
    dynamicArrayDeleteData(pStack);
}

/* 栈是否为空 */
int dynamicArrayStackIsEmpty(dynamicArrayStACK *pStack)
{
    int size = 0;
    return dynamicArrayGetSize(pStack, &size);
    return size == 0 ? 1 : 0;
}

/* 获得栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStACK *pStack, int *pSize)
{
    #if 1
    return dynamicArrayGetSize(pStack, pSize);
    #else
    dynamicArrayGetSize(pStack, pSize);
    if(pSize)
    {
        return *pSize;
    }
    #endif
}

/* 销毁 */
int dynamicArrayStackDestory(dynamicArrayStACK *pStack)
{
    dynamicArrayDestory(pStack);
}

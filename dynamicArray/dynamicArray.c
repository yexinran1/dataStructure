#include<stdio.h>
#include"dynamicArray.h"
#include<stdlib.h>
#include<string.h>

/* 状态码*/
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

#define DEFAULT_SIZE 10

/* 静态函数前置声明 */
static int expandDynamicCapacity(dynamicArray *pArray);
static int shrinkDynamicCapacity(dynamicArray *pArray);

/* API：application program interface*/
/* 动态数组初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 避免传入非法值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }
    /* 分配空间 */
    pArray->data = (ELEMENTTYPE*)malloc(sizeof(ELEMENTTYPE) * capacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    /* 初始化动态数组的参数属性 */
    pArray->len = 0;
    pArray->capacity = capacity;
    return ON_SUCCESS;
}

/* 动态数组插入数据(默认插到数组的末尾) */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    return dynamicArrayAppointPosInsertData(pArray, pArray->len, val);
}

/* 扩容 */
static int expandDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);
    /* 备份指针 */
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE*)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 把之前的数据全部拷贝过来 */
    for(int idx = 0; idx< pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx]; 
    }

    /* 释放以前的内存， 避免内存泄漏 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    pArray->capacity = needExpandCapacity;
    return ret;
}

/* 动态数组插入数据，在指定位置插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if(pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }
    #if 1
    /* 数组扩容的临界值是：数组大小的1.5倍 >=数组容量 */
    if((pArray->len + (pArray->len >> 1)) < pArray->capacity)
    {
        /* 开始扩容 */
        expandDynamicCapacity(pArray);
    }
    #endif
#if 1
    /* 数据后移，流出pos位置插入 */
    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
#else
    for(int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx + 1] = pArray->data
    }
#endif
    /* 找到对应的值，填入到数组中 */
    pArray->data[pos] = val;
    /* 数组的大小加一 */
    (pArray->len) ++;
}

/* 动态数组修改指定位置的数据 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 判断位置的合法性 */
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    /* 更新指定位置的数据 */
    pArray->data[pos] = val;

    return ON_SUCCESS;
}


/* 动态数组删除数据(默认情况下删除末尾的数据) */
int dynamicArrayDeleteData(dynamicArray *pArray)
{
    dynamicArrayDeleteAppointPosData(pArray, pArray->len - 1);
}

/* 静态函数一定要前置声明 */
/* 缩容 */
static shrinkDynamicCapacity(dynamicArray *pArray)
{
    int needShrinkCapacity = pArray->capacity - (pArray->capacity >> 1);
    /* 备份指针 */
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE*)malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 把之前的数据全部拷贝过来 */
    for(int idx = 0; idx< pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx]; 
    }

    /* 释放以前的内存， 避免内存泄漏 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    pArray->capacity = needShrinkCapacity;
    return ON_SUCCESS;
}

/* 动态数组删除指定位置数据 */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }
    /* 缩容量 */
    if(pArray->len < pArray->capacity >> 1)
    {
        shrinkDynamicCapacity(pArray);
    }
     /* 数据前移 */
    for(int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }
    /* 更新数组的大小 */
    (pArray->len--);
    return ON_SUCCESS;
}

/* 动态数组删除指定的元素 */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
   

}
/* 动态数组的销毁 */
int dynamicArrayDestory(dynamicArray *pArray)
{

}

/* 获取动态数组的大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{

}

/* 获取动态数组的容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{

}

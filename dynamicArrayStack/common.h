#ifndef __COMMON_H_
#define __COMMON_H_
#if 0
typedef void* ELEMENTTYPE;
#else
#define ELEMENTTYPE void*
#endif
/* 避免头文件重复包含 */
typedef struct dynamicArray
{
    ELEMENTTYPE *data;       /* 数组的空间 */
    int len;                /* 数组的大小 */
    int capacity;           /* 数组的容量 */

}dynamicArray;
#endif
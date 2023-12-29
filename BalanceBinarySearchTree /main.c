#include<stdio.h>
#include "balanceBinarySearchTree .h"

#define BUFFER_SIZE 10

/* 测试二叉搜索树 */
int compareBasicDataFunc(void * arg1, void * arg2)
{
    int val1 = *(int *)arg1;
    int val2 = *(int *)arg2;
    return val1 - val2;
}

/* 打印基础数据 */
int printBasicData(void * arg)
{
    int ret = 0;
    int val = *(int *)arg;
    printf("val:%d\t", val);
    return ret;
}


int main()
{
    BalanceBinarySearchTree * AVL;
    balanceBinarySearchTreeInit(&AVL, compareBasicDataFunc, printBasicData);
    
    int buffer[BUFFER_SIZE] = {56, 28, 75, 73, 77, 13, 7, 26, 100, 12};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        balanceBinarySearchTreeInsert(AVL, (void *)&buffer[idx]);
    }

{
    /* 获取二叉搜索树的结点个数 */
    int size = 0;
    balanceBinarySearchTreeGetNodeSize(AVL, &size);
    printf("size: %d\n", size);
}
{
    /* 获取二叉搜索树的高度 */
    int height = 0;
    balanceBinarySearchTreeGetHeight(AVL, &height);
    printf("height: %d\n", height);
}
    
#if 1
    /* 中序遍历 */
    printf("中序遍历:\n");
    balanceBinarySearchTreeInOrderTravel(AVL);
    printf("\n");

    /* 前序遍历 */
    printf("前序遍历:\n");
    balanceBinarySearchTreePreOrderTravel(AVL);
    printf("\n");

    /* 后序遍历 */
    printf("后序遍历:\n");
    balanceBinarySearchTreePosOrderTravel(AVL);
    printf("\n");


#else
    /* 层序遍历 */
    printf("层序遍历:\n");
    balanceBinarySearchTreeLevelOrderTravel(AVL);
    printf("\n");
#endif
{
    /* 是否包含指定元素 */
    printf("测试是否包含指定元素：\n");
    int val = 1;   
    int result = balanceBinarySearchTreeIsContainAppointVal(AVL, &val);
    if(result)
    {
        printf("包含\n");
    }
    else
    {
         printf("不包含\n");
    }
}
{
    printf("删除指定元素：\n");
    int val = 56;
    balanceBinarySearchTreeDelete(AVL, &val);
    balanceBinarySearchTreeLevelOrderTravel(AVL);
    printf("\n");
    int size = 0;
    balanceBinarySearchTreeGetNodeSize(AVL, &size);
    printf("size: %d\n", size);
    int height = 0;
    balanceBinarySearchTreeGetHeight(AVL, &height);
    printf("height: %d\n", height);

}
    

    


    return 0;
}
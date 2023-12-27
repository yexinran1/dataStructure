#include<stdio.h>
#include "BinarySearchTree.h"

#define BUFFER_SIZE 5

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
    printf("val:%d\n", val);
    return ret;
}


int main()
{
    BinarySearchTree * BST;
    binarySearchTreeInit(&BST, compareBasicDataFunc, printBasicData);
    
    int buffer[BUFFER_SIZE] = {56, 28, 75, 73, 77};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        binarySearchTreeInsert(BST, (void *)&buffer[idx]);
    }

    /* 获取二叉搜索树的结点个数 */
    int size = 0;
    binarySearchTreeGetNodeSize(BST, &size);
    printf("size: %d\n", size);

    /* 获取二叉搜索树的高度 */
    int height = 0;
    binarySearchTreeGetHeight(BST, &height);
    printf("height: %d\n", height);


    return 0;
}
#include "BinarySearchTree.h"
#include<string.h>
#include<stdlib.h>
/* 状态码*/
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 二叉搜素树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBStree)
{
    int ret = 0;
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if(bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
    }
#if 1    
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
#endif

    *pBStree = bstree;
    return ret;
}

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree **pBStree, ELEMEMTTYPE val)
{
    int ret = 0;
    return 0;
}
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
static int compareFunc(ELEMEMTTYPE val1, ELEMEMTTYPE val2);
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
    /* 分配根节点 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
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

static int compareFunc(ELEMEMTTYPE val1, ELEMEMTTYPE val2)
{
    return val1 - val2;
}

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBStree, ELEMEMTTYPE val)
{
    int ret = 0;
    /* 空树 */
    if (pBStree->size == 0)
    {
        /* 更新树的结点 */
        (pBStree->size)++;
        pBStree->root->data = val;
    }

    /* travelNode指向根节点 */
    BSTreeNode * travelNode = pBStree->root;
    BSTreeNode * parentNode = pBStree->root;
    /* 比较传入的值 确定符号 到底放在左边右边 */
    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 标记父节点 */
        parentNode = travelNode;
        cmp = compareFunc(val, travelNode->data);
        /* 插入元素 < 遍历的结点 */
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        /* 插入元素 > 遍历的结点 */
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 插入元素 = 遍历的结点 */
            return ret;
        }
    }
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 新结点赋值 */
    newBstNode->data = val;
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else
    {
        parentNode->right = newBstNode;
    }
    /* 新结点的parent赋值 */
    newBstNode->parent = parentNode;
    /* 更新树的结点 */
    (pBStree->size)++;
    return ret;
}
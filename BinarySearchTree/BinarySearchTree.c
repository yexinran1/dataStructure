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
/* 静态函数前置声明 */
static int compareFunc(ELEMEMTTYPE val1, ELEMEMTTYPE val2);

/* 创建结点 */
static BSTreeNode * createBSTreeNewNode(ELEMEMTTYPE val, BSTreeNode *parent);

/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBStree, ELEMEMTTYPE val, int(*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2));

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
#if 0    
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
#else
    bstree->root = createBSTreeNewNode(0, NULL);
    if(bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
#endif

    *pBStree = bstree;
    return ret;
}
#if 0
static int compareFunc(ELEMEMTTYPE val1, ELEMEMTTYPE val2)
{
    return val1 - val2;
}
#endif

static BSTreeNode * createBSTreeNewNode(ELEMEMTTYPE val, BSTreeNode *parent)
{
    /* 分配根节点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset (newBstNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 赋值 */
    newBstNode->data = val;
    newBstNode->parent = parent;
    return newBstNode;
}


/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBStree, ELEMEMTTYPE val, int(*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2))
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
#if 0
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset (newBstNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根节点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 新结点赋值 */
    newBstNode->data = val;
#else
    BSTreeNode * newBstNode = createBSTreeNewNode(val, parentNode);
#endif

/* 挂在左子树 */
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else
    {
        parentNode->right = newBstNode;
    }
    /* 新结点的parent赋值 */
#if 0
    newBstNode->parent = parentNode;
#endif
    /* 更新树的结点 */
    (pBStree->size)++;
    return ret;
}

/* 根据指定的值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBStree, ELEMEMTTYPE val, int(*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2))
{
    BSTreeNode * travelNode = pBStree->root;
    while (travelNode != NULL)
    {

    }
}
/* 二叉搜索时是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBStree, ELEMEMTTYPE val, int(*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2))
{

}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    return ret;

}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    return ret;
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePosOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    return ret;
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    return ret;
}

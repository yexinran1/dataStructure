#include "BinarySearchTree.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

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
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBStree, ELEMEMTTYPE val);

/* 判断二叉搜素度为2 */
static int binarySearchTreeNodeHasTwoChildren(BSTreeNode *node);
/* 判断二叉搜素度为1 */
static int binarySearchTreeNodeHasOneChild(BSTreeNode *node);
/* 判断二叉搜素度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);

/* 二叉搜索树的前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 二叉搜索树的中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 二叉搜索树的后序遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);

/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode * node);
/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode * node);

/* 二叉搜素树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBStree, int(*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2), int(*printFunc)(ELEMEMTTYPE val))
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
        /* 钩子函数赋值 */
        bstree->compareFunc = compareFunc;
        /* 钩子函数包装器 */
        bstree->printFunc = printFunc;
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

/* 判断二叉搜素度为2 */
static int binarySearchTreeNodeHasTwoChildren(BSTreeNode *node)
{
    return (node->left != NULL) && (node->right != NULL);
}
/* 判断二叉搜素度为1 */
static int binarySearchTreeNodeHasOneChild(BSTreeNode *node)
{
    return ((node->left == NULL) && (node->right != NULL)) || ((node->right == NULL) && (node->left != NULL));
}

/* 判断二叉搜素度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    return (node->right == NULL) && (node->left == NULL);
}

/* 获取当前结点的前驱结点 中序遍历到结点的前一个结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode * node)
{
    if (node->left != NULL)
    {
        /*前驱结点是在左子树的右子树的右子树...*/
        BSTreeNode * travelNode = node->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;       
    }
    /* 程序执行到这个地方 说明一定没有左子树 那就需要想父节点找 */
    while (node->parent != NULL && (node == node->parent->left))
    {
        node = node->parent;
    }
    /* node->parent == NULL */
    /* node == node->parent->right */
    return node->parent;
}

/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode * node)
{
    if (node->right != NULL)
    {
        /* 后继结点是在右子树的左子树的左子树...*/
        BSTreeNode * travelNode = node->right;
        while (travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode;       
    }
    /* 程序执行到这个地方 说明一定没有右子树 那就需要想父节点找 */
    while (node->parent != NULL && (node == node->parent->right))
    {
        node = node->parent;
    }
    /* node->parent == NULL */
    /* node == node->parent->right */
    return node->parent;
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
        cmp = pBStree->compareFunc(val, travelNode->data);
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
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBStree, ELEMEMTTYPE val)
{
    BSTreeNode * travelNode = pBStree->root;
    int cmp = 0;
    while (travelNode != NULL)
    {
        cmp = pBStree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 找到 */
            return travelNode;
        }
    }
    return NULL;
}
/* 二叉搜索时是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBStree, ELEMEMTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBStree, val) == NULL ? 0 : 1;
}


/* 二叉搜索树的前序遍历 */
/* 根节点 左子树 右子树 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 根节点 */
    pBstree->printFunc(node->data);
    /* 左子树 */
    inOrderTravel(pBstree, node->left);   
    /* 右子树 */
    inOrderTravel(pBstree, node->right);

}
int binarySearchTreePreOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    preOrderTravel(pBStree, pBStree->root);
    return ret;

}

/* 二叉搜索树的中序遍历 */
/* 左子树 根节点 右子树 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    inOrderTravel(pBstree, node->left);
    /* 根节点 */
    pBstree->printFunc(node->data);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);

}
int binarySearchTreeInOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    postOrderTravel(pBStree, pBStree->root);
    return ret;
}

/* 二叉搜索树的后序遍历 */
/* 左子树 右子树 根节点 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    inOrderTravel(pBstree, node->left);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);   
    /* 根节点 */
    pBstree->printFunc(node->data);
}
int binarySearchTreePosOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    postOrderTravel(pBStree, pBStree->root);
    return ret;
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBStree)
{
    int ret = 0;
    doubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);
    
    /* 根节点入队 */
    doubleLinkListQueuePush(pQueue, pBStree->root);

    /* 判断队列是否为空 */
    BSTreeNode * travelNode = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&travelNode);
    #if 0
        printf("data:%d\n", travelNode->data);
    #else
        pBStree->printFunc(travelNode->data);
    #endif
        doubleLinkListQueuePop(pQueue);

        /* 将左子树入队 */
        if (travelNode->left !=NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }

        /* 将右子树入队 */
        if (travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);
        }
    }
    /* 释放队列 */
    doubleLinkListQueueDestorty(pQueue);
    return ret;
}

/* 获取二叉搜树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight)
{
    int ret = 0;
    if (pBstree != NULL)
    {
        return NULL_PTR;
    }
    /* 空树 */
    if (pBstree->size == 0)
    {
        return 0;
    }
    doubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);
    
    /* 根节点入队 */
    doubleLinkListQueuePush(pQueue, pBstree->root);

    /* 树的高度（根节点入队高度为1） */
    int height = 1;
    
    /* 队列的大小 */
    int levelSize = 1;
    BSTreeNode * nodeVal = NULL;
    //int queueSize = 0;
    /* 判断队列是否为空 */   
    //while (doubleLinkListQueueGetSize(pQueue, &queueSize))
    while (doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        doubleLinkListQueuePop(pQueue);
        levelSize--;

        /* 左子树不为空 */
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->left);
        }

        /* 右子树不为空 */
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->right);
        }

        /* 树的当前层结点遍历结束 */
        if (levelSize == 0)
        {
            height++;
            doubleLinkListQueueGetSize(pQueue, &levelSize);
        }
    }
    /* 解引用 */
    *pHeight = height;

    /* 释放队列 */
    doubleLinkListQueueDestorty(pQueue);
    return ret;
}

/* 二叉搜索树的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMEMTTYPE val)
{
    
}

/* 二叉搜索树的销毁*/
int binarySearchTreeDestory(BinarySearchTree * pBstree)
{
    if(pBstree == NULL)
    {
        return NULL_PTR;
    }

    int ret;
    doubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    /* 根节点入队 */
    doubleLinkListQueuePush(pQueue, pBstree->root);

    BSTreeNode * nodeVal = NULL;
    while (doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        doubleLinkListQueuePop(pQueue);
        /* 左子树不为空 */
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->left);
        }

        /* 右子树不为空 */
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->right);
        }
        /* 最后释放 */
        if(nodeVal)
        {
            free(nodeVal);
            nodeVal = NULL;
        }
    }

    /* 释放队列 */
    doubleLinkListQueueDestorty(pQueue);

    /* 释放树 */
    if(pBstree)
    {
        free(pBstree);
        pBstree = NULL;
    }
    return ret;

}
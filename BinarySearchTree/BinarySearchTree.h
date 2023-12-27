#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include "doubleLinkListQueue.h"
//#define ELEMEMTTYPE int


typedef struct BSTreeNode
{
    ELEMEMTTYPE data;
    struct BSTreeNode *left;        /* 左子树 */
    struct BSTreeNode *right;       /* 右子树 */
    #if 1
    struct BSTreeNode *parent;      /* 父节点 */
    #endif

}BSTreeNode;

typedef struct BinarySearchTree
{
    /* 根节点 */
    BSTreeNode *root;
    /* 树的结点个数 */
    int size;
    /* 钩子函数比较器放在结构体 */
    int (*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2);

    /* 钩子函数 包装器(实现自定义打印函数接口) */
    int (*printFunc)(ELEMEMTTYPE val);
    /* 把队列的属性放到树里面 */
    //doubleLinkListQueue * pQueue;

}BinarySearchTree;

/* 二叉搜素树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBStree, int(*compareFunc)(ELEMEMTTYPE val1, ELEMEMTTYPE val2), int(*printFunc)(ELEMEMTTYPE val));

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBStree, ELEMEMTTYPE val);

/* 二叉搜索时是否包含指定元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBStree, ELEMEMTTYPE val);

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBStree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBStree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePosOrderTravel(BinarySearchTree *pBStree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBStree);

/* 获取二叉搜索树的结点个数 */
int binarySearchTreeGetNodeSize(BinarySearchTree *pBStree, int *pSize);

/* 获取二叉搜树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight);

/* 二叉搜索树的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMEMTTYPE val);

/* 判断树是否是完全二叉树 */
int binarySearchTreeIsComplete(BinarySearchTree *pBSTree);

/* 二叉搜索树的销毁*/
int binarySearchTreeDestory(BinarySearchTree * pBstree);

#endif
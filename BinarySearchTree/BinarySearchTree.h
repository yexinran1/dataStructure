#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMEMTTYPE int

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


}BinarySearchTree;

/* 二叉搜素树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBStree);

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree **pBStree, ELEMEMTTYPE val);




#endif
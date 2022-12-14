#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct BSTreeNode{
    Type   key;                 // 关键字(键值)
    struct BSTreeNode *left;    // 左孩子
    struct BSTreeNode *right;   // 右孩子
    struct BSTreeNode *parent;  // 父结点
}Node, *BSTree;

// 前序遍历"二叉树"
void preorder_bstree(BSTree tree);
// 中序遍历"二叉树"
void inorder_bstree(BSTree tree);
// 后序遍历"二叉树"
void postorder_bstree(BSTree tree);

// (递归实现)查找"二叉树x"中键值为key的节点
Node* bstree_search(BSTree x, Type key);
// (非递归实现)查找"二叉树x"中键值为key的节点
Node* iterative_bstree_search(BSTree x, Type key);

// 查找最小结点：返回tree为根结点的二叉树的最小结点。
Node* bstree_minimum(BSTree tree);
// 查找最大结点：返回tree为根结点的二叉树的最大结点。
Node* bstree_maximum(BSTree tree);

// 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
Node* bstree_successor(Node *x);
// 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
Node* bstree_predecessor(Node *x);

// 将结点插入到二叉树中，并返回根节点
Node* insert_bstree(BSTree tree, Type key);

// 删除结点(key为节点的值)，并返回根节点
Node* delete_bstree(BSTree tree, Type key);

// 销毁二叉树
void destroy_bstree(BSTree tree);

// 打印二叉树
void print_bstree(BSTree tree, Type key, int direction);


/*
 * 前序遍历"二叉树"
 */
void preorder_bstree(BSTree tree)
{
    /* TODO: write code as below */
    /* TODO: 前序遍历 */
    if (tree) {
        printf("%d ", tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}

/*
 * 中序遍历"二叉树"
 */
void inorder_bstree(BSTree tree)
{
    /* TODO: write code as below */
    /* TODO: 中序遍历 */
    if (tree) {
        inorder_bstree(tree->left);
        printf("%d ", tree->key);
        inorder_bstree(tree->right);
    }
}

/*
 * 后序遍历"二叉树"
 */
void postorder_bstree(BSTree tree)
{
    /* TODO: write code as below */
    /* TODO: 后序遍历 */
    if (tree) {
        postorder_bstree(tree->left);
        postorder_bstree(tree->right);
        printf("%d ", tree->key);
    }
}

/*
 * (递归实现)查找"二叉树x"中键值为key的节点
 */
Node* bstree_search(BSTree x, Type key)
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return bstree_search(x->left, key);
    else
        return bstree_search(x->right, key);
}

/*
 * (非递归实现)查找"二叉树x"中键值为key的节点
 */
Node* iterative_bstree_search(BSTree x, Type key)
{
    while ((x!=NULL) && (x->key!=key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

/*
 * 查找最小结点：返回tree为根结点的二叉树的最小结点。
 */
Node* bstree_minimum(BSTree tree)
{
    /* TODO: write code as below */
    Node *p = tree;
    Node *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->left;
        /* code */
    }
    return q;
}

/*
 * 查找最大结点：返回tree为根结点的二叉树的最大结点。
 */
Node* bstree_maximum(BSTree tree)
{
    /* TODO: write code as below */
    Node *p = tree;
    Node *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->right;
        /* code */
    }
    return q;
}

/*
 * 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
 */
Node* bstree_successor(Node *x)
{
    // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
    if (x->right != NULL)
        return bstree_minimum(x->right);

    // 如果x没有右孩子。则x有以下两种可能：
    // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    Node* y = x->parent;
    while ((y!=NULL) && (x==y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
 */
Node* bstree_predecessor(Node *x)
{
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (x->left != NULL)
        return bstree_maximum(x->left);

    // 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
    Node* y = x->parent;
    while ((y!=NULL) && (x==y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * 创建并返回二叉树结点。
 *
 * 参数说明：
 *     key 是键值。
 *     parent 是父结点。
 *     left 是左孩子。
 *     right 是右孩子。
 */
static Node* create_bstree_node(Type key, Node *parent, Node *left, Node* right)
{
    Node* p;

    /* TODO: write code as below */
    /* TODO: 创建并返回二叉树结点 */
    p = (Node *)malloc(sizeof(Node));
    if (NULL == p) {
        return NULL;
    }
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;

    return p;
}

/*
 * 将结点插入到二叉树中
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 插入的结点
 * 返回值：
 *     根节点
 */
static Node* bstree_insert(BSTree tree, Node *z)
{
    Node *y = NULL;
    Node *x = tree;

    // 查找z的插入位置
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y==NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}

/*
 * 新建结点(key)，并将其插入到二叉树中
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     key 插入结点的键值
 * 返回值：
 *     根节点
 */
Node* insert_bstree(BSTree tree, Type key)
{
    Node *z;    // 新建结点

    // 如果新建结点失败，则返回。
    if ((z=create_bstree_node(key, NULL, NULL, NULL)) == NULL)
        return tree;

    return bstree_insert(tree, z);
}

/*
 * 删除结点(z)，并返回根节点
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 删除的结点
 * 返回值：
 *     根节点
 */
static Node* bstree_delete(BSTree tree, Node *z)
{
    Node *x=NULL;
    Node *y=NULL;

    if ((z->left == NULL) || (z->right == NULL) )
        y = z;
    else
        y = bstree_successor(z);

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if (x != NULL)
        x->parent = y->parent;

    if (y->parent == NULL)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != z)
        z->key = y->key;

    if (y!=NULL)
        free(y);

    return tree;
}

/*
 * 删除结点(key为节点的键值)，并返回根节点
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 删除的结点
 * 返回值：
 *     根节点
 */
Node* delete_bstree(BSTree tree, Type key)
{
    Node *z, *node;

    if ((z = bstree_search(tree, key)) != NULL)
        tree = bstree_delete(tree, z);

    return tree;
}

/*
 * 销毁二叉树
 */
void destroy_bstree(BSTree tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy_bstree(tree->left);
    if (tree->right != NULL)
        destroy_bstree(tree->right);

    free(tree);
}

/*
 * 打印"二叉树"
 *
 * tree       -- 二叉树的节点
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void print_bstree(BSTree tree, Type key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->key);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->key, key, direction==1?"right" : "left");

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right,tree->key,  1);
    }
}

static int arr[]= {50, 90, 80, 10, 40, 30, 20, 60};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i, ilen;
    BSTree root=NULL;

    printf("== 依次添加: ");
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }

    printf("\n== 前序遍历: ");
    preorder_bstree(root);

    printf("\n== 中序遍历: ");
    inorder_bstree(root);

    printf("\n== 后序遍历: ");
    postorder_bstree(root);
    printf("\n");

    printf("== 最小值: %d\n", bstree_minimum(root)->key);
    printf("== 最大值: %d\n", bstree_maximum(root)->key);
    printf("== 树的详细信息: \n");
    print_bstree(root, root->key, 0);

    printf("\n== 删除根节点: %d", arr[3]);
    root = delete_bstree(root, arr[3]);

    printf("\n== 中序遍历: ");
    inorder_bstree(root);
    printf("\n");

    // 销毁二叉树
    destroy_bstree(root);
}


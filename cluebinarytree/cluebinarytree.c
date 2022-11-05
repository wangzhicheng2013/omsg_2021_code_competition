#include <stdio.h>
#include <stdlib.h>
typedef enum {
    LINK,
    THREAD
} tag_type;
typedef struct clue_bin_tree_node_ {
    int data;
    struct clue_bin_tree_node_ *left;
    struct clue_bin_tree_node_ *right;
    tag_type ltag;
    tag_type rtag;
} clue_bin_tree_node, *CBTree;
CBTree root;
static clue_bin_tree_node *create_node(int data)
{
    clue_bin_tree_node *node = (clue_bin_tree_node *)malloc(sizeof(clue_bin_tree_node));
    if (NULL == node) {
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    node->ltag = node->rtag = LINK;
    return node;
}
static void create_tree(CBTree *root) {
    int data;
    scanf("%d", &data);
    if (data <= 0) {
        return;
    }
    if (NULL == *root) {
        *root = create_node(data);
        if (NULL == *root) {
            return;
        }
    }
    
    create_tree(&((*root)->left));
    create_tree(&((*root)->right));
}
static void create() {
    create_tree(&root);
}
void tranverse_tree(CBTree root)
{
    if (root) {
        printf("%d ", root->data);
        tranverse_tree(root->left);
        tranverse_tree(root->right);
    }
}
void tranverse() {
    tranverse_tree(root);
}
void create_post_clues(CBTree root, clue_bin_tree_node *pre) {
    if (NULL == root) {
        return;
    }
    create_post_clues(root->left, pre);
    if (NULL == root->left) {
        root->ltag = THREAD;
        root->left = pre;
    }
    if ((pre != NULL) && (NULL == pre->right)) {
        pre->rtag = THREAD;
        pre->right = root;
    }
    pre = root;
    create_post_clues(root->right, pre);
}
clue_bin_tree_node *get_node(int e, CBTree root) {
    if (NULL == root) {
        return NULL;
    }
    if (e == root->data) {
        return root;
    }
    if (LINK == root->ltag) {
        get_node(e, root->left);
    }
    if (LINK == root->rtag) {
        get_node(e, root->right);
    }
}
clue_bin_tree_node *get_precusor(int e) {
    clue_bin_tree_node *node = get_node(e, root);
    if (NULL == node) {
        return NULL;
    }
    if (THREAD == node->ltag) {
        return node->left;
    }
    clue_bin_tree_node *tmp = node->left;
    while (tmp != NULL && tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}
int main()
{
     create();
     tranverse();
     clue_bin_tree_node *pre = NULL;
     create_post_clues(root, pre);
     int e = 3;
     clue_bin_tree_node *node = get_precusor(e);
     if (node != NULL) {
        printf("%d precusor is %d\n", e, node->data);
     }

     return 0;
}


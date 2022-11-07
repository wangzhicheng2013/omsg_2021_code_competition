#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 256
typedef struct trie_node_ {
    struct trie_node_ *childs[NUM];
    unsigned char terminated;
} trie_node, *TRIETREE;
TRIETREE tree;
static trie_node *create_node()
{
    trie_node *node = (trie_node *)malloc(sizeof(trie_node));
    if (NULL == node) {
        return NULL;
    }
    memset(node, 0, sizeof(trie_node));
    return node;
}
static void insert_tree(const char *str) {
    int pos = 0;
    trie_node *node = tree;
    for (int i = 0;str[i];i++) {
        int pos = str[i];
        if (NULL == node->childs[pos]) {
            node->childs[pos] = create_node();
        }
        node = node->childs[pos];
    }
    if (node != NULL) {
        node->terminated = 1;
    }
}
static int find(const char *str) {
    int pos = 0;
    trie_node *node = tree;
    for (int i = 0;str[i];i++) {
        int pos = str[i];
        if (NULL == node->childs[pos]) {
            return 0;
        }
        node = node->childs[pos];
    }
    return (node != NULL) && (1 == node->terminated);
}
static void destory(trie_node **tree) {
    if (NULL == *tree) {
        return;
    }
    for (int i = 0;i < NUM;i++) {
        trie_node *node = (*tree)->childs[i];
        if (NULL == node) {
            continue;
        }
        if (1 == node->terminated) {
            free(node);
            node = NULL;
        }
        else {
            destory(&node);
        }
    }
    free(*tree);
    *tree = NULL;
}
int main()
{
    tree = create_node();
    insert_tree("abc 1212@");
    insert_tree("1#445!");
    insert_tree("hello trie!");
    printf("%d\n", find("hello trie!"));
    printf("%d\n", find("hello1213"));
    destory(&tree);

    return 0;
}


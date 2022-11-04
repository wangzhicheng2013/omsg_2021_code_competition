#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
// 设有一个带头结点的循环单链表，其结点值均为正整数。设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点
// 链栈
typedef struct linklist_node_
{
    struct linklist_node_ *next;
    int value;
} linklist_node, *LNODE;
LNODE head;

LNODE create_node(int e) {
    LNODE p = (LNODE)malloc(sizeof(linklist_node));
    if (!p) {
        return NULL;
    }
    p->value = e;
    p->next = p;
    return p;
}
int insert(int e) {
    LNODE p = create_node(e);
    if (NULL == p) {
        return -1;
    }
    if (head->next == head) {
        head->next = p;
        p->next = head;
    }
    else {
        p->next = head->next;
        head->next = p;
    }
    return 0;
}
int erase(int e) {
    if (NULL == head) {
        return 0;
    }
    LNODE p = head->next;
    LNODE prev = NULL;
    while (p != head) {
        if (p->value == e) {
            if (NULL == prev) {
                head->next = p->next;
            }
            else {
                prev->next = p->next;
            }
            free(p);
            return 0;
        }
        prev = p;
        p = p->next;
    }
    return -1;
}
void traverse() {
    if (NULL == head) {
        return;
    }
    for (LNODE p = head->next;p != head;p = p->next) {   
        printf("node:%d\n", p->value);
    }
}
void delete_min_val() {
    while (head->next != head) {
        int min_val = INT_MAX;
        LNODE p = head->next;
        LNODE prev = head;
        LNODE min_node = NULL;
        LNODE min_node_pre = head;
        while (p != head) {
            if (p->value < min_val) {
                min_val = p->value;
                min_node = p;
                min_node_pre = prev;
            }
            prev = p;
            p = p->next;
        }
        if (min_node != NULL) {
            printf("the min:%d will be deleted!\n", min_node->value);
            min_node_pre->next = min_node->next;
            free(min_node);
            printf("the min:%d deleted ok!\n", min_node->value);
        }
    }
    free(head);
    head = NULL;
}
int main()
{
    srand(time(NULL));
    head = create_node(-10000);
    if (NULL == head) {
        return -1;
    }
    for (int i = 0;i < 10;i++) {
        if (0 == insert(rand() % 100)) {
            printf("insert %d success!\n", i);
        }
    }
    traverse();
    delete_min_val();
    traverse();
    return 0;
}
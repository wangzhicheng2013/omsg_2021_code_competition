#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
// 假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
// 给定两个这种链表，请生成代表两个整数相加值的结果链表
typedef struct linklist_node_
{
    struct linklist_node_ *next;
    int value;
} linklist_node, *LNODE;

LNODE create_node(int e) {
    LNODE p = (LNODE)malloc(sizeof(linklist_node));
    if (!p) {
        return NULL;
    }
    p->value = e;
    p->next = NULL;
    return p;
}
int insert(LNODE *head, int e) {
    LNODE p = create_node(e);
    if (NULL == p) {
        return -1;
    }
    if (NULL == *head) {
        *head = p;
    }
    else {
        LNODE r = *head;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = p;
    }
    return 0;
}
void destory(LNODE *head) {
    LNODE p = *head;
    while (p != NULL) {
        LNODE r = p;
        p = p->next;
        free(r);
    }
    *head = NULL;
}
void traverse(LNODE head) {
    for (LNODE p = head;p != NULL;p = p->next) {   
        printf("node:%d\n", p->value);
    }
}
int get_num(LNODE head) {
    int num = 0;
    for (LNODE p = head;p != NULL;p = p->next) {   
        num = num * 10 + p->value;
    }
    return num;
}
LNODE linklist_add(LNODE head1, LNODE head2) {
    int num = get_num(head1) + get_num(head2);
    LNODE tmp = create_node(-1000);
    if (NULL == tmp) {
        return NULL;
    }
    while (num > 0) {
        LNODE p = create_node(num % 10);
        num /= 10;
        p->next = tmp->next;
        tmp->next = p;
    }
    if (NULL == tmp->next) {
        tmp->value = 0;
        return tmp;
    }
    LNODE new_head = tmp->next;
    free(tmp);
    return new_head;
}
int main()
{
    srand(time(NULL));
    LNODE head1 = NULL;
    LNODE head2 = NULL;
    insert(&head1, 9);
    insert(&head1, 3);
    insert(&head1, 7);

    insert(&head2, 6);
    insert(&head2, 3);

    traverse(head1);
    printf("==============================\n");
    traverse(head2);
    LNODE head = linklist_add(head1, head2);
    printf("==============================\n");
    traverse(head);
    destory(&head1);
    destory(&head2);
    destory(&head);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
// 链栈
typedef struct dlinklist_node_
{
    struct dlinklist_node_ *prev;
    struct dlinklist_node_ *next;
    int value;
} dlinklist_node, *DNODE;
DNODE head;
DNODE create_node(int e) {
    DNODE p = (DNODE)malloc(sizeof(dlinklist_node));
    if (!p) {
        return NULL;
    }
    p->value = e;
    p->next = p->prev = p;
    return p;
}
int insert(int e) {
    DNODE p = create_node(e);
    if (NULL == p) {
        return -1;
    }
    if (head->next == head) {
        head->next = p;
        p->prev = head;
    }
    else {
        DNODE rear = head->prev;
        p->prev = rear;
        rear->next = p;
    }
    p->next = head;
    head->prev = p;
    return 0;
}
int erase(int e) {
    DNODE p = head->next;
    while (p != head) {
        if (p->value == e) {
            p->prev->next = p->next;
            if (p->next) {
                p->next->prev = p->prev;
            }
            free(p);
            return 0;
        }
        p = p->next;
    }
    return -1;
}
void traverse() {
    for (DNODE p = head->next;p != head;p = p->next) {   
        printf("node:%d\n", p->value);
    }
}

int main()
{
    head = create_node(-10000);
    if (NULL == head) {
        return -1;
    }
    for (int i = 0;i < 10;i++) {
        if (0 == insert(i)) {
            printf("insert %d success!\n", i);
        }
    }
    traverse();
    for (int i = 0;i < 10;i++) {
        if (0 == erase(i)) {
            printf("remove %d success!\n", i);
        }
    }
    traverse();
    return 0;
}
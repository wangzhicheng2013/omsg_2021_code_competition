#include <stdio.h>
#include <stdlib.h>
// 链栈
typedef struct stack_node_
{
    struct stack_node_ *next;
    int value;
} stack_node, *SNODE;
typedef struct stack_ {
    SNODE top;
    int num;
    int cap;
} stack;
stack g_stack;
void init(int cap) {
    g_stack.num = 0;
    g_stack.cap = cap;
    g_stack.top = NULL;
}
int push(int e) {
    if (g_stack.num >= g_stack.cap) {
        return -1;
    }
    SNODE p = (SNODE)malloc(sizeof(stack_node));
    if (!p) {
        return -2;
    }
    p->value = e;
    p->next = NULL;
    if (NULL != g_stack.top) {
        p->next = g_stack.top;
    }
    g_stack.top = p;
    g_stack.num++;
    return 0;
}
int pop(int *e) {
    if (g_stack.num <= 0) {
        return -1;
    }
    *e = g_stack.top->value;
    SNODE tmp = g_stack.top;
    g_stack.top = g_stack.top->next;
    free(tmp);
    --g_stack.num;
    return 0;
}

int main()
{
    init(10);
    for (int i = 0;i < 10;i++) {
        if (0 == push(i)) {
            printf("push %d success!\n", i);
        }
    }
    int e = 0;
    while (0 == pop(&e)) {
        printf("pop %d success!\n", e);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 8
// 链栈
typedef struct cirular_queue_
{
    int *queue;
    int front;
    int rear;
} cirular_queue;
cirular_queue g_queue;
int init() {
    g_queue.front = g_queue.rear = 0;
    g_queue.queue = (int *)malloc(MAX_SIZE * sizeof(int));
    if (NULL == g_queue.queue) {
        return -1;
    }
    memset(g_queue.queue, 0, MAX_SIZE * sizeof(int));
}
int push(int e) {
    if (g_queue.front == (g_queue.rear + 1) % MAX_SIZE) {
        return -1;
    }
    g_queue.queue[g_queue.rear] = e;
    g_queue.rear = (g_queue.rear + 1) % MAX_SIZE;
    return 0;
}
int pop(int *e) {
    if (g_queue.front == g_queue.rear) {
        return -1;
    }
    *e = g_queue.queue[g_queue.front];
    g_queue.front = (g_queue.front + 1) % MAX_SIZE;
    return 0;
}
int get_front(int *e) {
    if (g_queue.front == g_queue.rear) {
        return -1;
    }
    *e = g_queue.queue[g_queue.front];
    return 0;
}
int get_rear(int *e) {
    if (g_queue.front == g_queue.rear) {
        return -1;
    }
    *e = g_queue.queue[(g_queue.rear - 1 + MAX_SIZE) % MAX_SIZE];
    return 0;
}
int main()
{
    init();
    for (int i = 0;i < MAX_SIZE;i++) {
        if (0 == push(i)) {
            printf("push %d success!\n", i);
        }
    }
    int e = 0;
    if (0 == get_rear(&e)) {
        printf("rear:%d\n", e);
    }
    while (0 == pop(&e)) {
        printf("pop %d success!\n", e);
    }
    return 0;
}
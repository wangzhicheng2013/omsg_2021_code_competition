// 开启三个线程 这三个线程ID分别是A,B,C 每个线程将自己的ID在屏幕上输出10遍 要求显示结果必须是ABCABCABC...
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#define MAX_LOOP 10
#define MAX_THREAD 3
pthread_mutex_t lock;
pthread_cond_t print_ready;

volatile int index = 0;
void *print_id(void *data)
{
    /* TODO: write code as below */
    /* TODO: 开启三个线程 这三个线程ID分别是A,B,C 每个线程将自己的ID在屏幕上输出10遍 要求显示结果必须是ABCABCABC... */
    int id = *((int *)data);
    for (int loop = 0;loop < MAX_LOOP;loop++) {
        pthread_mutex_lock(&lock);
        while (id != index) {
            pthread_cond_wait(&print_ready, &lock);
        }
        printf("%c", id + 'A');
        index = (index + 1) % MAX_THREAD;
        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&print_ready);
    }
    return NULL;
}

int main(void)
{
    int ids[MAX_THREAD] = { 0 };
    pthread_t ths[MAX_THREAD] = { 0 };
    void *retval;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&print_ready, NULL);
    for (int i = 0;i < MAX_THREAD;i++) {
        ids[i] = i;
    }
    for (int i = 0;i < MAX_THREAD;i++) {
        pthread_create(&ths[i], NULL, print_id, &(ids[i]));
    }
    for (int i = 0;i < MAX_THREAD;i++) {
        pthread_join(ths[i], &retval);
    }

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&print_ready);

    return 0;
}
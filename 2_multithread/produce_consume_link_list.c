#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define COUNT 100 

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t msg_is_ready = PTHREAD_COND_INITIALIZER;

typedef struct _msg {
    int num;
    struct _msg *next;
} msg, *PMSG;
PMSG head = NULL;
void *produce(void *data)
{
    /* TODO: write code as below */
    for (int i = 0;i < COUNT;i++) {
        PMSG message = (PMSG)malloc(sizeof(msg));
        if (!message) {
            return NULL;
        }
        message->num = i;
        pthread_mutex_lock(&lock);
        if (NULL == head) {
            head = message;
            head->next = NULL;
        }
        else {
            message->next = head->next;
            head->next = message;
        }
        printf("produce:%d\n", message->num);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&msg_is_ready);
    }
    printf("本次生产结束\n");
    return NULL;
}


void *consume(void *data)
{
    /* TODO: write code as below */
    for (int i = 0;i < COUNT;i++) {
        pthread_mutex_lock(&lock);
        while (NULL == head) {
            pthread_cond_wait(&msg_is_ready, &lock);
        }
        PMSG message = head;
        printf("consume:%d\n", message->num);
        head = head->next;
        free(message);
        pthread_mutex_unlock(&lock);
    }
    printf("本次消费结束\n");
    return NULL;
}

int main(void)
{
    pthread_t th_produce, th_consume;
    void *retval;
    
    pthread_create(&th_produce, NULL, produce, NULL);
    pthread_create(&th_consume, NULL, consume, NULL);

    pthread_join(th_produce, &retval);
    pthread_join(th_consume, &retval);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&msg_is_ready);

    return 0;
}
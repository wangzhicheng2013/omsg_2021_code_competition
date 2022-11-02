#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define COUNT 8   //车子装满货物的数量

static int int_conveying_number = 0;   // 已经传送了多少货物
static int int_loading_number = 0;     // 已经装车了多少货物

pthread_mutex_t lock;
pthread_cond_t can_conveying;  // 货物传送。
pthread_cond_t can_loading;    // 货物装车

void *loading(void *data)
{
    /* TODO: write code as below */
    /* TODO: 货物装车，装车完成后通知传送货物 */
    while (int_loading_number < COUNT) {
        pthread_mutex_lock(&lock);
        while (int_loading_number >= int_conveying_number) {
            pthread_cond_wait(&can_conveying, &lock);
        }
        printf("正在装车第 (%d) 个货物\n", ++int_loading_number);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&can_loading);
        
    }
    printf("本次装车结束\n");
    return NULL;
}


void *conveying(void *data)
{
    /* TODO: write code as below */
    /* TODO: 传送货物，货物传送过来后通知装车 */
    while (int_conveying_number < COUNT) {
        pthread_mutex_lock(&lock);
        while (int_conveying_number > int_loading_number) {
            pthread_cond_wait(&can_loading, &lock);
        }
        printf("正在传送第 (%d) 个货物\n", ++int_conveying_number);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&can_conveying);
    }
    printf("本次传送结束\n");
    return NULL;
}

int main(void)
{
    pthread_t th_conveyor, th_worker;
    void *retval;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&can_conveying, NULL);
    pthread_cond_init(&can_loading, NULL);

    pthread_create(&th_conveyor, NULL, conveying, NULL);
    pthread_create(&th_worker, NULL,loading, NULL);

    /* 等待装车完成，结束*/
    pthread_join(th_conveyor, &retval);
    pthread_join(th_worker, &retval);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&can_conveying);
    pthread_cond_destroy(&can_loading);

    return 0;
}
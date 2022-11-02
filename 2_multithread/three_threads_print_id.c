// 开启三个线程 这三个线程ID分别是A,B,C 每个线程将自己的ID在屏幕上输出10遍 要求显示结果必须是ABCABCABC...
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
void *print_id(void *data)
{
    char id = *((char *)data);
    printf("%c", id);
    return NULL;
}
int main(void)
{
    pthread_t th_A, th_B, th_C;
    void *retval;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    for (int i = 0;i < 10;i++) {
        pthread_create(&th_A, NULL, print_id, &A);
        pthread_join(th_A, &retval);

        pthread_create(&th_B, NULL, print_id, &B);
        pthread_join(th_B, &retval);

        pthread_create(&th_C, NULL, print_id, &C);
        pthread_join(th_C, &retval);
    }

    return 0;
}

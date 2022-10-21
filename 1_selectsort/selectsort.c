#include <stdio.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) (a^=b,b^=a,a^=b)

/*
 * 选择排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void select_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 选择排序 */
     for (int loop = 1;loop < n - 1;loop++) {
          int max = a[0];
          int k = 0;
          for (int i = 1;i <= n - loop;i++) {
               if (a[i] > max) {
                    max = a[i];
                    k = i;
               }
          }
          if (a[k] != a[n - loop]) {
               swap(a[k], a[n - loop]);
          }
     }
}

int main()
{
     int i;
     int a[] = {80,79,99,18,20,39,28,10,59,43,78};
     int ilen = LENGTH(a);

     printf("before sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     select_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");
}

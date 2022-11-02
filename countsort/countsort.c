#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
void find_min_max(int a[], int n, int *min_val, int *max_val) {
     *min_val = *max_val = a[0];
     for (int i = 1;i < n;i++) {
          if (a[i] > *max_val) {
               *max_val = a[i];
          }
          else if (a[i] < *min_val) {
               *min_val = a[i];
          }
     }
}
/*
 * 计数排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void count_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 计数排序  */
     int min_val = 0, max_val = 0;
     find_min_max(a, n, &min_val, &max_val);
     int size = max_val - min_val + 1;
     int bytes = sizeof(int) * size;
     int *tmp = (int *)malloc(bytes);
     if (!tmp) {
          return;
     }
     memset(tmp, 0, bytes);
     int i = 0;
     for (;i < n;i++) {
          ++tmp[a[i] - min_val];
     }
     int val = 0;
     int k = 0;
     for (i = 0;i < size;i++) {
          val = tmp[i];
          for (int j = 0;j < val;j++) {
               a[k++] = i + min_val;
          }
     }

     free(tmp);
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

     count_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}

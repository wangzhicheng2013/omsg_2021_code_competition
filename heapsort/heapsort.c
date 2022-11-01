#include <stdio.h>
#include <stdlib.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
void adjust_heap(int a[], int n, int start) {
     int i = start;
     int tmp = a[i];
     while (i < n) {
          int j = 2 * i + 1;
          if (j >= n) {
               break;
          }
          if (j + 1 < n && a[j] < a[j + 1]) {
               j++;
          }
          if (tmp < a[j]) {
               a[i] = a[j];
               i = j;
          }
          else {
               break;
          }
     }
     if (i < n) {
          a[i] = tmp;
     }
}
/*
 * 堆排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void heap_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 堆排序  */
     for (int start = (n  - 1) / 2;start >= 0;start--) {
          adjust_heap(a, n, start);
     }
     for (int start = 0;start < n - 1;start++) {
          swap(a[n - start - 1], a[0]);
          adjust_heap(a, n - start - 1, 0);
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

     heap_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}

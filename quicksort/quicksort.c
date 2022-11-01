#include <stdio.h>
#include <stdlib.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
// start <= end
int quick_partition(int a[], int start, int end) {
     int i = start, j = end;
     int tmp = a[i];
     while (i < j) {
          while (i < j && a[j] > tmp) {
               j--;
          }
          if (i < j) {
               a[i++] = a[j];
          }
          while (i < j && a[i] < tmp) {
               i++;
          }
          if (i < j) {
               a[j--] = a[i];
          }
     }
     a[i] = tmp;
     return i;
}
void quicksort(int a[], int start, int end) {
     int pos = quick_partition(a, start, end);
     if (pos > 0) {
          quicksort(a, 0, pos - 1);
     }
     if (pos < end) {
          quicksort(a, pos + 1, end);
     }
}
/*
 * 快速排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void quick_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 快速排序  */
     quicksort(a, 0, n - 1);
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

     quick_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}

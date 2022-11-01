#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
void merge(int a[], int low, int mid, int high) {
     int i = low, j = mid + 1;
     int *tmp = (int *)malloc(sizeof(int) * (high - low + 1));
     if (!tmp) {
          return;
     }
     int k = 0;
     while (i <= mid && j <= high) {
          tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
     }
     while (i <= mid) {
          tmp[k++] = a[i++];
     }
     while (j <= high) {
          tmp[k++] = a[j++];
     }
     memcpy(a + low, tmp, k * sizeof(int));
     free(tmp);
}
void mergesort(int a[], int low, int high) {
     if (low < high) {
          int mid = (low + high) / 2;
          mergesort(a, low, mid);
          mergesort(a, mid + 1, high);
          merge(a, low, mid, high);
     }
}
/*
 * 归并排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void merge_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 归并排序  */
     mergesort(a, 0, n - 1);
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

     merge_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}

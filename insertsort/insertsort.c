#include <stdio.h>
#include <stdlib.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
/*
 * 插入排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void insert_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 插入排序  */
     for (int i = 1;i < n;i++) {
          int tmp = a[i];
          int j = i - 1;
          if (a[j] <= tmp) {
               continue;
          }
          while (j >= 0 && a[j] > tmp) {
               a[j + 1] = a[j];
               j--;
          }
          a[j + 1] = tmp;
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

     insert_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}

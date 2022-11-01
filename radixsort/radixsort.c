#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
#define RADIX 10
typedef struct _bucket {
     int nums[128];
     int num;
     int id;
} bucket;
void init_buckets(bucket *buckets) {
     memset(buckets, 0, sizeof(bucket) * RADIX);
     for (int i = 0;i < RADIX;i++) {
          buckets[i].id = i;
     }
}
void push_buckets(bucket *buckets, int id, int val) {
     if (id >= 0 && id < RADIX) {
          buckets[id].nums[buckets[id].num++] = val;
     }
}
void pull_buckets(bucket *buckets, int a[]) {
     int k = 0;
     for (int i = 0;i < RADIX;i++) {
          for (int j = 0;j < buckets[i].num;j++) {
               a[k++] = buckets[i].nums[j];
          }
     }
     init_buckets(buckets);
}
int get_bucket_id(int num, int loop) {
     int id = 0;
     for (int i = 1;i <= loop;i++) {
          if (0 == num) {    
               return 0;
          }
          id = num % 10;
          num /= 10;
          
     }
     return id;
}
int find_max_loops(int a[], int n) {
     int max_loops = 0;
     for (int i = 0;i < n;i++) {
          int loop = 0;
          int tmp = a[i];
          while (tmp > 0) {
               loop++;
               tmp /= 10;
          }
          if (loop > max_loops) {
               max_loops = loop;
          }
     }
     return max_loops;
}    
/*
 * 基数排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void radix_sort(int a[], int n)
{
     /* TODO: write code as below */
     /* TODO: 基数排序  */
     bucket buckets[RADIX];
     init_buckets(buckets);
     int loops = find_max_loops(a, n);
     for (int loop = 1;loop <= loops;loop++) {
          for (int i = 0;i < n;i++) {
               int id = get_bucket_id(a[i], loop);
               push_buckets(buckets, id, a[i]);
          }
          pull_buckets(buckets, a);
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

     radix_sort(a, ilen);

     printf("after  sort:");
     for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
     printf("\n");

     return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b)   (a^=b,b^=a,a^=b)
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @return int整型
 */
int findPeakElement(int *nums, int numsLen) {
     // write code here
     for (int i = 0;i < numsLen;i++) {
          if ((i - 1 >= 0) && (i + 1 < numsLen) && (nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1])) {
               return i;
          }
     }
     return -1;
}

int main()
{
     int i;
     int a[] = {80,79,99,18,20,39,28,10,59,43,78};
     int ilen = LENGTH(a);
     int index = findPeakElement(a, ilen);
     printf("peak index:%d, peak value:%d\n", index, a[index]);

     return 0;
}

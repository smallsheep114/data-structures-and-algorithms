#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1.删除数组中所有的val
//方法一：找到一个val，往前盖
//方法二：时间换取空间
//方法三：双指针法yyds
//要求时间复杂度O(N)  空间复杂度O（1）

//int main()
//{
//	int arr[] = { 1,2,2,3,4,5,0,2,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int src = 0;//src带头走
//	int des = 0;
//	int val = 2;
//	int i = 0;
//	while (src < sz)//while后面别加分号，什么鬼bug
//	{
//		if (arr[src] != val)
//		{
//			arr[des++] = arr[src++];
//		}
//		else
//		{
//			src++;
//		}
//	}
//	printf("%d\n", des);
//	return 0;
//}

//2.合并两个数组,成为一个有序数组
//两个递增的有序数组，arr1（空间足够大）,arr2
//int main()
//{
//	int arr1[7] = { 1,2,4,6 };
//	int arr2[] = { 0,7,8 };
//	int end1 = 3;//记住的是下标
//	int end2 = 2;
//	int end = end1 + end2 + 1;
//	while (end1 >= 0 && end2 >= 0)
//	{
//		if(arr1[end1]>arr2[end2])
//		{
//			arr1[end--] = arr1[end1--];
//		}
//		else
//		{
//			arr1[end--] = arr2[end2--];
//		}
//	}
//	if (end2 >= 0)
//	{
//		arr1[end--] = arr2[end2--];
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
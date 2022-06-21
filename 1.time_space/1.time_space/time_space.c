#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.0-n的所有整数，但其中缺了一个，时间复杂度为O(N)的条件下，找出缺失的数
//1.方法一
// 
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,9 };//这个不是额外的空间
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ret = ret + i - arr[i];
//	}
//	printf("缺失的数为%d\n", ret);
//	return 0;
//}
//时间复杂度:O(n)  空间复杂度O(1)

//方法二--找不同用异或
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,9 };
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ret = ret ^ i ^ arr[i];
//	}
//	printf("缺失的数为%d\n", ret);
//	return 0;
//}
//时间复杂度:O(n)  空间复杂度O(1)

//方法三：较差的方法
//int main()
//{
//	int arr[9] = {0,1,2,3,4,5,6,7,9 };
//	int arr1[10] ;
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		arr1[arr[i]] = arr[i];//下标与数一样的，就填到arr1里面，剩下每天的就是缺失的，下标就是答案
//	}
//	for (i = 0; i < 9; i++)
//	{
//		if (arr1[i] != i)
//		{
//			printf("缺失的数为%d\n", i);
//		}
//	}
//	return 0;
//}

//时间复杂度O（1）--执行次数是不随变量的变化而变化的，是固定的

//并不是一层循环就是O（n），两层循环就是O（n^2），这种想法是错误的

//要从代码实现的思想去计算时间复杂度

//算法的复杂度计算，喜欢省略简写成logN（键盘不好敲）



//旋转数组（空间复杂度O（1））
// 思路一
//1.先将最后一个数拿起来
//2.移动数据
//3.拿起来的数放在第一个去
//旋转3次数组
// 
// 时间复杂度O(N*K)
//跑不过去，效率太低
//void arr_move(int* arr, int num, int k)
//{
//	while (k--)
//	{
//		int x = arr[num - 1];
//		for (int end = num - 2; end >= 0; end--)//使用一个表示end去标记位置
//		{
//			arr[end + 1] = arr[end];
//		}
//		arr[0] = x;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int k = 3;
//	arr_move(arr,num,k);
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//思路二：空间换取时间
//拷贝


//思路三：逆置   (旋转数组，目前最好的方法：逆置)--太秀了
//void Reverse(int* arr, int left, int right)
//{
//
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		--right;
//		++left;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	printf("请输入要旋转多少次数组");
//	scanf("%d", &k);
//	if (k > num)
//		k %= num;//这个太秀了
// 
//	Reverse(arr, num - k, num - 1);
//	Reverse(arr, 0, num - k-1);
//	Reverse(arr, 0, num - 1);
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1.ɾ�����������е�val
//����һ���ҵ�һ��val����ǰ��
//��������ʱ�任ȡ�ռ�
//��������˫ָ�뷨yyds
//Ҫ��ʱ�临�Ӷ�O(N)  �ռ临�Ӷ�O��1��

//int main()
//{
//	int arr[] = { 1,2,2,3,4,5,0,2,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int src = 0;//src��ͷ��
//	int des = 0;
//	int val = 2;
//	int i = 0;
//	while (src < sz)//while�����ӷֺţ�ʲô��bug
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

//2.�ϲ���������,��Ϊһ����������
//�����������������飬arr1���ռ��㹻��,arr2
//int main()
//{
//	int arr1[7] = { 1,2,4,6 };
//	int arr2[] = { 0,7,8 };
//	int end1 = 3;//��ס�����±�
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
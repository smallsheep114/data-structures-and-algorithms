#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.0-n������������������ȱ��һ����ʱ�临�Ӷ�ΪO(N)�������£��ҳ�ȱʧ����
//1.����һ
// 
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,9 };//������Ƕ���Ŀռ�
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ret = ret + i - arr[i];
//	}
//	printf("ȱʧ����Ϊ%d\n", ret);
//	return 0;
//}
//ʱ�临�Ӷ�:O(n)  �ռ临�Ӷ�O(1)

//������--�Ҳ�ͬ�����
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,9 };
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ret = ret ^ i ^ arr[i];
//	}
//	printf("ȱʧ����Ϊ%d\n", ret);
//	return 0;
//}
//ʱ�临�Ӷ�:O(n)  �ռ临�Ӷ�O(1)

//���������ϲ�ķ���
//int main()
//{
//	int arr[9] = {0,1,2,3,4,5,6,7,9 };
//	int arr1[10] ;
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		arr1[arr[i]] = arr[i];//�±�����һ���ģ����arr1���棬ʣ��ÿ��ľ���ȱʧ�ģ��±���Ǵ�
//	}
//	for (i = 0; i < 9; i++)
//	{
//		if (arr1[i] != i)
//		{
//			printf("ȱʧ����Ϊ%d\n", i);
//		}
//	}
//	return 0;
//}

//ʱ�临�Ӷ�O��1��--ִ�д����ǲ�������ı仯���仯�ģ��ǹ̶���

//������һ��ѭ������O��n��������ѭ������O��n^2���������뷨�Ǵ����

//Ҫ�Ӵ���ʵ�ֵ�˼��ȥ����ʱ�临�Ӷ�

//�㷨�ĸ��Ӷȼ��㣬ϲ��ʡ�Լ�д��logN�����̲����ã�



//��ת���飨�ռ临�Ӷ�O��1����
// ˼·һ
//1.�Ƚ����һ����������
//2.�ƶ�����
//3.�������������ڵ�һ��ȥ
//��ת3������
// 
// ʱ�临�Ӷ�O(N*K)
//�ܲ���ȥ��Ч��̫��
//void arr_move(int* arr, int num, int k)
//{
//	while (k--)
//	{
//		int x = arr[num - 1];
//		for (int end = num - 2; end >= 0; end--)//ʹ��һ����ʾendȥ���λ��
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

//˼·�����ռ任ȡʱ��
//����


//˼·��������   (��ת���飬Ŀǰ��õķ���������)--̫����
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
//	printf("������Ҫ��ת���ٴ�����");
//	scanf("%d", &k);
//	if (k > num)
//		k %= num;//���̫����
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
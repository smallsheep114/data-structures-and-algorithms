#define  _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);//��ͨ�������ı����ݣ�����Ҫ�����ַ
	//���뺯��
	SeqListPushFront(&s1, 1);
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 3);
	SeqListPushFront(&s1, 4);
	SeqListPushFront(&s1, 5);
	SeqListPushFront(&s1, 6);
	SeqListPushFront(&s1, 7);
	//ɾ��
	SeqListPopBack(&s1);
	SeqListPopFront(&s1);
	//�������
	SeqListInsert(&s1, 1, 1);
	//���ɾ��
	SeqListErase(&s1, 3);

	SeqListPrint(&s1);
	//�ͷſռ�
	printf("\n%d\n",SeqListSearch(&s1, 2));

	SeqListModify(&s1, 2);
	SeqListPrint(&s1);

	SeqListDistory(&s1);
}

void menu()
{
	printf("**********************************\n");
	printf("1.β������			2.β��ɾ��\n");
	printf("3.ͷ������			4.ͷ��ɾ��\n");
	printf("5.�������			6.����洦\n");
	printf("7.��ӡ				-1.�˳�\n");
	printf("**********************************\n");
	printf("��ѡ����Ҫʵ�ֵĹ���\n");
}

int main()
{
	//TestSeqList1();
	SL s1;
	SeqListInit(&s1);
	int x = 0,num = 0;
	while (x != -1)
	{
		menu();
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			F_add(&s1, num, SeqListPushBack);
			break;
		case 2:
			F_pop(&s1, num, SeqListPopBack);
			break;
		case 3:
			F_add(&s1, num, SeqListPushFront);
			break;
		case 4:
			F_pop(&s1, num, SeqListPopFront);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			SeqListPrint(&s1);
			break;
		case -1:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}


	SeqListDistory(&s1);
	return 0;
}

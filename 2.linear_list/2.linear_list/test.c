#define  _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);//想通过函数改变内容，我们要传入地址
	//插入函数
	SeqListPushFront(&s1, 1);
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 3);
	SeqListPushFront(&s1, 4);
	SeqListPushFront(&s1, 5);
	SeqListPushFront(&s1, 6);
	SeqListPushFront(&s1, 7);
	//删除
	SeqListPopBack(&s1);
	SeqListPopFront(&s1);
	//随机插入
	SeqListInsert(&s1, 1, 1);
	//随机删除
	SeqListErase(&s1, 3);

	SeqListPrint(&s1);
	//释放空间
	printf("\n%d\n",SeqListSearch(&s1, 2));

	SeqListModify(&s1, 2);
	SeqListPrint(&s1);

	SeqListDistory(&s1);
}

void menu()
{
	printf("**********************************\n");
	printf("1.尾部插入			2.尾部删除\n");
	printf("3.头部插入			4.头部删除\n");
	printf("5.随机插入			6.随机随处\n");
	printf("7.打印				-1.退出\n");
	printf("**********************************\n");
	printf("请选择你要实现的功能\n");
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
			printf("输入错误，请重新输入\n");
			break;
		}
	}


	SeqListDistory(&s1);
	return 0;
}

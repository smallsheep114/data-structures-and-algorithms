#define  _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//������˫������

//plist/phead--ͷָ��
void TestSList1()
{
	SLTNode* plist = NULL;
	SListpushBack(&plist, 1);//���ͷָ��Ϊ�գ���ô����Ҫ�޸�ͷָ�룬Ҫ�޸ĵĻ������Ǿ�Ҫ��ͷָ��ĵ�ַ
	SListpushBack(&plist, 2);
	SListpushBack(&plist, 3);
	SListpushBack(&plist, 4);
	SListpushBack(&plist, 5);

	SListpushFront(&plist, 6);

	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListpushFront(&plist, 1);
	SListpushFront(&plist, 2);
	SListpushFront(&plist, 3);
	SListpushFront(&plist, 4);
	SListpushFront(&plist, 5);

	SListPrint(plist);
	//SListDistory(plist);
}

void TestSList3()
{
	SLTNode* plist = NULL;
	SListpushFront(&plist, 1);
	SListpushFront(&plist, 2);
	SListpushFront(&plist, 3);
	SListpushFront(&plist, 4);
	SListpushFront(&plist, 5);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	//SListDistory(plist);
}

void TestSList4()
{
	SLTNode* plist = NULL;
	SListpushFront(&plist, 1);
	SListpushFront(&plist, 2);
	SListpushFront(&plist, 3);
	SListpushFront(&plist, 4);
	SListpushFront(&plist, 5);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);
}

void TestSList5()
{
	SLTNode* plist = NULL;
	SListpushFront(&plist, 1);
	SListpushFront(&plist, 2);
	SListpushFront(&plist, 3);
	SListpushFront(&plist, 4);
	SListpushFront(&plist, 5);//����

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SListInsert(&plist, pos, 30);
	SListPrint(plist);//��3��ǰ�����30

	pos = SListFind(plist, 5);//��5��ǰ�����6
	SListInsert(&plist, pos, 6);

	SListPrint(plist);

	pos = SListFind(plist, 5);
	SListErase(&plist, pos);//��5ɾ��

	pos = SListFind(plist, 6);
	SListErase(&plist, pos);//��6ɾ��

	SListPrint(plist);
}

int main()
{
	//TestSList1();
	//TestSList2();
	/*TestSList3();*/
	//TestSList4();
	TestSList5();
}
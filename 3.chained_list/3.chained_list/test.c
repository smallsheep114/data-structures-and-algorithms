#define  _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//单链表，双向链表

//plist/phead--头指针
void TestSList1()
{
	SLTNode* plist = NULL;
	SListpushBack(&plist, 1);//如果头指针为空，那么我们要修改头指针，要修改的话，我们就要传头指针的地址
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
	SListpushFront(&plist, 5);//插入

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SListInsert(&plist, pos, 30);
	SListPrint(plist);//在3的前面插入30

	pos = SListFind(plist, 5);//在5的前面插入6
	SListInsert(&plist, pos, 6);

	SListPrint(plist);

	pos = SListFind(plist, 5);
	SListErase(&plist, pos);//将5删除

	pos = SListFind(plist, 6);
	SListErase(&plist, pos);//将6删除

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
#define  _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//1.
void SListPrint(SLTNode* phead)//打印链表
{
	SLTNode* cur = phead;//头指针是不动的，cur是动态的
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//2.


//3.
SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

//4.
//尾节点的下一个指针为空，而不是自身为空
SLTNode* SListSearchTail(SLTNode* phead)//找尾结点函数，返回尾结点的地址
{
	SLTNode* tail = phead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	return tail;

}

void SListpushBack(SLTNode** pphead, SLTDataType x)//尾插
{
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
	//找尾结点
	SLTNode* tail = SListSearchTail(*pphead);
	//接收新的尾结点
	tail->next = newnode;
	}
}

//5.
void SListpushFront(SLTNode** phead, SLTDataType x)//头部插入，会涉及到头指针的变动
{
	SLTNode* newnode = BuyListNode(x);
	//发现特殊情况和一般情况的写法是一样的,尾插不一样
	/*if (*phead == NULL)
	{
		*phead = newnode;
	}
	else*/
	{
		newnode->next = *phead;
		*phead = newnode;
	}
}

void SListPopFront(SLTNode** pphead)//头删,会涉及到头指针的变动
{
	if (*pphead != NULL)
	{
		SLTNode* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
	else
	{
		printf("数据已经全部删除\n");
	}
}

//void SListPopBack(SLTNode** pphead)//尾删，会涉及头指针的变动
//{//1.找尾结点的前一个节点,将它的next变为null
//	SLTNode* tail_front = *pphead;
//	if (tail_front == NULL)//一个数据都没有的时候
//	{
//		printf("数据已经全部清除\n");
//	}
//	else if (tail_front->next == NULL)//只有一个数据的时候,这个时候头指针就要被修改了
//	{
//		free(*pphead);
//		tail_front = NULL;
//		*pphead = NULL;
//	}
//	else//有多个数据的时候
//	{
//		while (tail_front->next->next != NULL)
//		{
//			tail_front = tail_front->next;
//		}
//		tail_front->next = NULL;
//		//2.释放尾结点的空间
//		free(tail_front->next);
//	}
//}

//尾删--老师的写法--小跟班指针(用来找导数第二个节点)
//6.
void SListPopBack(SLTNode** pphead)//尾删，会涉及头指针的变动
{
	//三种情况
	//0个节点
	//1个节点
	//2个及以上的节点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)//找到x的节点地址
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//中间插，将x放在pos节点的位置
{//特殊情况起始更简单，pos就是phead的位置
	SLTNode* newnode = BuyListNode(x);
	if (pos == *pphead)
	{
		SListpushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos)//中间删
{//特殊情况：头删情况,找不到前一个,
	//处理头删情况的时候，也解决了只有一个节点
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		//free(pos);
	}
}
#define  _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//1.
void SListPrint(SLTNode* phead)//��ӡ����
{
	SLTNode* cur = phead;//ͷָ���ǲ����ģ�cur�Ƕ�̬��
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
//β�ڵ����һ��ָ��Ϊ�գ�����������Ϊ��
SLTNode* SListSearchTail(SLTNode* phead)//��β��㺯��������β���ĵ�ַ
{
	SLTNode* tail = phead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	return tail;

}

void SListpushBack(SLTNode** pphead, SLTDataType x)//β��
{
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
	//��β���
	SLTNode* tail = SListSearchTail(*pphead);
	//�����µ�β���
	tail->next = newnode;
	}
}

//5.
void SListpushFront(SLTNode** phead, SLTDataType x)//ͷ�����룬���漰��ͷָ��ı䶯
{
	SLTNode* newnode = BuyListNode(x);
	//�������������һ�������д����һ����,β�岻һ��
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

void SListPopFront(SLTNode** pphead)//ͷɾ,���漰��ͷָ��ı䶯
{
	if (*pphead != NULL)
	{
		SLTNode* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
	else
	{
		printf("�����Ѿ�ȫ��ɾ��\n");
	}
}

//void SListPopBack(SLTNode** pphead)//βɾ�����漰ͷָ��ı䶯
//{//1.��β����ǰһ���ڵ�,������next��Ϊnull
//	SLTNode* tail_front = *pphead;
//	if (tail_front == NULL)//һ�����ݶ�û�е�ʱ��
//	{
//		printf("�����Ѿ�ȫ�����\n");
//	}
//	else if (tail_front->next == NULL)//ֻ��һ�����ݵ�ʱ��,���ʱ��ͷָ���Ҫ���޸���
//	{
//		free(*pphead);
//		tail_front = NULL;
//		*pphead = NULL;
//	}
//	else//�ж�����ݵ�ʱ��
//	{
//		while (tail_front->next->next != NULL)
//		{
//			tail_front = tail_front->next;
//		}
//		tail_front->next = NULL;
//		//2.�ͷ�β���Ŀռ�
//		free(tail_front->next);
//	}
//}

//βɾ--��ʦ��д��--С����ָ��(�����ҵ����ڶ����ڵ�)
//6.
void SListPopBack(SLTNode** pphead)//βɾ�����漰ͷָ��ı䶯
{
	//�������
	//0���ڵ�
	//1���ڵ�
	//2�������ϵĽڵ�
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

SLTNode* SListFind(SLTNode* phead, SLTDataType x)//�ҵ�x�Ľڵ��ַ
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

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//�м�壬��x����pos�ڵ��λ��
{//���������ʼ���򵥣�pos����phead��λ��
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

void SListErase(SLTNode** pphead, SLTNode* pos)//�м�ɾ
{//���������ͷɾ���,�Ҳ���ǰһ��,
	//����ͷɾ�����ʱ��Ҳ�����ֻ��һ���ڵ�
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
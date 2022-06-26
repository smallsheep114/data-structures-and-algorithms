#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;

struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//存下一个节点得地址
};

typedef struct SListNode SLTNode;

void SListPrint(SLTNode* phead);//打印链表
void SListDistory(SLTNode* phead);//释放空间

void SListpushBack(SLTNode** pphead, SLTDataType x);//尾部插入,会涉及到头指针的变动
void SListpushFront(SLTNode** phead, SLTDataType x);//头部插入，会涉及到头指针的变动

void SListPopFront(SLTNode** phead);//头删,会涉及到头指针的变动
void SListPopBack(SLTNode** phead);//尾删，会涉及头指针的变动

SLTNode* SListFind(SLTNode* phead, SLTDataType x);//找到x的节点地址
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//中间插，将x放在pos节点的位置,将x放在pos节点的前面
void SListErase(SLTNode** pphead, SLTNode* pos);//中间删
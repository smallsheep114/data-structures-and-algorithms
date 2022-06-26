#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;

struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//����һ���ڵ�õ�ַ
};

typedef struct SListNode SLTNode;

void SListPrint(SLTNode* phead);//��ӡ����
void SListDistory(SLTNode* phead);//�ͷſռ�

void SListpushBack(SLTNode** pphead, SLTDataType x);//β������,���漰��ͷָ��ı䶯
void SListpushFront(SLTNode** phead, SLTDataType x);//ͷ�����룬���漰��ͷָ��ı䶯

void SListPopFront(SLTNode** phead);//ͷɾ,���漰��ͷָ��ı䶯
void SListPopBack(SLTNode** phead);//βɾ�����漰ͷָ��ı䶯

SLTNode* SListFind(SLTNode* phead, SLTDataType x);//�ҵ�x�Ľڵ��ַ
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//�м�壬��x����pos�ڵ��λ��,��x����pos�ڵ��ǰ��
void SListErase(SLTNode** pphead, SLTNode* pos);//�м�ɾ
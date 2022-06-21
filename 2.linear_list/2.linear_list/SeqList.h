#define  _CRT_SECURE_NO_WARNINGS 1
//#pragma once
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//#define MAX_SIZE 100
#define SIZE_CAPACITY 4//д���ʱ��Ҫ�ӷֺţ����׳�bug
typedef int SQDataType;//���������͸��������ڸ��õ��޸�

//�򻯽ṹ�������
//��̬˳������⣺�����˲����ã��������ò���
//typedef struct SeqList
//{
//	SQDataType a[MAX_SIZE];
//	int size;//��Ч���ݵĸ���
//}SL;

//��̬˳���
typedef struct SeqList
{
	SQDataType* a;
	int size;//��Ч���ݵĸ���
	int capacity;//��¼����
}SL;

//�Ժ���������
//��ɾ��ĵȽӿں���
void SeqListInit(SL* s1);//��ʼ��˳���

void SeqListPushBack(SL* ps, SQDataType x);//��β������,x��Ҫ�Ž�ȥ������
void SeqListPushFront(SL* ps, SQDataType x);//��ͷ������

void SeqListPrint(SL* ps);//��ӡ����

void SeqListPopBack(SL* ps);//ͷɾ
void SeqListPopFront(SL* ps);//βɾ

void SeqListInsert(SL* ps, int pos, SQDataType x);//�������
void SeqListErase(SL* ps, int pos);//���ɾ��

void SeqListDistory(SL* ps);//�ͷſռ䣬��Ȼ���ܻ�����ڴ�й¶

int SeqListSearch(SL* ps, SQDataType x);//�������ݣ��ҵ��˷����±꣬�Ҳ�������0

void SeqListModify(SL* ps, SQDataType x);//�޸�����

void F_add(SL* ps, SQDataType x, void(*p)(SL* ps, SQDataType x));//����ͨ�ú�����ͷβ��

void F_pop(SL* ps, SQDataType x, void(*p)(SL* ps));//ɾ��ͨ�ú�����ͷβ��
#endif
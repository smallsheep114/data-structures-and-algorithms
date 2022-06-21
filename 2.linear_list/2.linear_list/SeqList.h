#define  _CRT_SECURE_NO_WARNINGS 1
//#pragma once
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//#define MAX_SIZE 100
#define SIZE_CAPACITY 4//写宏的时候不要加分号，容易出bug
typedef int SQDataType;//将数据类型改名，便于更好地修改

//简化结构体的名字
//静态顺序表问题：给少了不够用，过多了用不了
//typedef struct SeqList
//{
//	SQDataType a[MAX_SIZE];
//	int size;//有效数据的个数
//}SL;

//动态顺序表
typedef struct SeqList
{
	SQDataType* a;
	int size;//有效数据的个数
	int capacity;//记录容量
}SL;

//对函数的声明
//增删查改等接口函数
void SeqListInit(SL* s1);//初始化顺序表

void SeqListPushBack(SL* ps, SQDataType x);//从尾部插入,x是要放进去的数据
void SeqListPushFront(SL* ps, SQDataType x);//从头部插入

void SeqListPrint(SL* ps);//打印数据

void SeqListPopBack(SL* ps);//头删
void SeqListPopFront(SL* ps);//尾删

void SeqListInsert(SL* ps, int pos, SQDataType x);//随机插入
void SeqListErase(SL* ps, int pos);//随机删除

void SeqListDistory(SL* ps);//释放空间，不然可能会造成内存泄露

int SeqListSearch(SL* ps, SQDataType x);//查找数据，找到了返回下标，找不到返回0

void SeqListModify(SL* ps, SQDataType x);//修改数据

void F_add(SL* ps, SQDataType x, void(*p)(SL* ps, SQDataType x));//插入通用函数（头尾）

void F_pop(SL* ps, SQDataType x, void(*p)(SL* ps));//删除通用函数（头尾）
#endif
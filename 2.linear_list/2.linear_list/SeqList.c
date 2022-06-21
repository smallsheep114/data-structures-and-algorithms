#define  _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
//�������룬ͷ�壬β�壬�����--��
// ����ɾ����ͷɾ��βɾ�����ɾ--ɾ
// ��ӡ�����뺯��
// ������⺯��������ʱҪʹ�ã�
// ͷ�������Ҫ�����ƶ�������--�Ӻ�ǰ��������ƶ�
// ɾ������ǰ����ʼ��ǰ����
//1.
void SeqListInit(SL* s1)
{
	//memset(s1->a, 0, sizeof(SQDataType) * MAX_SIZE);
	s1->a = (SQDataType*)malloc(sizeof(SQDataType) * SIZE_CAPACITY);
	s1->size = 0;
	s1->capacity = SIZE_CAPACITY;//�����Խ������ĳ�ʼֵ��Ϊ0
}

//2.
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SQDataType* tmp = (SQDataType*)realloc(ps->a, (ps->capacity) * 2 * sizeof(SQDataType*));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//�˳������������˼
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
}

void SeqListPushBack(SL* ps, SQDataType x)//��β������
{
	/*if (ps->size >= MAX_SIZE)
	{
		printf("SeqLis is Full\n");
	}*/
	//��������
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//3.
void SeqListPushFront(SL* ps, SQDataType x)//��ͷ������
{//�Ӻ�ʼ�ƶ�
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//4.
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//5.
void SeqListPopBack(SL* ps)//βɾ
{
	assert(ps->size > 0);
	ps->size--;//βɾ����size--���ɣ������Ļ�ά���������ܼ�
}

//6.
void SeqListPopFront(SL* ps)//ͷɾ
{//��ǰ��ʼ�ƶ�
	int start = 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;//ѭ�����̵ĵ������������ǵ�
	}
	ps->size--;
}

//7.
void SeqListInsert(SL* ps, int pos, SQDataType x)//�������   ���±�Ϊpos�ĵط���������
{
	SeqListCheckCapacity(ps);
	assert(pos < ps->size);
	int end = ps->size-1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//8.
void SeqListErase(SL* ps, int pos)//���ɾ��
{
	assert(pos < ps->size);
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	--ps->size;//ǰ�ñȺ��õ�Ч�ʸ�һ�������������Ժ���
}

//9.
void SeqListDistory(SL* ps)
{
	free(ps->a);
	ps->size = 0;
	ps->capacity = 0;
}


//10.
int SeqListSearch(SL* ps, SQDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

//11.
void SeqListModify(SL* ps, SQDataType x)
{
	
	int num = 0;
	printf("��Ҫ��%d�޸ĳ�?\n", x);
	scanf("%d", &num);
	int ret = SeqListSearch(ps, x);
	if (ret != -1)
		ps->a[ret] = num;
	else
		printf("���ݲ�����");
}

//12.
void F_add(SL* ps, SQDataType x, void(*p)(SL* ps, SQDataType x))
{
	printf("��������Ҫ���������,��-1Ϊ������־\n");
	do
	{
		scanf("%d", &x);
		if (x != -1)
			(*p)(ps, x);
	} while (x != -1);
}

//13.
void F_pop(SL* ps, SQDataType x, void(*p)(SL* ps))//ɾ��ͨ�ú�����ͷβ��
{
	printf("������Ҫִ�иò����Ĵ���\n");
	scanf("%d", &x);
	while (x--)
	{
		(*p)(ps);
	}
}
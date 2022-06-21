#define  _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
//三个插入，头插，尾插，随机插--增
// 三个删除，头删，尾删，随机删--删
// 打印数据与函数
// 容量检测函数（插入时要使用）
// 头，随机都要进行移动，插入--从后到前考试向后移动
// 删除，从前到后开始向前覆盖
//1.
void SeqListInit(SL* s1)
{
	//memset(s1->a, 0, sizeof(SQDataType) * MAX_SIZE);
	s1->a = (SQDataType*)malloc(sizeof(SQDataType) * SIZE_CAPACITY);
	s1->size = 0;
	s1->capacity = SIZE_CAPACITY;//不可以将容量的初始值设为0
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
			exit(-1);//退出整个程序的意思
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
}

void SeqListPushBack(SL* ps, SQDataType x)//从尾部插入
{
	/*if (ps->size >= MAX_SIZE)
	{
		printf("SeqLis is Full\n");
	}*/
	//扩容两倍
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//3.
void SeqListPushFront(SL* ps, SQDataType x)//从头部插入
{//从后开始移动
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
void SeqListPopBack(SL* ps)//尾删
{
	assert(ps->size > 0);
	ps->size--;//尾删就让size--即可，这样的话维护起来还能简单
}

//6.
void SeqListPopFront(SL* ps)//头删
{//从前开始移动
	int start = 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;//循环过程的迭代条件别老是掉
	}
	ps->size--;
}

//7.
void SeqListInsert(SL* ps, int pos, SQDataType x)//随机插入   从下标为pos的地方插入数据
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
void SeqListErase(SL* ps, int pos)//随机删除
{
	assert(pos < ps->size);
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	--ps->size;//前置比后置的效率高一丢丢，不过可以忽略
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
	printf("你要将%d修改成?\n", x);
	scanf("%d", &num);
	int ret = SeqListSearch(ps, x);
	if (ret != -1)
		ps->a[ret] = num;
	else
		printf("数据不存在");
}

//12.
void F_add(SL* ps, SQDataType x, void(*p)(SL* ps, SQDataType x))
{
	printf("请输入你要插入的数据,以-1为结束标志\n");
	do
	{
		scanf("%d", &x);
		if (x != -1)
			(*p)(ps, x);
	} while (x != -1);
}

//13.
void F_pop(SL* ps, SQDataType x, void(*p)(SL* ps))//删除通用函数（头尾）
{
	printf("请输入要执行该操作的次数\n");
	scanf("%d", &x);
	while (x--)
	{
		(*p)(ps);
	}
}
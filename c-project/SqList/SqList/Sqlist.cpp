#include <stdio.h>
#include<stdlib.h>

#define maxsize 10
typedef struct
{
	int data[maxsize];
	int length;
}SqList;

void InitList(SqList &L)
{
	L.length = 0;
}

void insertList(SqList &L, int length)
{
	int i = 0;
	for (i; i < maxsize; i++)
	{
		L.data[i] = i;
		length++;
	}
}
int main()
{
	int i = 0;
	SqList L;
	InitList(L);
	insertList(L, L.length);
	for (i; i < maxsize; i++)
	{
		printf("%d", L.data[i]);
	}
	return 0;
}
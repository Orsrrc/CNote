#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 //�趨Ĭ�ϵ���󳤶�
typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList &L) {
	L.data = (int *)malloc(InitSize * sizeof(int)); //malloc �������ڴ��᷵���ڴ���׵�ַ
	L.length = 0;
	L.MaxSize = InitSize;
}

void insertList(SeqList &L)
{
	for (int i = 0; i < 10; i++)
	{
		L.data[i] = i;
	}
}


void InreaseSize(SeqList &L, int len)
{
	int *p = L.data;
}

int main() {
	SeqList L;
	InitList(L);
	insertList(L);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", L.data[i]);
	}
	return 0;
}
/*��Ŀ����ҵ���ŵĽ������������ɡ�����(I)���ڻ����10��Ԫʱ���������10%���������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣��ɿ����7.5%��20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��40��60��֮��ʱ����40��Ԫ�Ĳ��֣�
�����3%��60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%��
����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɣ�
�Ӽ������뵱������I����Ӧ���Ž���������*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int	Init_Overincome(int overincome);
	int Return_Money(int overincome, int Get_Money); 
	void Print_Money(int Get_Money);
	
	int overincome = 0;
	int Get_Money = 0;
	overincome = Init_Overincome(overincome);
	Get_Money = Return_Money(overincome, Get_Money);
	Print_Money(Get_Money);
	return 0;
} 

int Init_Overincome(int overincome)
{
	printf("�����뱾������(��λ����):");
	scanf("%d", &overincome);
	return overincome;
}

int Return_Money(int overincome, int Get_Money)
{
	if(overincome <= 10)
	{
		Get_Money = overincome * 0.1;
	}
	else if(overincome >= 10 && overincome <= 20)
	{
		Get_Money = 10 * 0.1 + (overincome - 10) * 0.075;
	}
	else if(overincome >= 20 && overincome <= 40)
	{
		Get_Money = 10 * 0.1 + 10 * 0.075 + (overincome - 20) * 0.05;
	}
	else if(overincome >= 40 && overincome <= 60)
	{
		Get_Money = 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + (overincome - 40) * 0.03;
	}
	else if(overincome >= 60 && overincome <= 100)
	{
		Get_Money = 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + 20 * 0.03 + (overincome - 60) * 0.015;
	}
	else
	{
		Get_Money = 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + 20 * 0.03 + 20 * 0.015 + (overincome - 100) * 0.01;
	}
	return Get_Money;
}

void Print_Money(int Get_Money)
{
	printf("���»�õĽ���Ϊ(��λ����Ԫ):%d", Get_Money);
	return 0;
}
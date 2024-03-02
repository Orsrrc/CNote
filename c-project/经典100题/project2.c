/*题目：企业发放的奖金根据利润提成。利润(I)低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可可提成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；40万到60万之间时高于40万元的部分，
可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%，
高于100万元时，超过100万元的部分按1%提成，
从键盘输入当月利润I，求应发放奖金总数？*/

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
	printf("请输入本月利润(单位：万):");
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
	printf("本月获得的奖金为(单位：万元):%d", Get_Money);
	return 0;
}
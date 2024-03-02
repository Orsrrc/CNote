/*题目：输入三个整数x,y,z，请把这三个数由小到大输出。*/ 

#include <stdio.h>
#include <stdlib.h>

void main(){
	int init_x(int x);
	int init_y(int y);
	int init_z(int z);
	int Func_Compare(int x, int y, int z);
	
	
	int x, y, z;
	x = init_x(x);
	y = init_y(y);
	z = init_z(z);
	
	Func_Compare(x, y, z);
	system("pause");
	return 0;
}

int init_x(int x)
{
	printf("请输入x的值：");
	scanf("%d", &x);
	return x;
}

int init_y(int y)
{
	printf("请输入y的值：");
	scanf("%d", &y);
	return y;
}

int init_z(int z)
{
	printf("请输入z的值：");
	scanf("%d", &z);
	return z;
}

int Func_Compare(int x, int y, int z)
{
	int temp;
	if(x > y)
	{
		temp = x ;
		x = y;
		y = temp;
	}
	if(x > z)
	{
		temp = x;
		x = z;
		z = temp;
	}
	if(y > z)
	{
		temp = y;
		y = z;
		z = temp; 
	}
	printf("从小到大排列表示为：%d %d %d", x,y,z);
}
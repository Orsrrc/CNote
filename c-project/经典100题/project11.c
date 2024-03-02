/*古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，
小兔子长到第三个月后每个月又生一对兔子，
假如兔子都不死，问每个月的兔子总数为多少？*/

//发现如下规律 
/* 1  1  2  3  5  8  13 21 35 */
/*f1 f2 f3 f4 f5 f6 f7 */
/* f3 = f1 + f2*/
/* f4 = f3(f1 + f2) + f2 = f1 + f2 + f2*/
/* f5 = f4 + f3*/
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int f1 = 1;
	int f2 = 1;
	int month;
	for(month = 1; month < 13; month++)
	{
		printf("%d %d", f1,f2); //打印每个月的兔子数量 数量递增
		printf(" ");
		if(month %2 == 0)
		{
			printf("\n"); //控制输出 每行四个 
		} 
		f1 = f1 + f2; //前两个月加起来的值赋值给第三个月 
		f2 = f1 + f2; //前两个月加起来的值赋值给第三个月 
	}
} 
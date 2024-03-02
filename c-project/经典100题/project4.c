/*输入某年某月某日，判断这一天是这一年的第几天？*/

#include <stdio.h>
#include <stdlib.h>

void main()
{

	 int Init_Day(int year, int month, int day);
	 int Judge_Day(int year, int month,int day);
	 void Print_Day(int sum);
	 int year = 0;
	 int month = 0;
	 int day = 0;
	 int sum = 0;
	 
	 sum = Init_Day(year, month, day);
	 Print_Day(sum);
	 return 0;
	
}


int Init_Day(int year, int month, int day)
{
	int sum = 0;
	printf("请输入日期（格式：年.月.日）："); 
	scanf("%d.%d.%d", &year,&month,&day);
	sum = Judge_Day(year,month,day);
	return sum;
}

int Judge_Day(int year, int month, int day)
{
	int sum = 0; //计算天数 
	switch(month)
	{
		case 1:
			sum = 0;
			break;
		case 2:
			sum = 31;
			break;
		case 3:
			sum = 59;
			break;
		case 4:
			sum = 90;
			break;
		case 5:
			sum = 120;
			break;
		case 6:
			sum = 151;
			break;
		case 7:
			sum = 181;
			break;
		case 8:
			sum = 212;
			break;
		case 9:
			sum = 243;
			break;
		case 10:
			sum = 273;
			break;
		case 11:
			sum = 304;
			break;
		case 12:
			sum = 334;
			break;
		default:
			printf("data error, please try again!\n");
		 	Judge_Day(year,month,day);
		 	break;
	}
	sum += day;
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) /*判断是否为闰年*/
	{
		if(month > 2)
		{
			sum++;
		}
	}
	return sum;
}

void Print_Day(int sum)
{
	printf("这一天是本年的第%d天\n", sum);
	return 0;
}
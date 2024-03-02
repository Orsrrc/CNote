#include <stdio.h>
#include <stdlib.h>

void main()
{
	int Judge_Func(int Unknow_Num);
	void Print_Num(int Unknow_Num);
	
	int Unknow_Num = 0;
	Unknow_Num = Judge_Func(Unknow_Num);
	Print_Num(Unknow_Num);
}


int Judge_Func(int Unknow_Num)
{
	for(Unknow_Num; Unknow_Num < 10000; Unknow_Num++)
	{
		int Judge_Num;
		Judge_Num = sqrt(Unknow_Num + 100);
		if(Judge_Num * Judge_Num == Unknow_Num + 100)
		{
			Judge_Num = sqrt(Unknow_Num + 100 + 168);
			if(Judge_Num * Judge_Num == Unknow_Num + 100 + 168)
			{
				return Unknow_Num;
			}
		}
	}	
} 

void Print_Num(int Unknow_Num)
{
	printf("¸ÃÊýÎª%d", Unknow_Num);
	return 0;
}
 
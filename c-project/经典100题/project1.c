#include<stdlib.h>
#include<stdio.h>


//有1、2、3、4，四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少
void main()
{
	int bai,shi,ge,sum = 0;
	for(bai = 1; bai < 5; bai++)
	{
		for(shi = 1; shi < 5; shi++)
		{
			for(ge = 1; ge < 5; ge++)
			{
				if(bai != shi && shi != ge && bai != ge)
				{
					
					sum++;
					printf("%d%d%d",bai,shi,ge);
					printf("\n");
					
				}
			
			}
			
		}
	}
	printf("总共能够组成%d个数字",sum);
	system("pause");
	
}
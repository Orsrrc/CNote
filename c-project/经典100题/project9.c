#include<stdio.h>
#include<stdlib.h>

void main()
{
	void Print_Chess();
	Print_Chess();
} 

void Print_Chess()
{
	int i = 0;
	int j = 0;
	for(i; i < 8; i++)
	{
		for(j; j < 8; j++)
		{
			if((i + j) % 2 == 0)
				{
					printf("%c%c", 219, 219);
				}
				else
				{
					printf(" ");
				}
		}
		printf("\n");
	}
	return 0;
}
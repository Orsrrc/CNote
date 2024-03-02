#include <stdio.h>
#include <stdlib.h>

void main()
{
	void Print_list();
	Print_list(); 
}

void Print_list()
{
	int i = 1;
	int j = 1;
	for(i; i < 10; i++)
	{
		for(j; j < 10; j++)
		{
			printf("%d * %d = %d ", i, j, i * j);
		}
		j = 1;
		printf("\n");
	}
	return 0;
}
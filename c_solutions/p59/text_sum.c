#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fin = NULL;

	fin = fopen("translated.txt", "r");

	if(fin == NULL)
	{
		printf("failed to open file\n");
		return -1;
	}

	long long sum = 0;

	char c;
	do{
		c = fgetc(fin);

		sum += c;

	}while(c != EOF);

	printf("sum is: %ld \n", sum);

	return 0;
}


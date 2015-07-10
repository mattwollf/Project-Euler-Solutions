#include "penta.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEFAULT_PENTAS_GENERATED 10000000

int *pentas;
size_t num_pentas;

int is_penta(int n)
{
	int i = 0;

	while(i != num_pentas && pentas[i] < n)
	{
		i++;
	}
	
	return pentas[i] == n;
}

int compare_pentas(int j, int k)
{
	int penta1 = pentas[j];
	int penta2 = pentas[k];

	if(!is_penta(penta2 - penta1))
	{
		return 0;
	}

	if(!is_penta(penta2 + penta1))
	{
		return 0;
	}

	return 1;	
}

int main(int argc, char *argv[])
{
	int i = 0;

	num_pentas = DEFAULT_PENTAS_GENERATED;

	if(argc != 1)
	{
		int temp = atoi(argv[1]);

		if(temp < 100 || temp > 4000000000)

			return -1;

		num_pentas = atoi(argv[1]);
	}

	pentas = malloc(sizeof(int) * num_pentas);

	do {
		pentas[i] = penta(i);
		
		i++;
	} while(i != num_pentas);

	free(pentas);

	return 0;
}

int penta(unsigned int n)
{
	if(n == 0) return -1; 

	return (3 * n * n - n) / 2;
}

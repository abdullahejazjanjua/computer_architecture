#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 5

int main()
{
	int **M = (int **) malloc(SIZE * sizeof(int*));
	for (int i = 0; i < SIZE; i++)
	{
		M[i] = (int*) malloc(SIZE * sizeof(int));
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			M[i][j] = i + j;
		}
	}
	
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for ordered
		for (int i = 0; i < SIZE; i++)
		{
			int sum = 0;
			for (int j = 0; j < SIZE; j++)
			{
				sum += M[i][j];
			}
			#pragma omp ordered
			{
				printf("Row [%d] sum: %d\n", i, sum);
			}
		}
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		free(M[i]);
	}
	free(M);
}
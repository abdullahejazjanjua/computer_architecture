#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 100

int main()
{
	srand(time(0));
	int *A, *B, result;
	
	A = (int*) malloc(SIZE * sizeof(int));
	B = (int*) malloc(SIZE * sizeof(int));
	
	#pragma omp parallel num_threads(4)
	{
		#pragma omp single
		{
			for (int i = 0; i < SIZE; i++)
			{
				A[i] = (rand() % 100) + 1;
				B[i] = (rand() % 100) + 1;				
			}
		}
		
		#pragma omp for reduction(+:result)
		for (int i = 0; i < SIZE; i++)
		{
			result += (A[i] * B[i]);
		}
	}
	free(A);
	free(B);
	
	printf("A . B = %d\n", result);
}
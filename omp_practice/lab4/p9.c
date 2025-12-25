#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <omp.h>

#define SIZE 500

int main()
{
	srand(time(0));
	int *A, min_val, min_val_count;
	
	A = (int*) malloc(SIZE * sizeof(int));
	min_val = INT_MAX;
	min_val_count = 0;
	
	#pragma omp parallel num_threads(4)
	{
		#pragma omp single
		{
			for (int i = 0; i < SIZE; i++)
			{
				A[i] = (rand() % 100) + 1;				
			}
		}
		
		#pragma omp for reduction(min:min_val)
		for (int i = 0; i < SIZE; i++)
		{
			if (A[i] < min_val)
				min_val = A[i];
		}
		
		#pragma omp for 
		for (int i = 0; i < SIZE; i++)
		{
			#pragma omp critical
			{
				if (A[i] == min_val)
					min_val_count++;
			}
		}
	}
	free(A);

	
	printf("MinVal: %d, MinVal count: %d\n", min_val, min_val_count);
}
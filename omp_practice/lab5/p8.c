#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define SIZE 1000

int main()
{
	int *A, total_sum;;
	A = (int *) malloc(SIZE * sizeof(int));
	total_sum = 0;
	for (int i = 0; i < SIZE; i++) 
	{
    	A[i] = 1;
	}	
	
	#pragma omp parallel
	{
		#pragma omp for
		for (int i = 0; i < SIZE; i++)
		{
			#pragma omp atomic
			total_sum += A[i];
		}
	}
	
	printf("SUM: %d\n", total_sum);
	
	return 0;
}
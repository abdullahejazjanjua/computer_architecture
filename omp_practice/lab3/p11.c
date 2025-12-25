#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> 

#define SIZE 10

int main()
{
	srand(time(0));
	int sum, prod, *A;
	
	A = (int*) malloc(SIZE * sizeof(int));
	sum = 0; 
	prod = 1;
	
	#pragma omp parallel num_threads(10)
	{
		#pragma omp single
		{
			for (int i = 0; i < SIZE; i++)
				A[i] = (rand() % 100) + 1;
		}
		
		#pragma omp for
		for (int i = 0; i < SIZE; i++)
		{
			A[i] = A[i] * 2;
			printf("Thread [%d] processed index [%d]\n", omp_get_thread_num(), i);
		}
	}
}
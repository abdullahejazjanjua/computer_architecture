#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> 

#define SIZE 100

int main()
{
	srand(time(0));
	int sum, avg, count, *A;
	
	A = (int*) malloc(SIZE * sizeof(int));
	sum   = 0; 
	avg   = 0;
	count = 0;
	
	
	#pragma omp parallel num_threads(10)
	{
		#pragma omp single
		{
			for (int i = 0; i < SIZE; i++)
				A[i] = (rand() % 100) + 1;
		}
		
		#pragma omp sections
		{
			#pragma omp section
			{
				for (int i = 0; i < SIZE / 2; i++)
				{
					sum += A[i];
				}
			}
		
			#pragma omp section
			{
				for (int i = SIZE / 2; i < SIZE; i++)
				{
					avg += A[i];
				}
				avg /= (SIZE / 2);
			}
			
			#pragma omp section
			{
				for (int i = 0; i < SIZE; i++)
				{
					if (A[i] > 80)
						count++;
				}
			}
		}
	}
	
	printf("sum: %d, average: %d, count > 80: %d\n", sum, avg, count);
}
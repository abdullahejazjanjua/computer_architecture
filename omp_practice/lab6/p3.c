#include <stdio.h>
#include <omp.h>

#define NLOOPS 15

int main()
{
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for ordered
			for (int i = 0; i < NLOOPS; i++)
			{
				#pragma omp ordered
				printf("Iteration [%d]: Square is [%d]\n", i, i * i);
			}
	}
}
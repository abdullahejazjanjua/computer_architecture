#include <stdio.h>
#include <omp.h>

#define NLOOPS 1000

int main()
{
	int global_counter = 0;
	
	#pragma omp parallel num_threads(4)
	{
		for (int i = 0; i < NLOOPS; i++)
		{
			#pragma omp critical
			{
				global_counter++;
			}
		}
	}
	
	printf("Global sum: %d\n", global_counter);
}
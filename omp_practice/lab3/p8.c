#include <stdio.h>
#include <omp.h>

#define N 101

int main()
{
	int sum = 0;
	#pragma omp parallel num_threads(10)
	{
		#pragma omp for reduction(+:sum)
			for(int i = 0; i < N; i++)
			{
				sum += i;
			}
	}
	
	printf("Sum: %d\n", sum);
}
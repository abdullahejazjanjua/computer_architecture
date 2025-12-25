#include <stdio.h>
#include <omp.h>

#define NLOOPS 15

int main()
{
	double begin = omp_get_wtime();
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for ordered
			for (int i = 0; i < NLOOPS; i++)
			{
				#pragma omp ordered
				printf("Packet [%d] assembled by thread [%d]\n", i, omp_get_thread_num());
			}
	}
	double end = omp_get_wtime();
	
	printf("time taken: %lf\n", (end-begin));
}
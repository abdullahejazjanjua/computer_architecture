#include <stdio.h>
#include <omp.h>

int main()
{
	#pragma omp parallel
	{
		printf("Thread [%d] is performing Phase 1\n", omp_get_thread_num());
		#pragma omp barrier
		#pragma omp master
		{
			printf("--- PHASE 1 COMPLETE ---\n");
		}
		printf("Thread [%d] is performing Phase 2\n", omp_get_thread_num());
	}
}
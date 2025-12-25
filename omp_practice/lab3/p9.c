#include <stdio.h>
#include <omp.h>


int main()
{
	#pragma omp parallel num_threads(6)
	{
		printf("I am thread %d out of total %d\n", omp_get_thread_num(), omp_get_num_threads());
	}
}
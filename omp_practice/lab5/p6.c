#include <stdio.h>
#include <omp.h>

int main()
{
	int val = 100;
	#pragma omp parallel private(val)
	{
		val += omp_get_thread_num(); // each private val is initialized to 0 and not 100
		printf("val: %d\n", val);
	}
	printf("After Parallel Region:\n");
	printf("val: %d\n", val);
}
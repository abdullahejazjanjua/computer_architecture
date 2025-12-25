#include <stdio.h>
#include <omp.h>

int summation(int *A, int N)
{
	if (N <= 0)
		return 0;
	if (N == 1)
		return A[0];
	
	int x, y;
	#pragma omp task shared(x)
	x = summation(A,  N/2);
	
	#pragma omp task shared(y)
	y = summation(A + N/2, N - N/2);
	
	#pragma omp taskwait
	return x + y;
	
}


int main()
{
 	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum;
	
	#pragma omp parallel
	{
		#pragma omp single
		{
			sum = summation(A, 10);
		}
	}
	
	printf("sum: %d\n", sum);
}


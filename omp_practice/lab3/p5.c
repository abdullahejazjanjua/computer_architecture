#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main()
{
    int sum = 0;
    int *A = (int *) malloc(N * sizeof(int));

    #pragma omp parallel
    {
        #pragma omp single
        {
            for(int i = 0; i < N; i++)
            {
                A[i] = (rand() % 100) + 1;
            }
        }
        // Each thread has a local copy of sum
        #pragma omp for reduction(+:sum)
        for(int i = 0; i < N; i++)
        {
            sum += A[i]; //Each thread independently updates its own copy
        } // Once all threads reach here, the sum from all local copies is accumulated in sum variable
    }
    printf("sum: %d\n", sum);
}

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 1000000

int main()
{
    int sum = 0;
    int *A = (int *) malloc(N * sizeof(int));

    #pragma omp parallel num_threads(5)
    {
        #pragma omp single
        {
            for(int i = 0; i < N; i++)
            {
                A[i] = (rand() % 100) + 1;
            }
        }
        #pragma omp for
        for(int i = 0; i < N; i++)
        {
            sum += A[i]; // this is a race condition
        }
    }
    printf("sum: %d\n", sum);
}

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main()
{
    int *A = (int *) malloc(N * sizeof(int));
    int sum = 0;
    #pragma omp parallel
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
            #pragma omp critical
            {
                sum += A[i];
            }
        }
    }

    printf("sum: %d\n", sum);
}

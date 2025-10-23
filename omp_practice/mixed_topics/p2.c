#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000

int main()
{
    int *X = (int *) malloc(N * sizeof(int));
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < N; i++)
            X[i] = 0;

        #pragma omp for
        for(int i = 0; i < N; i++)
            X[i] = X[i] + omp_get_thread_num();

        #pragma omp for ordered
        for(int i = 0; i < N; i++)
        {
            #pragma omp ordered
            {
                printf("X[%d] = %d\n", i, X[i]);
            }
        }

    }
}
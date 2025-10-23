#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main()
{
    int *A = (int *) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        A[i] = (rand() % 100) + 1;
    }

    int global_sum = 0;
    int avg = 0;
    #pragma omp parallel
    {
        int local_sum = 0;
        #pragma omp for
        for(int i = 0; i < N; i++)
        {
            #pragma omp critical
            {
                local_sum += A[i];
            }
        }

        #pragma omp critical
        {
            global_sum += local_sum;
        }

        #pragma omp single
        {
            avg = global_sum / N;
        }
    }
    printf("sum: %d, avg: %d\n", global_sum, avg);
}

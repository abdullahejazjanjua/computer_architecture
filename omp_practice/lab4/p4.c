#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

#define N 1000000

int main()
{
    int *A = (int *) malloc(N * sizeof(int));
    int max = INT_MIN, min = INT_MAX;
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
                if(A[i] > max)
                    max = A[i];
                if(A[i] < min)
                    min = A[i];
            }
        }
    }

    printf("max: %d, min: %d\n", max, min);
}

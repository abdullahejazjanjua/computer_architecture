#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main()
{
    int *A = (int *) malloc(N * sizeof(int));
    int max = INT_MIN, min = INT_MAX, sum = 0;

    for(int i = 0; i < N; i++)
    {
        A[i] = (rand() % 100) + 1;
    }

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for(int i = 0; i < N; i++)
                {
                    sum += A[i];
                }
            }

            #pragma omp section
            {
                for(int i = 0; i < N; i++)
                {
                    if(A[i] > max)
                    {
                        max = A[i];
                    }
                }
            }

            #pragma omp section
            {
                for(int i = 0; i < N; i++)
                {
                    if(A[i] < min)
                    {
                        min = A[i];
                    }
                }
            }
        }
    }

    printf("sum: %d, max: %d, min: %d\n", sum, max, min);
}

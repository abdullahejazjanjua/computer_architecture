#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <limits.h>

#define SIZE 100

int main()
{
    int max = INT_MIN, min = INT_MAX;
    int *A = (int *) malloc(SIZE * sizeof(int));
    #pragma omp parallel
    {
        #pragma omp single
        {
            for(int i = 0; i < SIZE; i++)
            {
                srand(time(0) + omp_get_thread_num());
                A[i] = rand() % SIZE;
            }
        }
 
        #pragma omp for reduction(min:min) reduction(max:max)
        for(int i = 0; i < SIZE; i++)
        {
            if(A[i] > max)
                max = A[i];
            if(A[i] < min)
                min = A[i];
        }
    }
    free(A);
    printf("min: %d, max: %d\n", min, max);
}

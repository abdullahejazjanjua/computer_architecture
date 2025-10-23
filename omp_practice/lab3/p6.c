#include <stdio.h>
#include <omp.h>

int summation(int *A, int N);

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    // 1. Create the parallel region ONCE
    #pragma omp parallel
     {
        // 2. A single thread starts the recursive task generation
        #pragma omp single
        {
            sum = summation(A, 10);
        }
    } // <-- All threads join here
    printf("sum: %d\n", sum);
}

int summation(int *A, int N)
{
    if (N == 0)
    {
        return 0;
    }
    if(N == 1)
    {
        return A[0];
    }
    int half, x, y;
    half = N / 2;
    // Create a task for the first half
     #pragma omp task shared(x)
     x = summation(A, half);

    // Create a task for the second half
    #pragma omp task shared(y)
    y = summation(A + half, N - half);

    // Wait for BOTH tasks to finish
     #pragma omp taskwait
     return x + y;
}

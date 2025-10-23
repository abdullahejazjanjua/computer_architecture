#include <stdio.h>
#include <omp.h>

int max(int A[], int N)
{
    if (N == 0)
        return 0;

    if (N == 1)
        return A[0];

    int x, y, half;
    half = N / 2;
    #pragma omp task shared(x)
    x = max(A, half);

    #pragma omp task shared(y)
    y = max(A + half, N - half);

    #pragma omp taskwait
    if (x > y) return x;
    else return y;
}

int main()
{
    int A[10] = {1, 2, 3, 100, 5, 6, 7, 8, 9, 10};
    int result = 0;
    #pragma omp parallel
    {
        #pragma omp single
        {
            result = max(A, 10);
        }
    }

    printf("max: %d\n", result);
}
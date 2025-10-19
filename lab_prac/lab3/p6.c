#include <stdio.h>
#include <omp.h>

int summation(int *A, int N);

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = summation(A, 10);
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
        return *A;
    }
    int half, x, y;    
    half = N / 2;
    #pragma omp parallel 
    {
        #pragma omp task shared(x)
        x = summation(A, half);
        
        #pragma omp task shared(y)
        y = summation(A + half, N - half); 
        
        #pragma omp taskwait
        x += y; 
    
    }
}

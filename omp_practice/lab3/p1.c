#include <stdio.h>
#include <omp.h>

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int C[10];

    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < 10; i++)
        {
            C[i] = A[i] + B[i];
            printf("C[%d] = %d (Thread: %d)\n", i, C[i], omp_get_thread_num());
        }
    }
}

#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int C[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum_A = 0;
    int prod_B = 1;
    int max_C = 0;
    
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            for(int i = 0; i < 10; i++)
            {
                sum_A += A[i];
            }
            #pragma omp section
            for(int i = 0; i < 10; i++)
            {
                prod_B *= B[i];
            }
            #pragma omp section
            for(int i = 0; i < 10; i++)
            {
                if (max_C < C[i])
                {
                    max_C = C[i];
                }
            }
        }
    }
    double end = omp_get_wtime();
    printf("Sum of Array A: %d\n", sum_A);
    printf("Product of Array B: %d\n", prod_B);
    printf("Max in Array C: %d\n", max_C);
    printf("Total time taken: %f\n", (end-start));
}

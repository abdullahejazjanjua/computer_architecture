#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int C[10];
    
    int num_threads = omp_get_num_threads();
    clock_t start_s = clock();
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 10; i++)
        {
            C[i] = A[i] + B[i];
            printf("\nThread %d of %d computed %d\n", omp_get_thread_num(), num_threads, C[i]);
        }    
   }
   clock_t end_s = clock();
   double end = omp_get_wtime();
   printf("Total parallel time: %f\n", (end - start));
   printf("Total sequential time: %f\n",(double) (end_s - start_s) / CLOCKS_PER_SEC);
 

}

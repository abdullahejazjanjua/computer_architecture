#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int C[10];
    
    int num_threads = omp_get_num_threads();
    clock_t start = clock();
    #pragma omp parallel
    {
        printf("\nHello from thread %d of %d\n", omp_get_thread_num(), num_threads);
        for (int i = 0; i < 10; i++)
        {
            C[i] = A[i] + B[i];
        }
        printf("\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", C[i]);
        } 
        printf("\n");
    }
    clock_t end = clock();
    printf("Total time taken: %f\n", (double) (end - start)/CLOCKS_PER_SEC);

}

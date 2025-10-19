#include <stdio.h>
#include <omp.h>

int main()
{
    double start, end;
    start = omp_get_wtime();
    #pragma omp parallel for ordered
    for(int i = 1; i <= 20; i++)
    {
        #pragma omp ordered
        printf("Thread %d computed square of %d = %d\n", omp_get_thread_num(), i, i * i); 
    }
    end = omp_get_wtime();
    printf("Total time with ordered: %.6f\n\n", (end-start));
    
    start = omp_get_wtime();
    #pragma omp parallel for
    for(int i = 1; i <= 20; i++)
    {
        printf("Thread %d computed square of %d = %d\n", omp_get_thread_num(), i, i * i); 
    }
    end = omp_get_wtime();
    printf("Total time without ordered: %.6f\n\n", (end-start));

}

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(3)
    {
        printf("Thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());

        #pragma omp barrier

        printf("After Barrier (Thread %d)\n", omp_get_thread_num());
    }
}

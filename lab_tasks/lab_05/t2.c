#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(4)
    {
        printf("Thread %d reached before barrier\n", omp_get_thread_num());
        #pragma omp barrier
        printf("Thread %d passed barrier\n", omp_get_thread_num());
    }
}

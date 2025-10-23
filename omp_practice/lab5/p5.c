#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(20)
    {
        #pragma omp master
        {
            printf("The master thread (ID: %d) is doing work...\n", omp_get_thread_num());
        }
        printf("All other threads skip it and continue executing (ID: %d)\n", omp_get_thread_num());
    }
}

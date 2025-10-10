#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        #pragma omp master
        {
            printf("I am master (ID: %d), doing some logging...\n", omp_get_thread_num());
        }
        printf("I am thread %d doing something...\n", omp_get_thread_num());
        #pragma omp barrier
        #pragma omp master
        {
            printf("All work done\n");
        }
    }
}

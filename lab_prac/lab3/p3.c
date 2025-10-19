#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello (Thread: %d)\n", omp_get_thread_num());
        #pragma omp single
        {
            printf("Only one thread will execute it (Thread: %d)\n", omp_get_thread_num());
        }
        printf("This is still executed\n");
    }
}

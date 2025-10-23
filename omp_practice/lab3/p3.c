#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(5)
    {
        printf("Hello (Thread: %d)\n", omp_get_thread_num());
        // A single thread enters the below construct
        #pragma omp single
        {
            printf("Only one thread will execute it (Thread: %d)\n", omp_get_thread_num());
        } // Remaining threads wait here for above thread to finish
        printf("This is still executed\n");
    }
}

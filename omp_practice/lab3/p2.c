#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            // A section is executed only by one thread, other threads skip it.
            // Once a section executed, it is not executed again
            #pragma omp section
            printf("This work is done by only one thread at a time (Thread: %d)\n",
                    omp_get_thread_num());

            #pragma omp section
            printf("This work is also done by one thread at a time (Thread: %d)\n",
                    omp_get_thread_num());
        } // All threads wait here for remaining threads to finish their work
    }
}

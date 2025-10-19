#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(3)
    {
        #pragma omp sections
        {
            #pragma omp section
            printf("This work is done by only one thread at a time (Thread: %d)\n",
                    omp_get_thread_num());

            #pragma omp section
            printf("This work is also done by one thread at a time (Thread: %d)\n",
                    omp_get_thread_num());
        }
    }
}

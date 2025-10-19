#include <stdio.h>
#include <omp.h> 

int main()
{
    #pragma omp parallel num_threads(20)
    {
        printf("Hello, world (thread: %d)\n", omp_get_thread_num());
    }

    return 0;
}

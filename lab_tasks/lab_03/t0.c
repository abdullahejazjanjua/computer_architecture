#include <stdio.h>
#include <omp.h>
#include <time.h>


int main()
{
    int num_threads = omp_get_num_threads();
    clock_t start = clock();
    # pragma omp parallel
    {
        printf("Hello from %d of %d\n", omp_get_thread_num(), num_threads);
    }
   clock_t end = clock(); 
   printf("Total time taken for %d threads is %f\n", num_threads, (double) (end - start)/CLOCKS_PER_SEC);
}

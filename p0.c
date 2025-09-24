#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello, world\n");
    }
    int procs = omp_get_num_procs();
    printf("The total number of processors is: %d\n", procs);
}

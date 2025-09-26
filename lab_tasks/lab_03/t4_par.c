#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int sum = 0;
    double start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
        for(int i = 1; i <= 1000000; i++)
        {
            sum += i;
        }
    double end = omp_get_wtime();
    printf("The total sum is: %d\n", sum);
    printf("Total time taken: %f\n", (end-start));

}

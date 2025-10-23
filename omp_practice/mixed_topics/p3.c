#include <stdio.h>
#include <unistd.h>
#include <omp.h>

#define N 50

int heavy_computation(int i)
{
    printf("Starting parallel work for packet %d\n", i);
    usleep(1000);
    return i * 2;
}

int main()
{
    double start = omp_get_wtime();
    #pragma omp parallel num_threads(3)
    {
        #pragma omp for ordered
        for(int i = 0; i < N; i++)
        {
            int result = heavy_computation(i);
            #pragma omp ordered
            {
                printf("Finished processing packet %d. Result: %d\n", i, result);
            }
        }
    }
    double end = omp_get_wtime();
    printf("Time taken: %.6f\n", (end-start));
}
#include <stdio.h>
#include <omp.h>
#include <math.h>

#define N 100000000

int main()
{
    double start, end, seq_time, pi;
    pi = 0.0;
    
    printf("Serial code:\n");
    start = omp_get_wtime();
    for(int k = 0; k < N; k++)
    {
        pi += pow(-1, k) / (2*k + 1);
    }
    
    pi *= 4;
    end = omp_get_wtime();
    seq_time = end-start;
    
    printf("pi: %lf\n", pi);
    printf("Time take: %.6f\n\n", seq_time);

    printf("Parallel code:\n");
    pi = 0.0;
    start = omp_get_wtime();
    #pragma omp parallel num_threads(8)
    {
        #pragma omp for reduction(+:pi)
        for(int k = 0; k < N; k++)
        {
            pi += pow(-1, k) / (2*k + 1);
        }
        #pragma omp single
        {
            pi *= 4;
        }
    }
    end = omp_get_wtime();
    double par_time = end-start;
    printf("pi: %lf\n", pi);
    printf("Time take: %.6f\n\n", par_time);
    printf("Speed up: %f\n", seq_time / par_time);


}
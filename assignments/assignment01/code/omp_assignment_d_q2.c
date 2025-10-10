#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./out.exe NUM_ITER NUM_THREADS\n");
        return 1;
    }

    int iterations = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    int count = 0;
    int chunk_size = (int) ceil(iterations / (double) num_threads);

    omp_set_num_threads(num_threads);

    // Static scheduling
    count = 0;
    double start_static = omp_get_wtime();
    #pragma omp parallel for schedule(static, chunk_size)
    for(int i = 0; i < iterations; i++) 
    {
        for(int j = 0; j < 100 % (i + 1); j++) 
        {
            double result = exp((double) i / 10.0);
        }
    }
    double end_static = omp_get_wtime();

    // Dynamic scheduling
    count = 0;
    double start_dynamic = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, chunk_size)
    for(int i = 0; i < iterations; i++) 
    {
        for(int j = 0; j < 100 % (i + 1); j++) 
        {
            double result = exp((double) i / 10.0);
        }
    }
    double end_dynamic = omp_get_wtime();

    // Guided scheduling
    count = 0;
    double start_guided = omp_get_wtime();
    #pragma omp parallel for schedule(guided, chunk_size)
    for(int i = 0; i < iterations; i++) 
    {
        for(int j = 0; j < 100 % (i + 1); j++) 
        {
            double result = exp((double) i / 10.0);
        }
    }
    double end_guided = omp_get_wtime();

    printf("Using chunk size: %d and %d threads\n", chunk_size, num_threads);
    printf("The total count is: %d\n", count);
    printf("Static schedule took: %f seconds\n", (end_static - start_static));
    printf("Dynamic schedule took: %f seconds\n", (end_dynamic - start_dynamic));
    printf("Guided schedule took: %f seconds\n", (end_guided - start_guided));

    return 0;
}

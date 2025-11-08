#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./out.exe ARRAY_SIZE NUM_THREADS\n");
        return 1;
    }
    
    int num_threads = atoi(argv[2]);
    int array_size = atoi(argv[1]);
    int sum = 0;
    double start, end, seq_time_taken, par_time_taken, speed_up, efficiency;
    
    omp_set_num_threads(num_threads);
    int *a = malloc(sizeof(int) * array_size);
    
    for (int i = 0; i < array_size; i++)
    {
        a[i] = i % 100;
    }

    
    start = omp_get_wtime();
    for (int i = 0; i < array_size; i++)
    {
        sum += a[i];
    }
    end = omp_get_wtime();
    seq_time_taken = end - start;
    
    sum = 0;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
        for (int i = 0; i < array_size; i++)
        {
            sum += a[i];
        }
    end = omp_get_wtime();
    par_time_taken = end - start;
    speed_up = seq_time_taken / par_time_taken; 
    efficiency = seq_time_taken / (par_time_taken * num_threads);
    printf("Sequential time with array size %d token %lf\n", array_size, seq_time_taken);
    printf("Parallel time with array size %d token %lf\n", array_size, par_time_taken);
    printf("Speed-up: %f%%\n", speed_up * 100);    
    printf("Efficiency: %f%%\n", efficiency * 100);  
    free(a);
}

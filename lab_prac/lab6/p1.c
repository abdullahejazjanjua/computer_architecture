#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./t5.exe ARRAY_SIZE\n");
        return 1;
    }

    int N = atoi(argv[1]);
    double start, end;

    int **A = (int**) malloc(sizeof(int*) * N);
    int **B = (int**) malloc(sizeof(int*) * N);
    int **C = (int**) malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        A[i] = (int*) malloc(N * sizeof(int));
        B[i] = (int*) malloc(N * sizeof(int));
        C[i] = (int*) malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            A[i][j] = 10 * i * j;
            B[i][j] = 10 * i * j;
        }
    }
    
    start = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int sum = 0;
            for(int k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
        }
    }
    end = omp_get_wtime();
    printf("Time taken without ordered: %.6f\n\n", (end-start));

    start = omp_get_wtime();
    #pragma omp parallel for collapse(2) ordered
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int sum = 0;
            for(int k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            #pragma omp ordered
            {
                printf("C[%d][%d] = %d\n", i, j, C[i][j]);
            }
        }
    }
    end = omp_get_wtime();
    printf("Time taken with ordered: %.6f\n", (end-start));

}

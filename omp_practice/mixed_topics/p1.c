#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000
#define K 500

int main()
{
    int **A = (int **) malloc(N * sizeof(int*));
    int **B = (int **) malloc(K * sizeof(int*));
    int **C = (int **) malloc(N * sizeof(int*));

    for(int i = 0; i < N; i++)
    {
        A[i] = (int *) malloc(K * sizeof(int));
        C[i] = (int *) malloc(N * sizeof(int));
    }

    for(int i = 0; i < K; i++)
        B[i] = (int *) malloc(N * sizeof(int));


    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K; j++)
        {
            A[i][j] = (rand() % 100) + 1;
        }
    }

    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
        {
            B[i][j] = (rand() % 100) + 1;
        }
    }

    int sum;
    #pragma omp parallel
    {
        int final_value; // Make a local copy for each thread
        // Parallelize the outer loop making sum private
        #pragma omp for ordered private(sum)
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                sum = 0; // Initialize sum to 0 to accumulate sum per i, j
                for(int k = 0; k < K; k++)
                {
                    // As i is only parallelized + each thread has a sum local copy, there is no race condition
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
            final_value = C[i][N - 1] + C[i][0];
            #pragma omp ordered
            {
                printf("Row %d finalized. FinalValue: %d\n", i, final_value);
            }
        }
    }


    for(int i = 0; i < N; i++)
    {
        free(A[i]);
        free(C[i]);
    }

    for(int i = 0; i < K; i++)
        free(B[i]);

    free(A);
    free(B);
    free(C);
}
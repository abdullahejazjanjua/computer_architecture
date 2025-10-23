#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100

int main()
{
    int **A = (int **) malloc(N * sizeof(int*));
    int **B = (int **) malloc(N * sizeof(int*));
    int **C = (int **) malloc(N * sizeof(int*));

    for(int i = 0; i < N; i++)
    {
        A[i] = (int *) malloc(N * sizeof(int));
        B[i] = (int *) malloc(N * sizeof(int));
        C[i] = (int *) malloc(N * sizeof(int));
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            A[i][j] = (rand() % 100) + 1;
            B[i][j] = (rand() % 99) + 1;
            C[i][j] = 0;
        }
    }

    #pragma omp parallel
    {
        #pragma omp for collapse(2)
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                for(int k = 0; k < N; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }

    free(A);
    free(B);
    free(C);
}

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
    	/*
      		* To use collapse(k), your loops must be perfectly nested. This means that for the 
        	* number of loops you are collapsing, there can be absolutely no code—not even a variable 
         	* declaration—between the for statements.	 
      	*/
        #pragma omp for collapse(2)
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
            	int sum = 0;
                for(int k = 0; k < N; k++)
                {
                    sum  += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
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

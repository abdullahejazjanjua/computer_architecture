#include <stdio.h>
#include <limits.h>
#include <omp.h>

int main()
{
    int A[5] = {1, 10, 99, 78, 33};
    int max = INT_MIN, min = INT_MAX, sum = 0;
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for(int i = 0; i < 5; i++)
                {
                    sum += A[i];
                }
            }
            
            #pragma omp section
            {
                for(int i = 0; i < 5; i++)
                {
                    if(A[i] > max)
                    {
                        max = A[i];
                    }
                }
            }

            #pragma omp section
            {
                for(int i = 0; i < 5; i++)
                {
                    if(A[i] < min)
                    {
                        min = A[i];
                    }
                }
            }
        }
    }

    printf("sum: %d, max: %d, min: %d\n", sum, max, min);
}

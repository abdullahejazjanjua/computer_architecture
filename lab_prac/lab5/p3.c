#include <stdio.h>
#include <omp.h>

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int global_sum = 0;
    #pragma omp parallel
    {
        int local_sum = 0;
        #pragma omp for
        for(int i = 0; i < 10; i++)
        {
            local_sum += A[i];
        }

        #pragma omp critical
        {
            global_sum += local_sum;        
        }    
    }
    printf("sum: %d\n", global_sum);
}

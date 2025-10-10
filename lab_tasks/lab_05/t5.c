#include <stdio.h>
#include <omp.h>

int main()
{
    int A[100], sum = 0;
    for(int i = 0; i < 100; i++)
    {
        A[i] = i * 2;
    }
    #pragma omp parallel for shared(sum)
        for(int i = 0; i < 100; i++)
        {
            #pragma omp atomic
            sum += A[i];   
        }

    printf("Method A: %d\n", sum);
    
    int global_sum = 0;
    #pragma omp parallel private(sum)
    {
        sum = 0;   
        #pragma omp for 
            for(int i = 0; i < 100; i++)
            {   
                sum += A[i];     
            }
        printf("Thread %d partial sum: %d\n", omp_get_thread_num(), sum);
        
        #pragma omp critical
        global_sum += sum;
    }
    printf("Method B: %d\n", global_sum);
   
}

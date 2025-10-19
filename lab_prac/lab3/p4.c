#include <stdio.h>

int main()
{
    int sum = 0;
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    #pragma omp parallel num_threads(10)
    {
        #pragma omp for
        for(int i = 0; i < 10; i++)
        {
            sum += A[i];
        }   
    }
    printf("sum: %d\n", sum);
}

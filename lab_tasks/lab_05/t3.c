#include <stdio.h>
#include <omp.h>

int main()
{
    int count = 0;
    #pragma omp parallel num_threads(16)
    {
        for(int i = 0; i < 100; i++)
        {
            count++;
        }
    }
    printf("Count without atomic: %d\n", count);
    
    count = 0;
    #pragma omp parallel num_threads(16)
    {
        for(int i = 0; i < 100; i++)
        {
            #pragma omp atomic
            count++;
        }
    }
    printf("Count with atomic: %d\n", count);

}

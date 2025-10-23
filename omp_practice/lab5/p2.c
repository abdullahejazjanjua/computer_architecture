#include <stdio.h>
#include <omp.h>

int main()
{
    int var = 0;
    #pragma omp parallel
    {
        for(int i = 0; i < 1000000; i++)
        {
            #pragma omp atomic
            var++;
        }
    }

    printf("var: %d\n", var);
}

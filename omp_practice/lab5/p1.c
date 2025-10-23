#include <stdio.h>
#include <omp.h>

int main()
{
    int var = 0;
    #pragma omp parallel 
    {
        for(int i = 0; i < 100; i++)
            var++;
    }

    printf("var: %d\n", var);
}

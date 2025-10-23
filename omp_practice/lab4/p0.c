#include <stdio.h>
#include <omp.h>

int main()
{
    int var = 0;
    #pragma omp parallel num_threads(20)
    {
        var += 1;
    }

    printf("var: %d\n", var);
}

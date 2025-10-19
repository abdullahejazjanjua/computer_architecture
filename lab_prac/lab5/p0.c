#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 10;
    #pragma omp parallel private(x)
    {
        printf("x: %d (Thread: %d)\n", x, omp_get_thread_num());
    }
    printf("x: %d (After private block)\n", x);
    
    #pragma omp parallel shared(x)
    {
        x++;
        printf("x: %d (Thread: %d)\n", x, omp_get_thread_num());
    }
    printf("x: %d (After public block)\n", x);


}

#include <stdio.h>
#include <omp.h>

int main()
{
    int x = 10;
    #pragma omp parallel private(x) num_threads(3)
    {
        x++;
        printf("x: %d (Thread: %d)\n", x, omp_get_thread_num());
    }
    printf("x: %d (After private block)\n\n", x);

    #pragma omp parallel shared(x) num_threads(3)
    {
        x++;
        printf("x: %d (Thread: %d)\n", x, omp_get_thread_num());
    }
    printf("x: %d (After public block)\n", x);


}

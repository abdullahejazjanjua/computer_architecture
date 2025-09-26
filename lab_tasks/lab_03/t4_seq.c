#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int sum = 0;
    clock_t start = clock();
    for(int i = 1; i < 1000000; i++)
    {
        sum += i;
    }
    clock_t end = clock();
    printf("The total sum is: %d\n", sum);
    printf("Total time taken: %f\n", (double) (end-start)/CLOCKS_PER_SEC);
}

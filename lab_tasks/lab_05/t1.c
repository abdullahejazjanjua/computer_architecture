#include <stdio.h>
#include <omp.h>


int main()
{
    int x = 5;
    printf("x before private: %d\n", x);
    #pragma omp parallel private(x)
    {
        x = omp_get_thread_num();
        printf("x: %d\n", x);
    }
    printf("x after private: %d\n", x);
    printf("\n");
    printf("x before shared: %d\n", x);
    #pragma omp parallel shared(x)
    {
        x++; 
    }
    printf("x after shared: %d\n", x);
}

/*
   In the first parallel block, x is declared private. This means each 
   thread has its own copy of x, initialized separately, so changes by 
   one thread don't affect others or the original x.

    In the second parallel block, x is shared among all threads. Threads 
    operate on the same x, so increments by different threads can affect the final value.

 */

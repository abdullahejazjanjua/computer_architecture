#include <stdio.h>
#include <omp.h>

// Recursive function ONLY creates tasks
int fib(int n) {
    if (n < 2)
    {
        return n;
    }

    int x, y;

    #pragma omp task shared(x)
    x = fib(n - 1);

    #pragma omp task shared(y)
    y = fib(n - 2);

    #pragma omp taskwait
    return x + y;
}

int main() {
    int n = 100;
    int result;

    // Create the thread pool ONCE
    #pragma omp parallel
    {
        // One thread starts the task generation
        #pragma omp single
        {
            result = fib(n);
        }
    } // Threads join here

    printf("Fib of %d: %d\n", n, result); // Correctly prints "Fib of 6: 8"
}
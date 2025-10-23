#include <stdio.h>
#include <omp.h>
#include <string.h>

int count_vowels(char *s, int length)
{
    if (length == 0) return 0;
    if (length == 1)
    {
        if(s[0] == 'a' | s[0] == 'e' | s[0] == 'i' | s[0] == 'o' | s[0] == 'u')
        {
            return 1;
        }
        return 0;
    }

    int x, y, half;
    half = length / 2;

    #pragma omp task shared(x)
    x = count_vowels(s, half);

    #pragma omp task shared(y)
    y = count_vowels(s + half, length - half);

    #pragma omp taskwait
    return x + y;
}

int main()
{
    int result;
    char *s = "Hello, peeps. i am khan.";
    #pragma omp parallel
    {
        #pragma omp single
        {
            result = count_vowels(s, strlen(s));
        }
    }
    printf("Number of vowels: %d\n", result);
}
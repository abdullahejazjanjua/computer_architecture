#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergesort_parallel(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            mergesort_parallel(arr, left, mid);

            #pragma omp section
            mergesort_parallel(arr, mid + 1, right);
        }
        merge(arr, left, mid, right);
    }
}


int main()
{
    int arr[16], segment_size = 4;

    for(int i = 0; i < 16; i++)
    {
        arr[i] = (rand() % 10) + 1;
    }

    printf("Random array:\n");
    for(int i = 0; i < 16; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double start = omp_get_wtime();
    #pragma omp parallel for ordered
    for(int i = 0; i < segment_size; i++)
    {
        int start = (i * segment_size);
        int end = (start + segment_size);
        mergesort_parallel(arr, start, end - 1);
        #pragma omp ordered
        {
            printf("Segment %d: ", i);
            for(int j = start; j < end; j++)
            {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
    }
    double end = omp_get_wtime();
    printf("Time taken: %.6f\n", (end-start));
}

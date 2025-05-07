#include <iostream>
#include <omp.h>
#include <cstdlib>

#define SIZE 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Parallel Bubble Sort using OpenMP
void parallelBubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        // Even phase
        #pragma omp parallel for default(none) shared(arr, n)
        for (j = 0; j < n - 1; j += 2) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }

        // Odd phase
        #pragma omp parallel for default(none) shared(arr, n)
        for (j = 1; j < n - 1; j += 2) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

// Merge function used in Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Parallel Merge Sort
void parallelMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr, l, m);

            #pragma omp section
            parallelMergeSort(arr, m + 1, r);
        }

        merge(arr, l, m, r);
    }
}

// Utility function to fill an array with random numbers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 1000;
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[SIZE], arr2[SIZE];

    fillArray(arr1, SIZE);
    for (int i = 0; i < SIZE; i++)
        arr2[i] = arr1[i];  // Copy for second sort

    double start, end;

    // Parallel Bubble Sort
    start = omp_get_wtime();
    parallelBubbleSort(arr1, SIZE);
    end = omp_get_wtime();
    printf("Parallel Bubble Sort Time: %f seconds\n", end - start);

    // Parallel Merge Sort
    start = omp_get_wtime();
    parallelMergeSort(arr2, 0, SIZE - 1);
    end = omp_get_wtime();
    printf("Parallel Merge Sort Time: %f seconds\n", end - start);

    return 0;
}

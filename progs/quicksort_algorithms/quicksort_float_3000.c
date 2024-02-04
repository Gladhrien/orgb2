#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// find partition position
int partition(float arr[], int low, int high) {

    // Choose the rightmost element as pivot
    float pivot = arr[high];

    // Pointer for greater element
    int i = (low - 1);

    // Traverse through all elements
    // compare each element with pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            // If element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // Swapping element at i with element at j
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with
    // the greater element specified by i
    swap(&arr[i + 1], &arr[high]);

    // Return the position from where partition is done
    return (i + 1);
}

// Function to perform quicksort
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    float arr[] = {501.5, 339.2, 922.1, 420.4};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    return 0;
}

// complex: O(nlogn)

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// find partition position
int partition(int arr[], int low, int high) {

    // Choose the rightmost element as pivot
    int pivot = arr[high];

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
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);  
    printf("Array Ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  
    }
    return 0;
}
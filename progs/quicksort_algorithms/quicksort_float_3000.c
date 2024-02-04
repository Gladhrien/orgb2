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
    float arr[] = {2.11, 1.54, 2.61, 6.39, 2.95, 6.78, 5.43, 4.34, 4.17, 6.54, 7.11, 2.19, 6.11, 7.76, 7.95, 3.25, 5.36, 4.01, 7.59, 6.91, 8.78, 8.92, 9.36, 9.42, 4.66, 4.06, 5.84, 4.01, 2.80, 4.91, 3.83, 8.23, 2.15, 9.41, 7.18, 2.09, 2.13, 9.30, 1.28, 5.94, 5.95, 7.83, 9.44, 7.87, 6.21, 1.95, 4.33, 5.48, 5.55, 1.37, 6.51, 1.26, 1.68, 4.42, 4.72, 8.37, 1.04, 5.30, 8.86, 1.18, 6.16, 2.68, 7.01, 8.13, 3.21, 1.79, 8.60, 3.98, 7.71, 5.02, 9.09, 5.81, 5.18, 5.40, 3.93, 1.68, 5.09, 2.65, 1.83, 1.25, 9.17, 3.91, 6.58, 2.16, 6.63, 9.31, 5.30, 6.73, 7.30, 5.63, 9.77, 6.15, 4.92, 2.27, 7.74, 5.92, 6.44, 4.86, 8.48, 4.95, 2.12, 3.75, 9.75, 6.00, 8.20, 1.09, 8.63, 9.73, 4.76, 7.20, 8.78, 2.49, 6.20, 1.24, 2.81, 1.66, 9.48, 1.93, 8.87, 2.46, 2.28, 1.65, 5.11, 3.79, 9.64, 6.48, 8.57, 6.09, 4.88, 9.70, 8.84, 9.47, 5.05, 5.79, 9.70, 9.83, 5.66, 3.80, 6.17, 6.08, 1.70, 9.99, 9.89, 3.69, 6.99, 5.06, 5.67, 2.95, 3.75, 4.33, 2.83, 5.93, 3.90, 4.62, 3.15, 9.15, 1.70, 4.79, 1.58, 8.09, 9.49, 6.18, 8.64, 9.18, 3.11, 6.80, 3.03, 1.47, 6.15, 8.30, 3.08, 4.07, 4.26, 1.63, 1.04, 9.58, 3.04, 2.65, 2.29, 9.68, 6.71, 8.21, 8.39, 8.32, 6.18, 4.65, 4.09, 8.52, 8.47, 7.49, 3.18, 8.87, 3.41, 1.20, 7.78, 3.94, 7.02, 2.86, 7.27, 1.74, 4.47, 8.92, 1.89, 5.75, 7.74, 2.62, 3.26, 5.88, 5.19, 7.59, 4.10, 6.11, 5.90, 9.88, 1.39, 8.44, 8.95, 6.50, 8.29, 9.98, 9.57, 6.93, 2.01, 1.32, 8.42, 8.69, 5.69, 1.56, 7.29, 1.44, 1.59, 3.83, 9.18, 3.81, 2.07, 7.57, 4.28, 1.51, 4.07, 2.28, 7.02, 9.49, 3.57, 9.02, 7.81, 5.51, 2.80, 4.75, 2.16, 9.95, 5.01, 4.97, 9.78, 3.39, 6.61, 3.23, 4.28, 3.65, 8.97, 3.03, 6.42, 7.69, 7.52, 9.13, 3.00, 6.41, 3.15, 2.65, 8.21, 4.38, 9.05, 1.80, 3.93, 1.13, 9.51, 8.59, 1.73, 3.02, 4.43, 9.73, 4.95, 6.80, 9.18, 8.74, 9.57, 7.96, 1.77, 6.14, 2.19, 8.94, 6.85, 2.76, 7.38, 1.09, 2.10, 1.35, 6.47, 7.28, 4.06, 5.12, 9.25, 3.80, 9.60, 2.97, 1.72, 4.41, 6.63, 1.02, 5.00, 7.00, 6.29, 4.68, 1.67, 7.83, 5.46, 6.41, 5.48, 4.36, 3.39, 2.89, 3.89, 4.80, 2.84, 5.36, 7.20, 9.09, 8.57, 6.23, 5.60, 3.55, 7.01, 7.22, 2.82, 9.73, 8.04, 8.15, 6.70, 1.25, 6.38, 3.02, 6.74, 7.08, 9.90, 5.50, 8.41, 4.13, 1.49, 6.56, 4.63, 1.10, 3.78, 5.32, 5.47, 7.72, 8.19, 9.77, 8.46, 8.49, 2.00, 1.22, 4.70, 6.01, 8.33, 8.62, 1.59, 8.61, 6.72, 5.57, 5.92, 5.03, 1.20, 3.66, 5.76, 6.97, 5.04, 7.56, 2.35, 8.41, 4.27, 4.26, 6.62, 6.55, 9.53, 9.80, 7.75, 8.05, 8.49, 7.49, 7.72, 1.96, 2.71, 2.16, 2.14, 1.95, 3.12, 5.78, 6.81, 1.89, 5.02, 2.64, 1.38, 8.34, 4.64, 6.23, 4.22, 7.48, 1.85, 5.13, 2.71, 6.57, 1.52, 7.44, 8.53, 6.05, 9.99, 6.80, 8.09, 1.86, 2.58, 2.89, 8.82, 5.15, 6.97, 4.24, 2.99, 7.99, 3.67, 2.84, 3.99, 3.24, 7.06, 7.70, 1.74, 3.06, 2.59, 3.06, 6.16, 8.25, 2.75, 1.11, 1.65, 3.46, 5.75, 6.64, 8.20, 1.83, 6.03, 2.83, 2.53, 2.30, 8.99, 7.41, 7.66, 7.97, 9.23, 8.35, 5.73, 7.15, 8.23, 4.22, 8.58, 2.36, 2.58, 2.42, 8.34, 7.96, 3.07, 5.18, 8.50, 3.90, 9.91, 6.66, 8.48, 1.72, 3.84, 5.22, 7.36, 2.24, 5.31, 9.22, 1.08, 4.52, 1.58, 8.28, 7.55, 7.67, 3.24, 6.77, 5.28, 2.38, 6.54, 1.94, 7.68, 9.33, 8.32, 2.47, 8.35, 1.46, 4.13, 1.25, 2.40, 8.94, 6.69, 7.62, 9.54, 4.70, 8.91, 7.19, 6.36, 4.50, 1.85, 8.43, 7.46, 6.70, 3.26, 5.39, 5.03, 5.87, 1.90, 2.46, 6.65, 8.98, 5.79, 4.26, 7.34, 9.92, 6.26, 9.21, 8.68, 9.56, 6.93, 2.81, 4.60, 8.05, 5.71, 5.16, 7.05, 8.77, 9.23, 2.12, 5.98, 8.29, 4.10, 2.06, 5.21, 7.79, 3.92, 5.52, 1.18, 8.93, 9.36, 7.00, 5.00, 4.16, 1.00, 5.44, 2.23, 2.28, 4.18, 2.90, 9.38, 5.19, 1.05, 5.88, 9.76, 2.48, 4.75, 7.04, 3.43, 5.25, 8.49, 4.29, 9.63, 9.86, 1.02, 2.33, 6.13, 9.28, 9.75, 2.91, 3.96, 2.29, 1.56, 9.59, 3.56, 9.08, 5.29, 8.67, 7.43, 6.39, 2.33, 4.22, 8.09, 8.54, 7.46, 4.87, 4.47, 1.15, 7.80, 6.81, 9.48, 9.84, 3.20, 3.10, 8.70, 9.75, 7.00, 4.56, 5.91, 7.16, 7.89, 8.36, 5.85, 2.87, 9.55, 7.44, 8.12, 1.46, 3.37, 1.31, 7.42, 9.40, 2.86, 9.63, 1.43, 1.98, 2.41, 6.06, 7.84, 8.24, 1.07, 2.97, 5.49, 7.44, 6.90, 3.95, 7.32, 4.40, 9.96, 8.23, 2.17, 1.49, 2.91, 8.53, 8.59, 6.75, 4.23, 7.94, 7.57, 5.49, 3.78, 2.05, 1.60, 1.20, 2.04, 2.94, 8.12, 3.00, 6.41, 2.62, 6.08, 7.33, 3.55, 1.41, 6.81, 6.90, 3.63, 5.35, 4.48, 8.71, 7.44, 4.25, 8.46, 3.35, 6.18, 6.82, 5.70, 3.52, 4.81, 8.25, 7.91, 2.96, 1.19, 5.52, 2.77, 1.17, 6.70, 6.31, 5.63, 1.86, 8.55, 9.21, 9.29, 9.45, 7.20, 2.78, 4.41, 7.38, 7.21, 8.61, 8.01, 8.91, 4.71, 3.50, 9.22, 1.64, 9.57, 4.56, 1.76, 4.53, 9.51, 5.01, 9.78, 3.69, 4.63, 4.14, 6.07, 4.77, 8.01, 8.22, 5.25, 5.57, 9.84, 9.78, 1.27, 3.43, 8.36, 7.90, 2.70, 7.90, 7.32, 2.51, 1.63, 6.53, 6.65, 8.07, 6.68, 4.05, 7.06, 3.67, 1.68, 6.80, 8.84, 1.82, 1.16, 2.19, 2.40, 5.56, 6.12, 7.23, 3.40, 1.69, 1.95, 9.07, 9.35, 2.44, 2.72, 5.19, 4.77, 9.42, 9.82, 8.22, 3.64, 5.07, 7.23, 8.54, 4.85, 8.04, 9.05, 7.60, 9.19, 6.99, 2.59, 2.03, 8.25, 7.10, 2.02, 2.47, 5.89, 3.47, 8.85, 2.93, 9.15, 6.71, 1.33, 1.47, 6.10, 3.23, 2.54, 3.72, 8.63, 3.09, 8.97, 6.95, 6.77, 3.44, 2.58, 4.68, 9.27, 6.46, 3.37, 1.57, 5.52, 2.58, 1.03, 8.59, 5.25, 1.29, 9.55, 1.23, 9.33, 5.17, 2.73, 9.21, 2.57, 3.54, 9.84, 3.12, 9.36, 3.14, 4.19, 6.48, 1.55, 8.33, 6.87, 5.12, 2.80, 4.69, 1.11, 7.42, 2.73, 1.06, 3.55, 8.72, 6.29, 9.71, 6.08, 7.34, 6.76, 7.41, 1.50, 3.18, 9.58, 3.29, 7.97, 5.97, 6.96, 3.14, 3.54, 7.82, 1.61, 2.24, 6.24, 9.14, 5.23, 4.41, 5.37, 9.52, 6.89, 1.04, 9.56, 4.31, 2.99, 5.37, 6.99, 3.17, 2.19, 8.90, 5.45, 6.22, 6.42, 3.76, 9.63, 8.52, 4.87, 6.07, 1.01, 6.04, 3.33, 2.07, 6.61, 2.57, 2.06, 9.38, 1.81, 5.74, 8.62, 3.93, 2.05, 8.70, 1.71, 9.34, 9.82, 2.78, 7.65, 9.42, 9.60, 6.74, 3.83, 6.00, 2.26, 6.15, 7.19, 5.04, 7.17, 8.91, 3.66, 8.19, 9.70, 3.59, 2.67, 9.28, 4.97, 4.48, 3.05, 4.57, 4.42, 9.17, 9.41, 8.39, 9.39, 4.46, 5.83, 7.96, 7.58, 5.51, 7.69, 6.10, 6.28, 2.92, 1.80, 2.34, 4.01, 2.95, 7.93, 5.66, 7.38, 7.26, 8.58, 3.31, 4.38, 3.62, 9.13, 9.96, 1.77, 3.06, 9.67, 9.79, 8.76, 5.38, 9.66, 3.60, 7.68, 9.00, 3.47, 2.88, 7.40, 7.15, 4.04, 8.73, 6.78, 6.54, 9.12, 1.86, 2.25, 1.45, 6.90, 9.81, 3.70, 9.71, 9.96, 8.11, 2.27, 2.14, 1.15, 1.16, 1.14, 1.94, 1.91, 5.98, 9.26, 4.85, 8.21, 9.93, 4.11, 6.11, 1.44, 2.17, 4.32, 3.18, 8.31, 9.32, 4.00, 2.89, 8.26, 8.02, 5.24, 2.63, 9.49, 8.02, 4.45, 3.52, 2.98, 3.61, 4.67, 8.79, 3.64, 4.95, 6.77, 5.29, 1.06, 1.08, 2.48, 9.92, 7.71, 2.31, 2.88, 7.95, 5.46, 5.32, 4.99, 1.05, 9.14, 1.10, 9.41, 1.79, 4.39, 2.91, 5.51, 3.53, 3.51, 5.65, 9.74, 4.77, 1.98, 4.57, 2.37, 6.58, 3.56, 4.74, 8.28, 3.71, 5.56, 7.98, 8.43, 4.45, 3.27, 2.09, 1.91, 7.25, 3.14, 1.79, 4.73, 9.69, 1.84, 4.97, 9.40, 8.00, 2.77, 2.31, 4.98, 5.23, 6.66, 2.71, 6.02, 8.82, 3.05, 4.69, 6.73, 7.88, 2.62, 1.03, 5.22, 1.51, 1.59, 2.25, 6.24, 5.67, 8.60, 3.86, 3.95, 9.85, 5.55, 5.38, 8.44, 2.63, 6.00, 3.57, 3.32, 2.34, 2.30, 9.62, 6.47, 2.26, 7.60, 4.40, 8.80, 4.50, 4.96, 4.81, 8.90, 8.45, 4.53, 4.61, 9.08, 2.35, 4.49, 6.36, 2.77, 2.22, 5.30, 3.81, 5.53, 3.48, 1.58, 2.66, 6.59, 1.21, 7.52, 7.92, 5.63, 4.27, 7.13, 3.49, 7.53, 1.17, 4.94, 2.74, 7.34, 2.79, 5.09, 6.42, 3.82, 3.84, 6.39, 1.55, 6.75, 2.50, 1.34, 2.99, 3.57, 6.44, 1.24, 6.37, 4.78, 9.10, 8.88, 5.00, 5.14, 2.03, 8.79, 8.40, 6.57, 5.03, 2.23, 7.09, 6.16, 6.94, 8.52, 3.77, 8.38, 3.35, 6.29, 4.11, 6.45, 8.97, 8.26, 3.69, 1.44, 3.06, 9.67, 7.52, 8.83, 1.44, 7.08, 9.56, 8.83, 9.14, 3.97, 9.79, 9.38, 1.31, 1.81, 7.86, 9.53, 9.20, 6.71, 2.86, 2.87, 4.96, 7.37, 6.79, 7.93, 6.30, 9.11, 7.23, 7.78, 4.93, 2.81, 4.16, 5.53, 7.24, 3.01, 5.64, 7.36, 5.45, 3.73, 9.18, 4.35, 8.92, 2.45, 4.56, 9.74, 1.07, 4.59, 2.35, 4.80, 2.38, 7.69, 8.14, 9.09, 9.55, 9.32, 2.17, 9.62, 4.55, 3.32, 5.44, 8.81, 1.30, 9.84, 8.87, 1.88, 6.22, 4.32, 4.50, 3.43, 7.66, 3.96, 7.91, 1.17, 8.56, 8.46, 4.83, 4.82, 9.61, 6.86, 6.51, 5.36, 1.90, 6.96, 5.43, 8.38, 8.47, 1.87, 1.99, 2.24, 7.48, 5.80, 2.00, 1.41, 4.44, 7.65, 3.87, 9.87, 2.73, 7.51, 2.49, 3.91, 8.04, 7.13, 2.82, 5.73, 5.10, 6.76, 6.26, 5.12, 6.19, 5.94, 5.21, 4.34, 2.98, 7.48, 7.35, 1.60, 5.72, 1.48, 3.21, 1.92, 3.52, 5.63, 9.64, 1.45, 4.04, 2.43, 9.89, 1.29, 2.21, 4.41, 6.36, 9.47, 8.60, 7.46, 8.42, 4.35, 8.31, 9.98, 5.93, 7.31, 6.58, 9.68, 9.78, 3.75, 1.34, 5.98, 1.67, 6.69, 1.52, 4.82, 8.73, 9.54, 3.68, 1.69, 4.82, 6.83, 4.84, 1.73, 6.24, 3.39, 9.04, 5.83, 2.37, 8.34, 9.56, 7.62, 1.22, 9.93, 3.83, 6.55, 4.24, 9.71, 2.45, 5.78, 9.12, 8.24, 9.93, 6.88, 4.67, 8.51, 3.16, 1.64, 9.82, 1.84, 6.05, 8.45, 4.58, 8.18, 5.06, 9.22, 5.65, 4.54, 3.04, 5.84, 6.04, 3.34, 5.09, 8.30, 9.87, 5.27, 9.54, 4.29, 7.94, 7.76, 1.48, 3.82, 4.65, 9.51, 2.00, 7.38, 6.94, 5.96, 4.33, 6.35, 3.84, 3.27, 1.32, 7.77, 1.20, 6.05, 9.65, 4.64, 1.50, 9.97, 7.14, 1.36, 8.33, 8.86, 9.80, 6.50, 9.60, 7.13, 9.10, 7.07, 2.27, 1.13, 9.29, 3.26, 1.87, 8.18, 8.56, 5.86, 4.27, 3.49, 7.30, 6.74, 1.74, 3.11, 5.60, 2.61, 2.26, 7.45, 2.52, 1.28, 3.03, 2.54, 7.08, 7.29, 3.71, 8.11, 8.17, 5.42, 3.29, 9.83, 9.45, 8.61, 2.79, 7.85, 9.08, 7.25, 5.33, 4.15, 7.43, 9.01, 8.50, 9.36, 2.85, 1.42, 4.10, 2.01, 8.96, 7.61, 1.88, 3.91, 7.95, 4.23, 9.40, 4.19, 9.94, 9.06, 6.20, 5.16, 3.90, 5.62, 4.02, 3.94, 8.69, 4.15, 2.05, 3.99, 5.84, 6.85, 4.09, 5.86, 8.03, 8.35, 4.95, 9.62, 3.82, 4.02, 2.69, 7.73, 6.66, 5.87, 4.43, 1.29, 6.95, 9.66, 4.11, 9.91, 4.85, 1.39, 9.03, 2.47, 8.06, 2.81, 4.18, 4.25, 4.88, 4.03, 3.98, 6.15, 3.00, 3.36, 1.13, 8.76, 8.12, 5.83, 3.42, 7.24, 3.50, 7.41, 4.46, 2.52, 7.18, 2.73, 1.84, 8.43, 5.40, 5.20, 3.86, 2.55, 5.61, 2.32, 1.27, 1.11, 8.85, 5.96, 3.02, 7.63, 4.43, 7.46, 8.80, 1.26, 1.85, 3.18, 3.42, 4.92, 4.30, 5.99, 3.17, 3.15, 3.28, 4.25, 5.21, 9.89, 2.68, 2.18, 7.78, 9.94, 7.47, 9.13, 6.63, 3.00, 7.58, 4.75, 2.93, 7.24, 5.17, 3.38, 1.53, 1.88, 1.34, 8.63, 1.58, 3.29, 2.63, 7.72, 7.12, 9.68, 5.08, 2.75, 7.65, 2.53, 8.01, 1.17, 8.36, 2.64, 8.98, 6.27, 5.35, 9.46, 5.91, 9.81, 5.99, 3.76, 3.41, 2.22, 4.52, 8.83, 6.50, 9.27, 2.90, 5.82, 5.25, 4.28, 6.97, 2.75, 7.27, 4.12, 8.71, 8.41, 6.67, 5.16, 2.15, 9.64, 1.75, 3.70, 5.59, 6.84, 8.15, 3.15, 7.89, 6.57, 7.11, 3.48, 3.08, 9.26, 7.98, 7.55, 1.62, 1.54, 4.70, 9.00, 8.55, 4.89, 3.73, 3.96, 7.82, 7.87, 7.71, 1.05, 5.54, 5.89, 8.72, 7.63, 1.21, 8.95, 7.63, 6.06, 5.94, 1.79, 7.58, 4.74, 3.09, 4.72, 5.88, 5.00, 8.90, 7.50, 2.96, 5.67, 2.20, 2.66, 2.39, 1.15, 6.92, 6.03, 1.77, 1.53, 7.92, 7.85, 6.38, 8.30, 8.96, 3.61, 9.16, 5.39, 9.67, 2.01, 4.86, 2.09, 2.18, 7.22, 9.76, 1.47, 9.65, 5.13, 2.56, 3.72, 2.25, 2.16, 3.77, 9.88, 5.59, 4.37, 9.43, 9.90, 9.51, 3.20, 6.83, 4.66, 1.26, 8.73, 9.37, 1.38, 7.61, 1.14, 8.81, 8.88, 7.54, 9.81, 7.17, 1.76, 8.29, 7.43, 8.73, 1.83, 4.54, 7.37, 5.33, 9.28, 7.39, 4.37, 4.88, 2.60, 7.64, 6.85, 1.55, 2.70, 9.98, 5.16, 7.25, 4.66, 5.49, 2.79, 4.83, 3.36, 3.05, 2.29, 5.50, 8.06, 3.92, 8.84, 4.21, 5.69, 7.70, 5.11, 1.65, 1.78, 7.03, 8.98, 6.79, 4.42, 3.92, 1.41, 5.37, 2.94, 4.50, 4.03, 1.09, 6.87, 7.68, 6.51, 5.56, 7.47, 3.23, 6.34, 2.04, 1.87, 1.23, 5.10, 4.60, 6.29, 9.69, 8.24, 1.83, 5.93, 5.85, 4.73, 1.56, 5.42, 4.90, 3.68, 6.83, 6.53, 6.46, 8.31, 5.96, 8.68, 9.00, 3.56, 7.47, 5.82, 5.26, 6.00, 6.21, 4.97, 8.74, 8.27, 3.66, 8.74, 8.15, 6.62, 4.39, 2.84, 4.94, 6.30, 6.38, 2.46, 4.53, 6.21, 7.56, 8.37, 1.04, 2.40, 2.12, 4.44, 9.99, 2.94, 3.45, 2.32, 9.32, 5.47, 6.76, 7.80, 7.03, 5.80, 8.82, 3.23, 1.28, 5.88, 7.05, 4.44, 4.14, 7.10, 2.34, 3.50, 8.43, 3.31, 4.89, 1.67, 5.66, 1.54, 4.36, 3.74, 5.08, 1.34, 5.14, 8.37, 9.79, 8.57, 8.16, 9.20, 3.42, 6.56, 3.54, 8.93, 9.71, 8.93, 5.64, 5.55, 1.50, 5.54, 5.58, 9.06, 5.15, 6.52, 5.70, 9.65, 6.43, 5.07, 3.59, 3.75, 4.47, 4.46, 9.24, 9.52, 5.60, 3.96, 8.22, 4.20, 1.42, 8.75, 6.59, 5.81, 9.39, 4.68, 7.77, 3.89, 7.14, 2.46, 6.33, 6.13, 5.28, 6.45, 5.95, 6.13, 4.04, 8.07, 1.62, 8.28, 1.47, 2.18, 1.24, 4.61, 8.07, 1.31, 7.23, 9.34, 1.65, 1.46, 8.19, 1.35, 9.54, 7.19, 6.21, 8.12, 4.71, 4.38, 5.72, 5.97, 3.20, 2.85, 6.31, 3.62, 8.55, 1.57, 7.16, 6.91, 1.52, 9.00, 7.55, 5.81, 5.86, 6.59, 9.33, 7.51, 1.43, 3.19, 7.07, 6.68, 3.95, 6.25, 5.64, 2.20, 2.76, 3.50, 1.32, 8.89, 3.38, 1.14, 6.89, 2.60, 4.58, 8.65, 4.31, 1.71, 2.30, 6.35, 1.27, 9.74, 2.87, 2.33, 9.65, 3.44, 3.53, 3.58, 6.22, 6.88, 7.98, 7.37, 8.84, 4.46, 3.58, 9.90, 9.07, 7.86, 8.88, 1.38, 7.18, 3.34, 2.69, 4.23, 7.67, 8.89, 5.89, 2.94, 5.40, 5.77, 8.85, 2.23, 7.54, 9.80, 9.05, 4.07, 4.17, 8.99, 8.00, 3.38, 4.84, 7.21, 6.19, 2.50, 5.73, 5.54, 3.39, 6.84, 7.67, 8.13, 5.70, 7.84, 3.08, 9.03, 5.91, 6.87, 6.46, 1.89, 7.67, 1.73, 4.20, 4.37, 8.64, 8.32, 8.81, 5.26, 1.41, 4.49, 7.49, 9.43, 2.55, 8.02, 7.66, 5.79, 5.06, 3.13, 5.04, 7.04, 2.08, 4.99, 8.67, 4.40, 5.24, 7.06, 7.50, 7.12, 8.61, 1.97, 7.65, 2.37, 1.10, 6.02, 4.51, 5.54, 7.27, 4.93, 4.05, 3.36, 4.77, 5.07, 6.69, 8.75, 4.87, 8.00, 1.95, 1.18, 7.05, 8.30, 5.48, 8.66, 9.39, 9.04, 9.91, 4.11, 2.67, 3.51, 6.32, 3.63, 3.64, 5.94, 6.52, 7.75, 5.43, 9.98, 5.67, 4.29, 2.42, 9.35, 6.65, 2.91, 8.27, 9.60, 2.88, 5.42, 9.47, 4.25, 6.43, 5.42, 6.49, 2.56, 5.69, 8.17, 4.08, 3.78, 7.11, 6.20, 2.90, 6.57, 2.42, 9.50, 2.04, 4.73, 9.37, 8.51, 4.79, 4.13, 6.86, 7.62, 6.07, 5.41, 7.64, 3.02, 1.50, 9.05, 5.75, 3.63, 3.21, 8.09, 5.05, 1.08, 7.74, 4.04, 3.21, 1.30, 1.70, 1.00, 2.98, 6.01, 2.64, 3.24, 3.56, 3.10, 3.40, 6.92, 6.95, 5.40, 2.61, 4.13, 8.48, 4.17, 9.53, 5.91, 6.35, 9.02, 4.17, 1.01, 1.42, 4.20, 4.21, 5.02, 7.17, 6.40, 7.45, 9.75, 8.71, 5.33, 1.78, 3.77, 7.28, 4.31, 7.77, 6.84, 2.41, 3.22, 1.37, 8.34, 3.13, 8.54, 2.09, 9.93, 3.11, 3.32, 7.75, 4.00, 2.51, 4.86, 7.29, 2.59, 4.91, 6.09, 2.84, 9.27, 6.94, 9.86, 1.89, 9.11, 6.03, 1.33, 5.71, 4.88, 9.19, 1.66, 3.62, 4.05, 3.29, 4.35, 4.63, 7.53, 2.41, 8.63, 3.71, 4.32, 9.24, 5.72, 8.03, 5.12, 4.61, 7.04, 5.84, 7.82, 3.53, 1.30, 6.40, 4.54, 4.59, 2.52, 2.40, 1.63, 9.16, 9.23, 5.77, 2.44, 3.30, 4.20, 5.68, 3.49, 5.62, 9.92, 5.95, 8.16, 1.02, 8.10, 4.55, 1.48, 7.80, 3.85, 5.32, 9.03, 8.77, 6.75, 6.44, 7.34, 3.33, 7.26, 7.40, 8.10, 8.48, 8.96, 7.01, 1.91, 4.03, 5.47, 7.89, 8.76, 2.60, 3.61, 8.95, 2.03, 2.53, 4.98, 9.24, 6.27, 1.93, 8.18, 6.04, 6.62, 9.58, 7.77, 7.91, 5.35, 6.26, 7.61, 4.19, 5.37, 5.61, 2.51, 4.78, 7.26, 6.73, 9.66, 2.06, 1.53, 4.81, 8.58, 4.94, 9.38, 1.97, 2.28, 5.28, 6.27, 3.44, 3.07, 5.82, 9.23, 8.00, 6.82, 7.85, 2.13, 6.91, 1.75, 3.87, 9.29, 4.89, 9.17, 2.21, 5.10, 5.76, 1.85, 4.83, 1.19, 8.96, 7.55, 2.88, 1.22, 3.35, 5.80, 3.54, 3.12, 2.08, 5.75, 8.38, 6.60, 3.25, 3.60, 2.55, 6.72, 8.45, 2.93, 2.37, 6.60, 4.14, 1.71, 8.75, 2.50, 1.36, 9.37, 3.68, 2.72, 3.47, 4.69, 9.47, 9.02, 7.81, 4.57, 7.45, 2.08, 8.39, 1.39, 1.61, 7.08, 8.79, 1.37, 4.09, 8.54, 3.97, 7.79, 6.19, 3.16, 9.48, 8.10, 6.12, 6.68, 1.71, 6.92, 7.20, 6.61, 3.28, 8.52, 9.59, 8.70, 4.55, 8.64, 1.82, 3.46, 6.25, 9.72, 6.12, 6.17, 9.04, 9.97, 5.53, 7.98, 4.18, 1.75, 9.61, 3.62, 6.87, 8.16, 1.21, 8.62, 4.51, 1.25, 7.73, 7.40, 7.76, 4.30, 7.29, 4.79, 2.21, 5.04, 5.58, 3.88, 7.30, 6.86, 7.53, 6.03, 6.42, 3.30, 7.50, 2.96, 5.17, 8.99, 4.58, 3.67, 3.34, 7.81, 7.99, 3.71, 7.09, 4.08, 5.59, 4.22, 2.54, 2.02, 5.23, 6.79, 5.18, 8.50, 2.36, 5.19, 8.14, 1.06, 3.33, 5.58, 6.33, 7.35, 5.34, 8.42, 3.87, 6.01, 3.88, 7.84, 6.99, 8.53, 4.35, 4.92, 4.34, 3.12, 9.72, 5.97, 8.03, 1.93, 6.53, 3.48, 1.35, 6.33, 7.53, 2.67, 7.16, 4.76, 3.45, 5.41, 4.67, 5.20, 2.30, 8.08, 4.15, 9.44, 7.09, 2.04, 1.07, 6.62, 6.37, 7.51, 5.27, 5.71, 7.83, 1.40, 3.58, 4.93, 3.65, 7.64, 8.21, 7.92, 9.45, 7.36, 5.33, 3.81, 5.68, 5.09, 2.69, 2.68, 9.85, 9.12, 1.73, 5.85, 9.94, 9.86, 9.30, 7.95, 3.60, 3.60, 3.81, 6.30, 3.89, 1.14, 6.45, 4.78, 3.88, 7.79, 9.29, 6.32, 2.83, 3.27, 8.65, 3.08, 3.99, 6.08, 3.33, 8.86, 8.69, 9.30, 1.82, 1.99, 6.14, 1.31, 1.52, 5.87, 6.98, 9.76, 1.10, 7.13, 6.49, 1.94, 8.67, 3.79, 6.40, 8.51, 1.96, 5.34, 7.86, 5.13, 9.89, 2.33, 5.05, 5.44, 7.12, 6.05, 5.57, 6.92, 1.61, 1.98, 6.52, 6.17, 2.97, 5.99, 3.46, 7.90, 6.50, 7.17, 9.69, 1.97, 4.49, 2.11, 8.88, 6.45, 5.76, 5.90, 6.34, 8.05, 2.74, 7.41, 5.21, 6.71, 5.11, 9.16, 9.06, 2.22, 2.32, 3.01, 6.96, 4.71, 6.23, 6.28, 3.44, 2.21, 9.35, 4.59, 9.61, 6.93, 9.87, 1.03, 3.28, 4.53, 3.42, 6.69, 4.72, 8.13, 3.01, 3.87, 3.59, 8.80, 4.80, 1.56, 9.31, 7.33, 5.50, 5.82, 9.12, 1.45, 7.32, 1.98, 6.06, 9.62, 6.48, 6.24, 3.13, 2.13, 2.74, 1.01, 2.49, 5.31, 5.46, 6.49, 7.31, 3.41, 9.31, 5.27, 8.82, 5.58, 2.79, 6.43, 3.40, 1.92, 2.15, 8.66, 5.31, 7.71, 9.87, 3.72, 7.59, 1.12, 6.10, 4.68, 4.36, 6.55, 9.46, 8.19, 2.42, 6.78, 7.74, 2.12, 1.72, 5.92, 8.39, 3.16, 9.69, 3.25, 5.45, 9.43, 4.58, 1.12, 4.62, 4.21, 7.42, 3.19, 2.31, 3.65, 3.74, 1.40, 8.77, 8.70, 9.25, 6.75, 2.00, 8.66, 6.54, 7.39, 7.22, 7.58, 6.88, 2.78, 8.47, 8.27, 6.17, 1.92, 2.20, 6.98, 9.32, 3.17, 7.70, 9.15, 9.07, 7.33, 2.10, 5.74, 1.66, 4.96, 9.59, 7.11, 4.51, 3.66, 2.44, 7.62, 6.72, 1.16, 9.14, 4.99, 5.70, 3.30, 7.15, 1.80, 6.60, 6.37, 6.64, 3.19, 8.46, 6.96, 4.64, 1.96, 4.02, 5.61, 3.93, 8.66, 8.06, 5.39, 9.10, 8.26, 3.31, 3.73, 5.01, 8.28, 3.10, 9.44, 2.36, 3.90, 9.27, 1.69, 6.98, 3.51, 1.33, 9.25, 8.91, 4.90, 5.68, 3.07, 7.97, 2.70, 5.38, 4.76, 1.64, 7.50, 3.86, 7.88, 7.54, 1.78, 1.38, 2.48, 4.79, 1.99, 9.09, 2.72, 7.92, 4.74, 4.52, 1.29, 1.43, 7.83, 1.07, 4.86, 8.44, 7.32, 4.12, 4.48, 2.38, 6.83, 8.40, 6.38, 7.02, 6.78, 5.96, 5.73, 7.99, 8.08, 1.62, 9.95, 8.75, 2.85, 8.72, 4.38, 1.19, 8.04, 5.62, 3.69, 3.04, 9.42, 6.31, 1.01, 7.93, 6.33, 2.54, 9.97, 2.49, 3.48, 9.34, 3.85, 7.86, 6.67, 7.03, 8.57, 5.79, 1.12, 7.79, 9.88, 3.45, 9.01, 7.88, 9.96, 2.52, 5.46, 8.94, 4.44, 5.14, 2.76, 7.31, 5.24, 3.37, 2.14, 8.79, 2.11, 9.72, 9.46, 9.20, 1.36, 1.61, 1.81, 4.92, 2.56, 6.66, 3.97, 6.47, 5.08, 3.09, 4.73, 2.57, 7.14, 9.45, 8.20, 1.23, 5.28, 4.55, 4.90, 3.74, 4.65, 9.26, 8.37, 9.80, 7.39, 5.65, 5.78, 5.29, 1.92, 7.35, 4.45, 4.64, 6.09, 4.62, 2.10, 4.24, 6.36, 6.28, 6.90, 4.83, 3.22, 1.40, 6.67, 1.60, 7.28, 2.45, 9.95, 9.77, 3.77, 4.00, 1.77, 6.64, 6.34, 8.65, 2.63, 6.32, 7.02, 8.78, 4.02, 6.56, 9.11, 4.12, 6.82, 4.62, 1.23, 2.92, 4.91, 6.59, 4.71, 4.06, 4.08, 2.07, 2.06, 7.04, 9.52, 8.94, 9.83, 7.25, 5.15, 7.87, 1.49, 10.00, 5.90, 6.48, 3.22, 7.56, 3.98, 5.20, 2.96, 6.25, 3.98, 7.07, 6.02, 5.51, 5.30, 3.94, 1.57, 1.68, 1.51, 2.75, 2.43, 5.22, 4.84, 7.60, 8.56, 9.50, 7.10, 1.76, 8.07, 3.70, 8.08, 6.12, 7.94, 9.01, 2.82, 8.14, 2.92, 5.34, 2.39, 8.40, 3.35, 7.21, 2.67, 4.16, 2.25, 5.49, 2.39, 6.14, 4.08, 4.39, 4.29, 9.03, 8.89, 9.19, 3.79, 4.98, 1.90, 5.07, 8.25, 4.60, 2.43, 6.26, 7.88, 2.60, 3.76, 2.66, 9.50, 9.21, 2.02, 5.41, 6.89, 3.80, 8.68, 3.85, 4.31, 3.27, 4.30, 7.73, 9.85, 8.16, 5.74, 8.11, 5.61, 8.17, 7.57, 2.70, 5.77, 5.26};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    // printf("Sorted Array: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%.2f ", arr[i]);
    // }
    return 0;
}

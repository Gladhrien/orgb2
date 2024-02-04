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
    float arr[] = {4.62, 4.90, 1.88, 5.96, 8.13, 5.58, 7.24, 8.99, 8.62, 4.06, 4.11, 3.44, 8.85, 8.05, 1.12, 1.26, 7.32, 7.80, 4.28, 9.56, 3.01, 6.19, 2.61, 7.85, 6.69, 7.33, 5.64, 1.45, 6.21, 2.73, 1.50, 5.14, 5.62, 4.18, 8.46, 3.25, 6.56, 6.05, 9.63, 6.42, 4.46, 2.90, 9.68, 3.39, 9.43, 4.66, 2.94, 3.21, 7.45, 7.88, 6.74, 1.98, 9.89, 7.26, 2.55, 7.07, 2.09, 3.93, 8.57, 7.42, 4.88, 5.83, 8.24, 3.40, 9.07, 7.66, 7.56, 6.65, 8.39, 9.03, 3.53, 6.55, 3.79, 3.24, 2.60, 5.72, 3.41, 3.14, 5.88, 3.30, 5.80, 5.41, 2.50, 2.46, 8.20, 7.08, 9.85, 9.66, 6.11, 5.61, 5.77, 7.49, 4.41, 8.34, 2.63, 9.47, 7.19, 8.31, 1.89, 7.54, 2.76, 3.87, 5.42, 1.71, 1.77, 1.33, 2.26, 3.56, 9.46, 8.22, 2.43, 7.98, 4.53, 4.43, 7.30, 4.67, 7.92, 1.23, 6.00, 3.49, 9.29, 1.96, 5.38, 1.11, 4.54, 4.73, 2.27, 9.39, 9.17, 1.16, 1.48, 2.28, 2.29, 8.40, 6.19, 8.59, 5.08, 2.33, 6.78, 6.66, 5.38, 4.19, 9.05, 2.80, 3.25, 1.90, 9.92, 3.98, 9.61, 8.35, 4.74, 4.24, 5.24, 3.60, 7.06, 9.65, 8.21, 3.82, 8.82, 4.27, 7.70, 8.18, 5.89, 4.48, 2.19, 2.45, 3.59, 8.16, 5.53, 2.62, 3.02, 7.12, 9.25, 3.77, 6.28, 9.42, 7.62, 2.39, 5.34, 5.42, 6.87, 2.13, 2.59, 3.89, 1.45, 8.69, 5.68, 3.06, 5.56, 2.35, 8.09, 7.57, 1.80, 4.68, 3.58, 9.40, 5.59, 3.71, 6.61, 5.80, 1.20, 1.64, 2.25, 2.46, 7.09, 5.65, 1.17, 1.85, 5.70, 6.44, 5.82, 2.20, 5.47, 7.94, 4.13, 7.78, 6.47, 6.45, 4.64, 8.05, 3.51, 7.38, 6.37, 3.69, 7.04, 9.50, 7.66, 2.04, 3.05, 7.13, 2.72, 1.20, 4.07, 8.61, 8.00, 6.17, 5.21, 2.69, 2.16, 6.17, 7.46, 6.50, 4.19, 8.52, 1.72, 4.10, 4.75, 1.52, 5.41, 6.90, 9.52, 1.28, 8.98, 3.92, 8.30, 6.35, 6.80, 6.29, 5.15, 6.36, 1.62, 3.59, 8.72, 8.30, 9.98, 6.58, 1.85, 8.12, 4.15, 2.45, 4.12, 2.15, 7.53, 6.51, 6.85, 9.54, 2.54, 5.18, 3.95, 8.96, 9.16, 4.22, 9.83, 9.48, 1.31, 2.87, 3.32, 4.15, 5.71, 5.29, 2.07, 8.35, 5.52, 9.83, 8.84, 3.48, 4.77, 3.32, 6.14, 3.40, 3.04, 4.95, 8.97, 9.97, 4.08, 2.66, 7.11, 5.02, 8.97, 7.58, 8.91, 1.83, 9.60, 1.32, 3.00, 2.78, 7.64, 9.13, 9.79, 5.88, 6.93, 3.51, 9.56, 9.81, 4.81, 6.84, 6.77, 1.46, 6.92, 5.67, 7.35, 1.11, 1.46, 5.84, 8.04, 6.99, 7.30, 9.54, 3.77, 2.39, 4.19, 2.02, 5.05, 1.56, 3.11, 2.56, 3.58, 9.23, 6.05, 1.07, 1.08, 5.55, 4.60, 3.16, 7.18, 5.27, 5.08, 9.16, 4.31, 4.25, 3.86, 7.19, 7.04, 1.19, 4.38, 3.84, 8.87, 1.31, 2.49, 4.85, 3.21, 7.79, 5.11, 4.53, 4.85, 5.12, 3.75, 7.99, 8.23, 4.35, 2.41, 4.14, 9.41, 5.30, 4.33, 2.84, 2.70, 6.72, 6.60, 4.45, 1.03, 1.04, 6.29, 8.80, 3.74, 5.69, 5.83, 6.83, 7.88, 2.55, 4.82, 2.21, 4.83, 8.53, 3.55, 2.95, 9.38, 1.98, 5.91, 2.99, 4.58, 4.25, 1.47, 2.23, 8.72, 7.28, 8.76, 7.71, 9.87, 5.67, 3.28, 3.96, 7.54, 5.06, 7.93, 5.16, 2.20, 5.11, 4.05, 2.44, 2.95, 7.51, 8.70, 6.79, 1.22, 8.56, 8.16, 1.95, 6.66, 3.83, 8.79, 6.33, 5.79, 6.07, 6.64, 8.68, 8.09, 2.23, 6.48, 3.29, 8.37, 7.23, 4.38, 6.34, 2.03, 7.90, 4.36, 1.67, 8.09, 10.00, 3.65, 4.87, 2.37, 5.09, 8.44, 7.86, 7.07, 1.23, 6.98, 3.61, 1.52, 7.84, 8.27, 5.21, 3.86, 9.90, 8.80, 3.44, 4.55, 7.52, 3.05, 2.52, 4.44, 7.89, 5.04, 3.71, 8.10, 1.65, 3.10, 6.80, 1.74, 7.15, 6.64, 9.59, 6.10, 1.79, 9.23, 2.98, 4.42, 5.26, 1.78, 7.43, 2.73, 3.90, 1.75, 5.20, 1.63, 3.93, 3.62, 4.33, 1.73, 7.55, 6.84, 5.61, 3.49, 8.51, 8.47, 3.10, 7.14, 1.91, 7.65, 7.60, 6.72, 1.01, 5.85, 6.01, 7.56, 8.42, 4.47, 3.74, 9.62, 3.17, 9.96, 1.07, 9.37, 6.48, 5.49, 9.04, 9.30, 7.20, 6.40, 9.36, 1.26, 6.82, 2.79, 4.60, 9.27, 5.82, 8.69, 9.51, 9.06, 3.36, 6.08, 5.01, 1.17, 6.15, 4.86, 6.18, 9.91, 9.84, 1.86, 7.50, 3.62, 8.99, 5.63, 7.39, 9.93, 7.00, 1.32, 8.63, 5.75, 7.71, 9.01, 5.69, 2.00, 2.11, 9.51, 3.61, 6.02, 1.59, 2.54, 9.47, 5.58, 3.42, 3.81, 9.68, 8.04, 3.41, 7.09, 4.20, 7.44, 3.47, 3.35, 6.21, 8.13, 4.23, 4.90, 4.62, 2.11, 4.56, 5.33, 7.56, 1.66, 5.07, 3.94, 7.73, 4.72, 7.22, 4.97, 4.69, 3.57, 1.49, 7.61, 9.17, 6.32, 4.40, 3.23, 2.78, 4.39, 7.97, 8.37, 9.53, 5.56, 7.00, 8.86, 8.84, 2.47, 7.34, 2.20, 3.09, 7.41, 8.91, 8.20, 3.03, 9.69, 2.10, 3.79, 2.49, 4.94, 1.91, 6.14, 9.76, 1.59, 8.93, 1.05, 2.18, 6.97, 8.55, 5.62, 9.94, 1.29, 8.06, 1.69, 4.97, 6.63, 5.65, 3.92, 2.68, 1.69, 3.48, 2.81, 8.32, 5.13, 8.71, 1.60, 1.50, 5.91, 8.66, 2.02, 2.77, 4.63, 4.58, 9.31, 5.23, 3.85, 1.63, 5.39, 7.73, 8.47, 9.13, 7.52, 6.25, 5.35, 4.97, 6.63, 9.36, 9.49, 5.86, 5.63, 6.74, 1.67, 3.80, 6.81, 3.34, 6.75, 2.99, 4.32, 4.59, 2.74, 6.13, 1.84, 2.14, 6.44, 5.00, 7.71, 7.29, 6.15, 3.09, 5.51, 7.40, 2.34, 8.17, 5.50, 1.86, 5.65, 7.21, 8.44, 2.91, 2.65, 2.91, 2.38, 7.47, 7.98, 3.50, 4.38, 7.69, 1.29, 8.29, 2.16, 6.76, 3.06, 1.61, 2.42, 5.87, 1.53, 3.64, 4.39, 7.76, 4.61, 9.44, 8.98, 1.64, 2.05, 7.23, 8.28, 4.30, 2.47, 3.45, 6.27, 1.56, 2.64, 8.35, 1.36, 8.57, 8.92, 7.27, 5.87, 9.19, 3.50, 2.30, 3.26, 9.92, 6.01, 6.52, 9.72, 5.98, 4.65, 5.26, 5.46, 4.03, 7.20, 8.08, 9.58, 9.93, 8.71, 4.21, 1.95, 6.82, 9.04, 4.78, 1.00, 2.64, 5.77, 1.79, 2.52, 3.52, 1.68, 7.90, 3.53, 2.56, 8.74, 9.69, 6.53, 5.49, 7.75, 8.69, 5.36, 8.41, 5.39, 9.82, 8.02, 1.92, 7.13, 6.29, 9.74, 1.18, 8.01, 5.29, 2.83, 2.82, 7.58, 8.62, 6.09, 4.65, 2.01, 7.24, 9.47, 4.70, 1.18, 9.84, 3.40, 7.57, 3.24, 9.74, 2.61, 2.53, 8.54, 7.90, 1.13, 3.12, 6.61, 5.88, 6.59, 9.29, 5.43, 9.76, 2.32, 2.91, 1.44, 7.04, 4.84, 2.25, 4.56, 7.82, 4.13, 4.07, 8.54, 5.40, 1.25, 4.73, 1.55, 9.34, 5.25, 1.68, 9.59, 6.03, 9.85, 2.19, 1.87, 3.46, 4.37, 3.73, 2.96, 6.04, 1.60, 8.96, 8.86, 2.97, 5.81, 1.61, 2.93, 5.74, 9.86, 5.51, 8.81, 9.61, 6.59, 3.55, 6.37, 5.91, 1.97, 1.79, 8.18, 2.18, 7.22, 4.08, 4.26, 5.32, 3.98, 6.99, 8.08, 9.71, 2.07, 8.83, 3.97, 9.35, 8.36, 6.47, 9.66, 3.02, 7.38, 1.80, 8.26, 8.40, 3.48, 6.74, 5.57, 1.12, 1.82, 9.32, 9.22, 1.23, 7.59, 9.28, 4.56, 1.27, 8.45, 7.14, 3.56, 8.70, 6.81, 1.94, 1.15, 2.74, 1.76, 4.55, 6.95, 5.15, 4.11, 7.25, 1.74, 3.14, 8.14, 6.91, 5.98, 6.52, 3.94, 2.89, 4.52, 8.39, 2.48, 3.66, 9.97, 9.01, 6.90, 7.22, 5.33, 5.30, 2.01, 8.27, 6.24, 8.95, 6.76, 3.78, 7.05, 6.57, 2.51, 9.26, 9.21, 6.54, 5.10, 8.54, 1.54, 2.65, 4.74, 8.42, 8.11, 3.19, 4.75, 8.05, 4.83, 2.65, 4.35, 1.78, 2.36, 7.55, 2.40, 3.89, 7.48, 8.10, 9.59, 9.81, 3.70, 4.57, 2.97, 9.98, 5.93, 9.70, 8.84, 5.44, 2.95, 6.56, 9.14, 4.99, 1.43, 5.04, 9.08, 5.05, 4.49, 5.48, 7.03, 7.62, 4.34, 1.98, 4.47, 8.39, 7.34, 1.06, 4.06, 2.42, 9.66, 2.05, 3.60, 3.78, 5.79, 3.76, 4.89, 1.70, 7.83, 6.67, 6.03, 4.49, 7.60, 3.81, 7.91, 3.13, 2.31, 9.48, 9.35, 2.43, 5.06, 2.61, 6.94, 9.00, 2.27, 8.48, 1.90, 6.49, 3.17, 9.80, 7.67, 5.89, 3.66, 6.46, 4.31, 1.00, 9.25, 8.38, 8.75, 8.43, 1.73, 6.24, 7.08, 3.59, 1.15, 1.40, 6.25, 5.44, 2.35, 8.15, 5.66, 8.27, 9.73, 8.61, 6.92, 1.54, 4.22, 8.65, 4.87, 7.40, 9.10, 2.39, 7.83, 6.33, 1.99, 3.95, 6.13, 2.29, 6.96, 5.94, 1.26, 9.18, 9.70, 2.35, 8.60, 9.34, 9.00, 2.31, 1.81, 5.70, 5.78, 6.69, 8.76, 4.67, 1.62, 3.82, 4.29, 4.14, 4.82, 2.84, 9.45, 8.20, 3.20, 7.77, 4.76, 9.72, 3.00, 8.83, 9.70, 5.99, 8.60, 5.40, 6.20, 6.30, 1.48, 3.76, 4.22, 7.63, 2.01, 9.88, 2.88, 1.76, 4.54, 9.27, 3.08, 2.37, 4.96, 4.99, 1.19, 4.93, 7.42, 8.66, 4.57, 6.92, 8.89, 4.04, 8.74, 5.55, 1.36, 1.34, 9.38, 4.20, 1.03, 3.80, 7.80, 9.93, 9.55, 9.39, 8.50, 7.46, 3.84, 2.22, 1.65, 7.17, 7.10, 8.24, 5.69, 1.94, 8.92, 5.16, 7.31, 4.75, 8.82, 8.21, 3.18, 7.92, 9.33, 7.35, 7.96, 1.09, 7.41, 4.76, 5.37, 5.35, 1.35, 7.94, 4.04, 4.80, 4.82, 4.30, 2.60, 7.47, 6.03, 2.79, 6.70, 6.22, 8.90, 6.53, 4.51, 1.88, 4.32, 9.65, 2.50, 1.07, 7.02, 6.31, 7.78, 3.36, 4.03, 9.26, 8.50, 7.16, 3.54, 5.97, 2.12, 2.15, 7.15, 7.36, 7.83, 9.40, 6.16, 5.31, 9.15, 3.31, 1.93, 1.25, 8.52, 5.84, 4.61, 7.19, 2.81, 6.57, 2.57, 8.81, 6.20, 2.53, 3.75, 7.45, 1.49, 7.21, 6.27, 1.14, 7.67, 1.58, 4.92, 2.16, 1.96, 2.89, 3.20, 7.01, 7.99, 5.66, 7.37, 7.41, 1.97, 5.01, 1.51, 7.39, 4.68, 4.21, 8.75, 8.49, 1.99, 8.00, 8.65, 3.38, 8.43, 4.16, 9.20, 2.85, 2.75, 8.45, 1.28, 5.03, 4.71, 8.78, 9.46, 6.33, 4.86, 1.05, 9.80, 6.55, 6.06, 8.19, 3.01, 4.17, 8.14, 1.82, 3.68, 3.13, 4.95, 2.28, 1.38, 9.03, 6.70, 2.36, 1.75, 8.25, 2.72, 7.64, 1.49, 9.12, 9.43, 3.07, 2.24, 5.25, 7.72, 6.62, 6.46, 3.38, 2.33, 5.28, 2.94, 5.09, 3.88, 1.39, 6.25, 6.07, 6.26, 1.14, 5.50, 8.46, 6.38, 9.57, 3.33, 9.78, 7.72, 8.88, 1.66, 3.64, 8.94, 4.08, 9.57, 1.52, 9.49, 9.12, 9.52, 8.33, 1.92, 9.75, 5.36, 2.76, 3.37, 3.36, 8.59, 1.40, 4.78, 2.68, 9.42, 8.17, 7.97, 3.18, 8.12, 9.02, 2.66, 3.28, 9.74, 9.88, 4.64, 8.12, 3.92, 4.00, 5.22, 1.41, 8.33, 7.60, 7.67, 3.37, 7.16, 6.44, 7.49, 3.16, 2.05, 6.85, 7.37, 3.99, 7.50, 6.70, 9.02, 7.30, 1.10, 6.54, 8.28, 3.90, 1.72, 3.10, 3.45, 5.39, 1.24, 9.87, 5.27, 6.88, 2.80, 7.81, 8.63, 3.47, 1.71, 6.66, 5.72, 9.20, 8.93, 4.02, 6.96, 7.45, 9.67, 2.46, 5.54, 2.76, 8.03, 2.12, 9.11, 2.69, 6.40, 2.86, 2.67, 3.30, 9.41, 7.86, 2.71, 9.31, 2.17, 3.69, 2.67, 4.91, 7.61, 8.72, 8.23, 5.90, 1.90, 1.81, 6.22, 3.88, 3.43, 2.24, 1.35, 2.26, 4.12, 4.59, 9.63, 2.59, 5.34, 6.73, 9.28, 4.24, 7.11, 1.04, 6.65, 9.99, 5.42, 6.94, 7.52, 4.71, 7.31, 7.03, 3.08, 6.98, 5.45, 3.62, 8.85, 8.36, 3.72, 1.06, 5.24, 3.06, 2.70, 4.79, 3.23, 2.31, 5.99, 4.49, 2.93, 5.97, 5.95, 9.78, 2.10, 3.39, 8.50, 6.89, 3.77, 7.51, 4.53, 4.44, 3.85, 5.71, 6.39, 8.32, 8.07, 3.15, 1.33, 6.17, 1.41, 4.23, 5.72, 7.29, 3.91, 4.92, 7.36, 5.64, 9.44, 2.21, 5.03, 7.18, 9.15, 4.00, 1.44, 8.64, 1.42, 9.06, 5.75, 6.47, 4.26, 6.51, 4.29, 1.30, 1.60, 3.96, 5.28, 8.94, 2.27, 7.01, 1.77, 9.67, 5.14, 2.38, 1.83, 9.40, 6.02, 7.64, 7.70, 9.33, 6.36, 5.54, 5.57, 8.43, 9.55, 6.35, 8.41, 8.19, 7.44, 6.28, 6.71, 7.06, 9.77, 5.23, 8.25, 9.05, 8.77, 4.28, 4.91, 7.69, 1.43, 5.00, 5.95, 7.63, 4.60, 1.68, 5.73, 9.09, 7.53, 6.93, 6.60, 4.90, 6.12, 4.42, 3.22, 2.03, 9.96, 1.24, 1.01, 9.60, 6.78, 1.57, 6.41, 4.18, 2.14, 2.85, 8.91, 1.70, 2.09, 6.30, 8.77, 9.55, 5.12, 9.08, 4.27, 2.17, 5.47, 9.96, 1.10, 8.53, 5.52, 4.46, 4.81, 4.96, 5.96, 5.81, 2.88, 7.81, 7.74, 3.22, 6.86, 5.59, 1.09, 4.80, 5.73, 3.26, 2.48, 1.37, 8.95, 9.53, 7.38, 2.50, 2.44, 6.96, 6.41, 7.26, 2.80, 1.84, 4.45, 1.19, 5.09, 9.10, 9.81, 9.89, 9.29, 6.18, 6.43, 2.86, 7.93, 2.63, 2.90, 5.45, 5.76, 7.68, 1.02, 1.87, 6.78, 8.11, 9.77, 4.89, 6.23, 6.39, 6.89, 1.15, 8.67, 3.51, 3.85, 2.06, 6.23, 6.49, 6.31, 3.04, 5.78, 8.89, 2.62, 5.13, 9.36, 7.32, 3.67, 7.87, 9.82, 7.96, 3.68, 4.98, 1.93, 8.79, 6.73, 4.15, 5.20, 9.07, 9.91, 6.62, 2.22, 3.25, 5.12, 7.10, 4.98, 2.40, 7.74, 7.68, 6.04, 6.42, 7.48, 7.75, 5.76, 5.95, 5.35, 7.33, 4.36, 3.70, 1.75, 8.67, 4.34, 7.95, 7.11, 1.86, 4.45, 9.44, 7.12, 6.11, 4.40, 5.84, 3.44, 8.03, 3.96, 4.04, 5.22, 7.59, 1.89, 7.85, 5.54, 4.34, 3.83, 4.09, 5.19, 3.29, 5.28, 1.21, 1.04, 3.46, 6.67, 3.63, 6.62, 8.01, 7.05, 4.50, 1.13, 8.56, 9.10, 9.24, 8.07, 3.55, 7.77, 7.79, 7.82, 8.88, 4.41, 8.49, 3.74, 6.91, 8.02, 9.73, 8.16, 2.58, 1.38, 6.79, 8.78, 5.60, 3.81, 7.27, 4.64, 3.63, 9.22, 4.86, 7.76, 9.51, 1.82, 4.41, 5.92, 5.61, 7.87, 4.37, 1.94, 4.43, 2.87, 6.06, 8.88, 3.31, 1.34, 9.86, 1.58, 5.46, 9.64, 2.24, 9.32, 1.41, 7.43, 1.51, 3.17, 3.03, 5.80, 8.99, 9.30, 8.64, 6.75, 5.86, 9.75, 2.08, 8.55, 7.86, 9.78, 1.39, 9.94, 8.51, 1.53, 2.54, 1.37, 6.89, 3.19, 6.14, 5.16, 3.72, 8.38, 2.92, 3.73, 3.15, 2.99, 1.30, 5.53, 1.64, 6.55, 5.19, 8.58, 3.12, 7.79, 7.97, 7.94, 9.25, 9.95, 7.34, 3.11, 1.57, 2.71, 9.09, 4.52, 1.08, 2.32, 5.18, 4.50, 2.30, 2.04, 2.84, 1.55, 5.68, 4.16, 3.29, 5.58, 3.87, 5.74, 9.90, 7.08, 4.66, 9.58, 9.89, 4.70, 2.98, 4.26, 2.13, 8.58, 3.14, 8.46, 5.24, 1.42, 5.32, 6.95, 5.92, 6.36, 8.87, 1.11, 6.08, 4.93, 2.42, 4.84, 3.21, 6.09, 3.02, 7.25, 6.32, 3.97, 4.71, 3.54, 6.34, 9.64, 6.81, 6.58, 7.17, 3.66, 6.06, 8.26, 4.11, 9.99, 2.72, 7.91, 4.05, 7.65, 3.91, 8.90, 8.76, 6.71, 6.51, 2.09, 4.77, 1.30, 5.76, 9.21, 4.01, 4.00, 7.28, 1.02, 3.52, 8.15, 8.34, 4.88, 4.94, 8.61, 4.01, 2.58, 2.77, 3.07, 4.79, 7.49, 5.31, 4.02, 7.15, 9.06, 4.63, 2.51, 7.89, 4.67, 4.79, 5.02, 8.24, 6.21, 4.17, 3.33, 2.08, 2.75, 9.21, 6.97, 5.37, 1.71, 2.58, 6.87, 9.85, 8.68, 9.19, 5.01, 6.59, 5.46, 6.43, 3.70, 5.07, 1.38, 6.83, 6.86, 8.95, 8.22, 6.45, 8.31, 2.41, 8.48, 6.10, 7.75, 7.00, 6.40, 4.69, 3.65, 8.01, 2.83, 8.29, 4.94, 6.88, 3.99, 8.65, 9.50, 5.10, 2.12, 1.21, 5.17, 9.71, 9.62, 9.24, 9.95, 2.69, 7.26, 9.37, 5.43, 9.11, 5.05, 6.50, 1.47, 9.18, 9.79, 3.42, 3.43, 3.27, 6.16, 6.85, 6.00, 8.31, 5.20, 2.96, 2.34, 2.92, 5.94, 7.95, 8.73, 4.30, 3.34, 5.50, 4.72, 9.32, 2.88, 4.48, 1.27, 5.85, 9.03, 9.62, 6.10, 5.99, 2.06, 7.02, 6.68, 8.57, 3.27, 6.12, 9.14, 1.45, 3.89, 8.73, 5.93, 5.48, 8.06, 3.35, 6.77, 3.67, 4.51, 9.14, 1.34, 2.82, 6.68, 8.80, 1.22, 1.56, 7.84, 9.18, 2.57, 9.45, 6.38, 1.16, 4.10, 3.57, 5.60, 2.00, 5.31, 4.09, 5.90, 5.17, 6.26, 3.33};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    // printf("Sorted Array: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%.2f ", arr[i]);
    // }
    return 0;
}

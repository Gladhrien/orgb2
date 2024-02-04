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
    float arr[] = {5.39, 7.30, 9.99, 6.57, 1.94, 9.41, 5.11, 6.59, 7.39, 7.81, 8.16, 2.67, 7.98, 6.82, 4.26, 9.49, 5.63, 5.43, 6.76, 8.80, 4.72, 5.08, 4.21, 7.43, 1.44, 3.28, 2.40, 6.84, 4.01, 2.52, 3.93, 2.23, 7.15, 3.78, 3.82, 3.84, 5.09, 2.96, 6.10, 4.03, 4.74, 6.44, 6.30, 7.03, 8.14, 6.32, 6.22, 4.43, 3.07, 7.36, 9.19, 4.97, 9.37, 8.23, 8.78, 9.70, 2.10, 6.84, 3.60, 6.49, 9.84, 8.54, 8.43, 2.21, 2.15, 1.89, 4.52, 6.75, 4.10, 4.98, 9.52, 7.52, 9.90, 5.05, 9.06, 5.78, 6.74, 8.06, 1.80, 9.28, 6.18, 2.80, 7.43, 9.31, 3.55, 8.77, 1.22, 5.92, 3.79, 9.92, 7.72, 2.78, 3.68, 1.08, 3.83, 8.68, 5.18, 9.14, 4.69, 7.47, 5.90, 8.96, 2.70, 3.53, 5.52, 8.62, 6.57, 8.97, 9.39, 5.14, 7.56, 1.16, 9.87, 6.68, 7.85, 2.75, 9.96, 1.88, 8.95, 7.85, 9.65, 7.45, 8.92, 9.16, 2.07, 2.90, 6.23, 3.87, 4.73, 4.97, 3.11, 8.47, 4.49, 1.27, 5.53, 6.81, 7.94, 5.83, 1.04, 3.23, 5.01, 2.48, 3.70, 7.66, 5.33, 1.60, 1.37, 9.02, 6.55, 4.27, 7.27, 6.14, 9.78, 6.11, 4.27, 1.37, 1.79, 8.28, 2.36, 2.37, 4.29, 7.48, 3.70, 4.46, 4.32, 4.98, 2.39, 9.40, 3.46, 5.27, 8.48, 5.32, 6.20, 3.13, 4.92, 5.59, 4.96, 4.74, 7.93, 5.71, 3.34, 1.94, 4.35, 3.92, 2.95, 2.43, 7.04, 5.57, 4.51, 8.56, 7.88, 3.04, 5.11, 8.49, 4.00, 9.30, 1.30, 9.58, 6.52, 9.53, 9.60, 6.35, 5.38, 9.44, 5.48, 4.64, 8.37, 1.09, 3.42, 7.24, 7.21, 7.43, 1.82, 9.90, 4.52, 9.72, 9.81, 1.23, 4.55, 5.46, 4.39, 7.11, 8.65, 8.94, 4.22, 8.18, 1.00, 2.82, 8.36, 8.88, 2.68, 2.93, 6.73, 9.40, 2.00, 6.19, 6.15, 4.10, 7.28, 8.34, 1.99, 7.90, 3.61, 3.40, 7.39, 8.96, 9.51, 5.14, 9.39, 2.52, 2.51, 5.20, 4.19, 5.84, 5.13, 9.13, 8.37, 2.20, 3.26, 5.07, 2.95, 6.67, 9.66, 8.29, 6.76, 9.45, 7.67, 3.64, 8.63, 9.10, 2.56, 6.47, 7.42, 7.26, 1.96, 4.82, 3.58, 3.73, 7.84, 5.82, 1.99, 7.80, 2.81, 7.16, 9.59, 2.98, 8.35, 1.42, 8.12, 7.08, 9.17, 1.12, 6.62, 9.45, 5.36, 2.72, 9.27, 8.15, 6.47, 4.80, 5.37, 1.44, 6.51, 1.68, 8.03, 7.13, 3.99, 7.63, 6.19, 5.78, 8.95, 9.32, 3.43, 8.93, 3.26, 5.80, 7.26, 1.89, 3.78, 5.11, 8.77, 9.43, 2.56, 5.91, 6.32, 7.29, 5.82, 4.75, 7.22, 2.18, 4.54, 2.38, 6.45, 5.74, 5.76, 6.58, 2.08, 3.90, 3.28, 9.47, 5.17, 8.19, 8.45, 6.34, 1.63, 5.58, 6.85, 3.06, 7.87, 7.82, 4.37, 7.77, 2.39, 2.29, 9.67, 3.88, 9.97, 6.14, 3.80, 9.35, 3.05, 9.99, 7.30, 2.03, 9.02, 8.47, 6.01, 7.04, 1.70, 7.32, 3.21, 1.51, 4.94, 1.60, 9.18, 3.49, 1.77, 2.43, 5.54, 5.51, 6.12, 7.53, 3.01, 1.53, 1.47, 4.13, 1.81, 9.79, 4.75, 1.14, 5.68, 2.29, 6.79, 7.45, 7.96, 7.99, 6.65, 7.15, 5.69, 8.89, 8.76, 9.40, 3.91, 2.89, 1.62, 1.13, 2.92, 4.18, 7.58, 9.50, 3.17, 7.04, 2.11, 2.09, 7.86, 1.73, 9.15, 2.87, 7.10, 3.22, 4.20, 4.34, 9.54, 2.88, 5.42, 4.59, 2.79, 2.54, 5.23, 1.24, 5.38, 4.28, 2.59, 8.24, 2.45, 2.19, 1.49, 7.82, 9.13, 6.00, 4.18, 8.08, 7.94, 5.26, 6.67, 6.82, 8.69, 4.51, 9.50, 5.21, 5.25, 4.69, 1.13, 7.55, 6.07, 3.43, 8.26, 9.17, 4.11, 8.86, 9.49, 5.13, 6.95, 7.75, 1.15, 6.89, 8.98, 9.85, 2.10, 6.45, 4.47, 9.08, 7.33, 7.88, 6.41, 1.10, 6.95, 7.84, 3.47, 6.87, 8.09, 3.63, 8.22, 3.66, 9.73, 8.68, 5.72, 1.17, 1.36, 1.56, 3.92, 4.92, 9.51, 5.93, 8.90, 8.26, 7.09, 3.77, 9.46, 8.08, 7.89, 6.11, 1.34, 3.77, 6.00, 6.75, 2.45, 4.30, 8.52, 2.91, 3.98, 2.41, 9.93, 9.77, 8.50, 4.87, 1.50, 6.61, 4.25, 8.50, 8.39, 5.60, 7.58, 9.86, 7.27, 4.45, 2.85, 5.53, 8.89, 8.18, 5.93, 4.80, 1.66, 6.06, 2.84, 7.39, 2.57, 9.38, 7.79, 3.72, 4.05, 7.32, 2.17, 5.16, 4.81, 3.35, 4.91, 2.90, 5.65, 9.24, 8.67, 6.31, 6.74, 6.90, 4.00, 2.01, 2.30, 4.57, 8.13, 8.75, 4.58, 4.42, 1.87, 6.88, 9.95, 3.16, 7.70, 3.59, 4.39, 7.76, 4.40, 6.29, 6.54, 4.06, 6.01, 5.74, 3.42, 2.26, 6.16, 9.15, 4.44, 4.37, 7.81, 7.29, 1.90, 4.91, 7.99, 3.75, 3.67, 5.03, 9.20, 9.83, 3.08, 7.00, 4.61, 8.29, 4.23, 2.01, 5.87, 1.69, 3.50, 6.94, 8.84, 3.37, 6.37, 7.78, 9.26, 9.76, 3.69, 7.03, 1.65, 7.51, 6.91, 4.08, 7.28, 4.26, 9.12, 9.61, 6.10, 2.71, 7.19, 7.95, 1.86, 3.75, 2.63, 7.01, 10.00, 2.77, 1.02, 5.65, 5.99, 9.05, 1.30, 8.60, 9.67, 4.71, 7.02, 1.81, 8.79, 9.05, 1.34, 7.35, 8.62, 1.11, 5.73, 7.74, 5.67, 1.05, 1.45, 7.10, 1.42, 3.34, 7.49, 8.51, 9.78, 6.66, 4.35, 7.60, 5.34, 7.57, 8.58, 3.85, 3.38, 1.00, 8.00, 2.18, 5.86, 7.61, 9.21, 5.44, 9.89, 6.30, 9.55, 3.73, 1.19, 1.93, 9.42, 8.73, 7.80, 1.28, 9.52, 3.96, 6.21, 4.89, 8.91, 3.57, 5.85, 1.75, 5.00, 9.74, 5.31, 9.98, 2.74, 3.44, 9.84, 5.07, 7.44, 2.13, 9.31, 7.35, 6.40, 8.64, 4.20, 2.29, 8.33, 8.41, 5.20, 1.28, 6.66, 8.67, 8.44, 6.17, 1.56, 9.46, 1.85, 7.54, 9.34, 7.56, 2.12, 8.20, 4.50, 4.59, 8.10, 6.99, 3.27, 5.16, 4.86, 8.99, 2.89, 9.30, 1.64, 2.47, 5.67, 1.17, 7.59, 2.93, 6.72, 1.78, 1.40, 2.31, 9.75, 9.23, 7.79, 3.63, 4.90, 2.11, 6.53, 3.10, 7.12, 6.08, 4.46, 6.38, 8.20, 4.94, 4.32, 2.03, 2.34, 5.66, 4.36, 3.96, 8.01, 3.97, 4.83, 7.68, 4.95, 8.23, 1.38, 6.85, 4.99, 7.47, 6.70, 2.87, 8.89, 1.35, 8.38, 9.06, 6.35, 1.05, 1.46, 6.96, 7.23, 5.44, 1.02, 8.82, 6.49, 2.50, 8.37, 6.24, 8.85, 6.55, 6.39, 2.51, 3.02, 9.85, 2.49, 7.60, 1.60, 2.27, 9.80, 6.81, 5.49, 4.48, 1.25, 8.80, 5.62, 4.12, 6.94, 9.65, 5.24, 6.61, 2.07, 3.74, 3.52, 3.38, 2.92, 8.12, 9.57, 6.74, 4.84, 9.23, 1.48, 4.67, 3.90, 8.16, 8.33, 1.17, 5.43, 2.41, 9.63, 2.14, 4.13, 8.87, 3.72, 3.09, 1.51, 6.27, 4.29, 8.64, 4.15, 6.56, 1.54, 8.99, 9.10, 2.65, 6.04, 1.06, 7.95, 6.86, 4.65, 3.86, 3.51, 9.91, 3.53, 8.56, 1.63, 8.30, 2.59, 4.88, 6.06, 9.94, 9.10, 9.41, 2.42, 9.56, 3.40, 2.11, 4.22, 1.49, 1.58, 9.09, 1.76, 3.01, 8.46, 7.50, 7.50, 8.29, 7.34, 4.38, 3.33, 4.34, 9.94, 9.04, 3.08, 7.02, 8.21, 3.15, 9.14, 8.55, 9.74, 9.83, 5.17, 6.91, 6.44, 5.93, 1.73, 9.88, 1.13, 2.20, 5.10, 3.88, 1.56, 2.44, 6.78, 7.72, 6.04, 6.87, 6.93, 3.57, 3.94, 6.22, 6.05, 4.48, 3.83, 6.36, 8.16, 4.25, 5.08, 5.61, 6.21, 2.07, 2.61, 7.97, 8.57, 4.30, 3.71, 1.55, 3.16, 6.46, 5.63, 8.61, 9.29, 5.19, 2.80, 3.87, 3.96, 8.39, 3.12, 8.41, 3.89, 5.85, 8.32, 7.09, 5.20, 8.72, 2.62, 8.66, 6.16, 9.81, 2.94, 1.04, 7.16, 9.54, 1.93, 3.64, 3.62, 9.34, 4.36, 3.60, 5.71, 6.34, 8.71, 3.19, 5.77, 5.67, 5.10, 7.47, 5.89, 1.75, 1.88, 9.43, 9.09, 5.62, 6.23, 8.17, 1.78, 9.32, 2.70, 4.17, 2.06, 7.23, 2.12, 2.99, 5.50, 8.15, 2.76, 6.83, 8.00, 6.12, 1.32, 2.04, 1.86, 3.91, 8.19, 9.27, 5.91, 3.93, 6.13, 3.33, 4.24, 3.21, 1.72, 4.77, 1.21, 9.80, 1.52, 2.62, 3.12, 8.01, 1.90, 2.26, 9.49, 8.41, 6.64, 4.47, 6.08, 1.71, 2.34, 7.51, 1.07, 5.41, 7.30, 8.74, 3.94, 4.72, 2.86, 7.86, 2.16, 1.21, 7.11, 6.01, 2.20, 1.73, 9.00, 6.02, 6.79, 2.46, 8.86, 2.88, 6.36, 6.43, 7.57, 4.33, 8.07, 3.68, 1.03, 2.59, 9.70, 9.07, 2.24, 8.10, 5.95, 2.61, 8.05, 2.54, 2.67, 1.39, 5.75, 3.95, 3.54, 6.86, 4.94, 8.46, 4.61, 1.80, 3.45, 6.33, 1.01, 4.16, 4.07, 7.65, 2.82, 3.83, 7.81, 3.89, 1.35, 3.51, 3.84, 2.28, 2.08, 9.62, 2.49, 9.01, 3.35, 5.02, 2.33, 4.05, 3.04, 9.59, 5.39, 6.93, 3.25, 5.45, 9.16, 3.61, 2.24, 8.90, 5.28, 7.09, 3.81, 1.20, 2.84, 8.55, 9.87, 2.37, 9.74, 1.94, 1.16, 8.93, 7.65, 2.64, 5.88, 8.71, 7.96, 6.89, 8.83, 7.52, 7.31, 4.41, 1.07, 3.14, 3.41, 7.12, 1.58, 4.60, 9.01, 4.62, 5.37, 7.22, 3.18, 9.44, 4.45, 8.06, 1.67, 6.36, 6.69, 3.65, 2.46, 3.32, 4.26, 2.16, 5.01, 8.17, 6.63, 9.25, 1.98, 7.14, 7.68, 6.68, 5.47, 1.43, 6.99, 7.18, 7.60, 8.33, 7.73, 8.59, 1.65, 8.81, 1.25, 8.25, 9.76, 6.17, 4.02, 7.26, 2.55, 9.66, 2.31, 4.15, 3.23, 2.73, 8.93, 3.76, 9.21, 8.75, 8.25, 7.89, 5.73, 5.18, 4.56, 8.79, 3.71, 9.61, 4.96, 8.76, 7.70, 3.24, 9.79, 4.49, 2.77, 2.04, 4.34, 5.04, 8.34, 5.77, 7.44, 4.63, 9.64, 1.79, 9.04, 6.24, 1.26, 6.54, 6.06, 8.07, 3.81, 2.03, 2.83, 9.12, 4.60, 8.72, 2.30, 4.66, 8.53, 9.62, 1.39, 6.53, 3.74, 1.43, 7.06, 5.48, 4.93, 1.31, 4.57, 2.84, 7.64, 9.69, 3.29, 7.69, 1.70, 5.98, 1.29, 5.07, 3.95, 1.72, 6.40, 4.43, 8.11, 9.31, 6.65, 1.86, 3.03, 4.07, 8.52, 9.91, 7.90, 2.42, 1.90, 4.40, 7.40, 8.24, 1.85, 3.39, 7.17, 8.42, 1.53, 3.22, 6.10, 9.20, 8.70, 1.03, 3.30, 1.41, 1.51, 2.69, 9.53, 2.32, 5.03, 4.64, 9.37, 8.04, 2.63, 8.09, 1.18, 4.51, 5.16, 3.20, 3.18, 5.69, 8.91, 5.97, 2.58, 6.83, 8.80, 3.46, 5.29, 5.41, 3.49, 5.31, 1.87, 7.48, 5.06, 8.11, 3.69, 6.88, 1.91, 5.30, 1.09, 5.94, 4.90, 7.18, 1.34, 6.63, 3.13, 3.14, 5.22, 7.37, 5.55, 8.82, 5.95, 6.87, 3.07, 9.87, 3.40, 2.91, 2.86, 7.78, 4.53, 1.23, 7.73, 3.44, 2.71, 3.19, 9.19, 8.22, 4.39, 6.09, 4.13, 3.91, 5.81, 6.31, 4.70, 3.44, 3.56, 3.48, 9.27, 6.73, 2.76, 4.24, 5.92, 5.64, 2.79, 6.14, 1.20, 6.20, 8.60, 5.68, 4.86, 2.46, 2.15, 1.32, 2.72, 5.79, 3.29, 4.65, 1.47, 4.62, 2.93, 3.53, 7.21, 1.81, 5.24, 5.30, 1.83, 5.42, 5.72, 5.09, 5.15, 2.02, 1.47, 4.53, 5.59, 2.21, 1.11, 4.16, 7.75, 6.50, 7.61, 3.86, 2.97, 1.24, 2.09, 5.21, 9.22, 9.60, 4.71, 6.61, 7.69, 5.50, 4.47, 2.73, 8.24, 4.11, 9.33, 4.06, 7.91, 8.66, 3.79, 7.83, 7.73, 3.49, 2.48, 5.80, 9.47, 2.33, 6.91, 9.18, 7.25, 3.70, 6.50, 2.80, 9.38, 6.28, 4.02, 8.07, 7.31, 9.23, 6.62, 8.63, 6.05, 9.57, 3.36, 6.25, 4.68, 2.35, 4.31, 2.23, 9.88, 8.54, 5.46, 3.39, 1.97, 9.68, 7.87, 2.65, 8.50, 8.31, 5.61, 8.53, 3.10, 6.80, 2.53, 9.71, 3.14, 4.21, 2.68, 3.01, 5.84, 2.02, 4.00, 2.67, 3.87, 9.06, 7.93, 9.35, 7.92, 7.98, 2.24, 5.94, 6.60, 9.55, 1.55, 8.78, 6.92, 1.69, 3.19, 7.34, 7.38, 3.97, 1.67, 5.40, 8.35, 4.60, 1.18, 6.33, 8.02, 5.76, 8.70, 4.41, 5.41, 9.69, 4.70, 6.53, 8.73, 7.05, 9.08, 1.19, 5.04, 3.31, 5.97, 5.57, 7.77, 8.48, 8.46, 9.82, 3.48, 2.37, 5.54, 2.55, 7.66, 9.00, 1.01, 3.47, 5.34, 5.12, 6.52, 9.79, 2.44, 1.41, 1.30, 6.07, 3.30, 7.40, 4.78, 6.29, 9.42, 6.90, 3.55, 6.83, 3.23, 1.29, 4.81, 5.64, 4.76, 5.02, 2.89, 4.55, 5.50, 6.57, 5.75, 6.42, 6.02, 3.15, 8.69, 9.70, 5.25, 3.25, 8.28, 7.97, 4.81, 1.71, 9.36, 5.06, 4.04, 1.21, 4.44, 5.52, 4.03, 6.96, 1.54, 9.98, 8.63, 5.86, 3.36, 7.92, 4.33, 6.38, 5.63, 6.77, 6.60, 9.63, 7.62, 4.04, 8.21, 6.78, 8.49, 8.32, 3.79, 1.66, 1.33, 9.86, 3.99, 9.64, 8.85, 1.52, 4.99, 3.32, 8.58, 8.05, 4.73, 6.27, 5.47, 6.56, 6.98, 1.12, 1.84, 4.66, 8.76, 8.03, 2.00, 1.15, 2.50, 1.92, 4.01, 9.03, 2.19, 1.97, 4.56, 1.95, 6.71, 6.71, 7.17, 3.59, 9.29, 7.24, 6.13, 6.80, 2.96, 9.44, 6.69, 5.00, 1.59, 1.06, 7.01, 8.59, 8.97, 5.59, 2.47, 5.98, 1.26, 7.08, 7.42, 6.42, 4.19, 4.12, 1.69, 1.91, 5.99, 7.55, 6.39, 1.27, 8.02, 7.99, 1.14, 7.41, 7.86, 8.38, 6.49, 4.85, 1.39, 1.64, 6.19, 4.58, 8.97, 9.48, 9.25, 2.28, 2.05, 4.99, 3.50, 8.67, 3.37, 5.19, 4.85, 7.91, 5.29, 5.27, 4.84, 5.66, 9.93, 1.77, 3.85, 3.41, 2.85, 2.25, 6.66, 9.61, 9.01, 4.76, 2.38, 7.00, 8.81, 3.76, 9.75, 9.11, 1.10, 3.27, 4.30, 2.81, 4.17, 7.07, 8.43, 5.55, 7.46, 1.74, 6.51, 5.45, 4.04, 2.76, 5.49, 2.99, 3.02, 3.80, 9.91, 2.75, 3.98, 3.36, 5.33, 8.59, 3.03, 1.04, 2.54, 5.83, 6.26, 9.95, 4.73, 7.62, 9.83, 4.79, 9.22, 8.13, 4.88, 5.46, 7.49, 7.38, 6.25, 4.90, 3.06, 3.82, 2.16, 7.56, 5.03, 5.36, 5.96, 5.24, 1.59, 8.57, 8.40, 5.54, 5.81, 5.58, 9.57, 4.43, 5.90, 1.96, 5.35, 4.14, 3.27, 7.54, 5.80, 4.50, 2.83, 5.89, 6.48, 1.82, 8.98, 4.09, 1.48, 1.45, 3.62, 1.83, 7.13, 5.71, 5.33, 2.63, 8.27, 1.68, 8.51, 7.34, 5.40, 7.13, 6.27, 5.28, 2.17, 8.36, 5.87, 5.56, 8.03, 8.84, 2.53, 7.25, 6.44, 7.20, 2.66, 1.57, 2.97, 4.38, 4.82, 9.28, 7.71, 5.84, 4.56, 4.28, 9.26, 4.54, 3.57, 8.14, 9.71, 7.21, 3.66, 1.95, 3.17, 1.84, 8.42, 3.31, 9.36, 4.23, 8.83, 2.69, 6.72, 7.07, 5.51, 8.11, 5.23, 9.77, 6.70, 8.45, 2.71, 9.73, 2.22, 6.98, 4.14, 2.06, 1.50, 6.09, 1.31, 4.64, 6.43, 8.20, 5.70, 5.88, 3.11, 4.77, 6.46, 7.71, 9.33, 5.29, 4.67, 7.53, 7.37, 6.59, 1.92, 3.45, 6.23, 2.36, 7.00, 5.76, 6.64, 6.28, 2.25, 4.86, 2.27, 1.98, 1.38, 3.67, 1.74, 5.89, 2.60, 4.69, 4.78, 1.43, 6.70, 8.92, 7.05, 6.97, 1.26, 7.46, 9.96, 4.77, 1.77, 7.74, 7.14, 5.05, 4.87, 4.95, 5.97, 4.09, 7.67, 7.41, 6.03, 8.65, 3.05, 3.56, 4.68, 2.74, 2.58, 6.97, 6.79, 7.59, 6.58, 6.48, 5.35, 5.26, 5.60, 9.66, 2.33, 9.36, 3.52, 8.54, 3.54, 2.78, 1.36, 9.82, 7.17, 5.37, 2.13, 7.19, 8.30, 1.57, 8.31, 9.11, 8.04, 7.76, 5.32, 2.14, 9.89, 8.61, 5.12, 4.93, 4.31, 3.65, 3.61, 7.64, 8.87, 1.08, 1.64, 9.07, 3.24, 6.26, 8.74, 3.10, 1.33, 1.09, 2.94, 5.96, 7.51, 7.63, 1.62, 7.20, 5.79, 8.84, 8.40, 2.60, 4.79, 3.00, 8.44, 6.37, 4.83, 6.15, 4.21, 2.97, 9.19, 3.58, 4.42, 3.09, 7.36, 1.61, 1.22, 6.40, 4.09, 7.77, 9.96, 9.68, 9.14, 5.15, 5.70, 3.31, 9.56, 7.69, 2.05, 3.66, 2.66, 9.97, 6.18, 5.22, 3.06, 7.33, 8.94, 2.64, 6.77, 2.32, 9.03, 2.35, 4.63, 3.20, 4.17, 2.22, 4.89, 7.06, 2.98, 7.83, 9.53, 6.96, 3.74, 2.40, 2.57, 7.90, 5.56, 1.99, 9.24, 3.00, 9.48, 8.88, 4.08, 9.92, 2.41, 1.40, 6.03, 6.31, 9.58, 1.61, 9.72, 6.92, 8.27, 1.76, 1.46, 8.71, 2.50, 7.94, 7.64, 6.41};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    // printf("Sorted Array: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%.2f ", arr[i]);
    // }
    return 0;
}

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
    float arr[] = {3.05, 5.21, 1.93, 6.52, 2.69, 2.63, 3.16, 8.69, 7.97, 3.68, 4.85, 2.73, 5.32, 4.50, 2.41, 5.13, 7.18, 4.01, 6.48, 2.37, 7.17, 5.25, 5.65, 6.12, 6.46, 5.98, 5.20, 5.60, 8.02, 4.26, 7.27, 4.52, 6.25, 2.72, 7.70, 3.33, 2.68, 6.63, 7.82, 7.28, 4.76, 7.25, 4.14, 1.85, 6.40, 9.24, 9.50, 7.20, 8.75, 7.03, 1.38, 3.81, 8.08, 6.67, 2.99, 7.34, 1.98, 2.15, 6.16, 2.01, 5.62, 5.82, 5.02, 1.59, 1.08, 3.65, 7.59, 4.35, 2.93, 2.29, 8.57, 8.48, 9.94, 9.36, 8.59, 5.91, 3.41, 8.85, 7.50, 5.89, 7.73, 9.83, 2.93, 3.76, 4.78, 6.55, 7.38, 2.74, 4.89, 6.51, 6.75, 6.18, 1.09, 9.52, 2.25, 2.53, 1.94, 5.10, 2.80, 2.55, 3.58, 2.51, 8.93, 9.55, 8.94, 7.58, 3.20, 6.37, 4.61, 2.65, 4.37, 1.01, 5.68, 5.76, 9.54, 9.09, 2.75, 9.98, 4.67, 2.09, 8.86, 1.56, 3.15, 6.20, 6.76, 4.45, 6.23, 3.75, 7.22, 9.85, 2.05, 7.05, 3.15, 6.24, 4.18, 1.28, 5.30, 8.64, 9.35, 6.51, 7.02, 6.45, 4.94, 8.61, 1.04, 6.50, 7.94, 9.43, 3.70, 8.03, 8.69, 7.65, 4.60, 2.78, 4.83, 2.98, 7.30, 7.85, 2.08, 4.45, 5.39, 7.43, 8.23, 3.98, 3.93, 4.04, 1.73, 5.71, 5.97, 3.17, 2.72, 1.32, 9.37, 5.48, 8.66, 7.54, 1.67, 2.39, 7.94, 3.72, 8.32, 6.15, 4.62, 7.80, 6.83, 3.09, 4.72, 5.53, 1.12, 4.85, 8.37, 7.11, 6.10, 6.54, 4.83, 6.97, 2.13, 7.62, 7.19, 5.67, 9.52, 3.31, 8.83, 3.31, 9.07, 2.88, 5.40, 4.34, 6.24, 5.63, 7.85, 2.49, 7.12, 7.76, 2.24, 2.27, 2.43, 5.67, 1.43, 1.40, 3.44, 6.62, 9.39, 7.45, 7.24, 6.59, 1.33, 7.66, 4.44, 7.06, 7.83, 4.73, 1.22, 5.85, 2.47, 9.53, 8.82, 2.95, 1.42, 4.15, 8.74, 8.37, 9.10, 9.73, 7.05, 1.88, 3.02, 2.62, 3.43, 8.50, 1.58, 1.74, 5.23, 2.52, 2.61, 8.90, 2.23, 1.54, 8.72, 6.89, 1.81, 3.39, 1.81, 5.01, 4.30, 9.65, 4.65, 7.39, 4.79, 6.08, 1.79, 3.01, 9.22, 8.34, 6.94, 1.40, 4.62, 9.41, 6.85, 4.23, 9.21, 9.02, 4.39, 2.81, 4.13, 8.77, 9.19, 1.32, 3.22, 3.12, 7.74, 3.24, 5.36, 8.90, 6.45, 1.60, 3.41, 5.72, 1.17, 9.23, 9.72, 4.46, 9.64, 3.42, 1.92, 6.83, 9.78, 3.36, 3.23, 9.14, 6.21, 7.29, 1.91, 3.62, 7.99, 5.81, 8.51, 2.46, 4.40, 7.54, 1.88, 7.91, 5.28, 5.49, 2.85, 1.27, 1.51, 1.77, 6.65, 1.03, 4.86, 5.58, 2.41, 1.30, 6.21, 1.34, 7.61, 5.06, 5.97, 5.53, 1.07, 2.31, 3.68, 7.32, 5.70, 3.43, 2.63, 1.66, 5.52, 1.11, 6.49, 3.38, 2.03, 8.97, 9.46, 6.27, 4.70, 7.18, 6.61, 2.58, 9.85, 3.90, 4.75, 8.67, 4.41, 9.61, 6.44, 5.31, 4.84, 6.32, 9.63, 2.50, 7.56, 7.67, 9.98, 6.99, 2.55, 9.81, 7.47, 3.92, 2.48, 8.90, 8.79, 8.15, 3.94, 4.21, 6.13, 9.65, 7.95, 6.77, 9.83, 1.56, 5.42, 8.11, 5.97, 5.93, 9.02, 4.76, 3.83, 2.33, 1.75, 4.33, 5.35, 3.27, 3.82, 8.75, 4.03, 2.47, 6.36, 7.93, 5.59, 3.13, 3.37, 7.87, 8.30, 7.00, 4.19, 6.83, 1.39, 8.48, 7.61, 8.91, 1.83, 3.32, 6.53, 7.46, 9.63, 3.77, 2.86, 2.17, 8.67, 6.41, 1.23, 1.59, 5.54, 2.57, 4.71, 9.06, 9.92, 4.24, 7.57, 7.44, 5.49, 7.82, 4.17, 9.92, 1.04, 5.95, 3.78, 8.84, 6.28, 4.67, 8.11, 6.13, 4.68, 8.46, 1.61, 4.20, 3.39, 3.56, 3.69, 1.18, 7.50, 4.82, 2.92, 4.06, 2.19, 3.67, 3.58, 3.03, 8.82, 7.17, 8.20, 3.80, 5.66, 5.07, 2.27, 5.41, 9.73, 4.02, 7.51, 8.06, 5.14, 6.88, 6.63, 5.68, 8.42, 4.59, 7.43, 8.63, 5.57, 5.37, 6.50, 8.29, 8.03, 1.63, 9.78, 5.06, 5.00, 6.57, 2.15, 9.30, 3.79, 8.30, 6.20, 7.07, 5.19, 7.50, 5.04, 5.38, 8.43, 2.73, 9.87, 1.47, 1.15, 2.74, 4.98, 8.22, 3.35, 1.35, 5.09, 1.16, 1.78, 7.12, 6.68, 2.89, 2.87, 7.40, 4.75, 6.46, 1.24, 9.37, 9.49, 8.40, 6.13, 6.71, 6.98, 9.86, 6.25, 8.76, 5.26, 5.07, 5.70, 6.53, 8.62, 9.64, 9.22, 3.49, 1.03, 9.33, 8.93, 8.83, 8.65, 9.42, 9.90, 2.02, 5.04, 3.67, 2.70, 4.34, 6.88, 1.69, 8.95, 4.07, 4.95, 5.43, 8.00, 8.23, 9.37, 9.58, 7.67, 6.16, 1.49, 9.40, 9.59, 6.40, 3.82, 3.04, 4.86, 3.70, 9.16, 1.43, 4.90, 6.87, 7.13, 2.80, 7.96, 9.89, 7.80, 9.28, 8.10, 6.19, 5.51, 7.26, 3.26, 9.89, 4.84, 3.53, 1.77, 3.55, 5.15, 6.81, 2.80, 4.65, 6.40, 2.11, 7.70, 1.64, 3.86, 1.87, 8.04, 8.27, 2.92, 2.13, 2.72, 1.89, 6.22, 2.11, 4.95, 7.27, 9.44, 5.08, 3.64, 7.06, 9.79, 4.10, 5.38, 2.12, 8.31, 8.55, 1.86, 8.73, 4.29, 1.46, 6.79, 6.36, 8.83, 1.99, 5.85, 7.92, 2.57, 9.11, 1.70, 4.66, 7.23, 4.05, 3.73, 2.30, 2.64, 2.25, 2.88, 8.16, 8.74, 2.67, 3.52, 8.28, 7.57, 6.80, 9.59, 1.08, 6.24, 2.45, 1.63, 6.69, 6.86, 6.02, 4.92, 1.80, 5.58, 4.60, 4.69, 7.53, 6.89, 4.83, 5.73, 8.08, 2.03, 1.63, 7.57, 5.24, 9.90, 7.78, 9.75, 7.10, 7.09, 9.34, 3.88, 9.29, 8.54, 6.49, 6.39, 9.73, 5.29, 7.48, 5.93, 6.07, 2.01, 5.44, 9.69, 7.11, 8.67, 5.78, 2.94, 8.04, 9.39, 6.81, 9.46, 2.84, 4.82, 8.40, 1.31, 6.75, 5.12, 1.33, 8.58, 7.76, 4.50, 2.06, 5.30, 1.69, 4.19, 1.90, 6.08, 7.61, 5.12, 6.95, 5.59, 3.78, 4.54, 1.48, 1.41, 1.35, 2.10, 1.87, 8.08, 2.06, 3.19, 5.23, 1.68, 2.94, 4.97, 1.97, 3.30, 7.38, 9.19, 7.47, 6.71, 8.36, 1.65, 8.18, 1.31, 3.14, 6.47, 2.42, 9.49, 5.98, 2.60, 5.73, 3.00, 1.52, 3.37, 6.48, 3.74, 5.91, 3.57, 6.11, 4.88, 4.55, 4.32, 8.68, 8.96, 8.46, 7.83, 2.69, 9.71, 1.05, 6.87, 6.01, 3.07, 5.79, 8.51, 2.68, 6.93, 8.12, 3.62, 9.74, 8.87, 4.51, 7.15, 5.18, 7.51, 6.33, 9.20, 8.38, 7.81, 6.60, 4.80, 9.36, 9.80, 1.66, 4.68, 3.45, 1.22, 6.68, 4.23, 5.62, 6.09, 8.98, 3.89, 8.88, 4.00, 1.74, 7.16, 8.92, 9.01, 1.61, 7.89, 9.74, 3.06, 3.75, 5.77, 2.71, 5.66, 8.18, 1.91, 7.42, 3.02, 9.67, 4.68, 4.00, 7.09, 4.48, 5.32, 6.04, 1.60, 9.56, 3.62, 4.80, 9.33, 5.38, 1.10, 6.03, 7.35, 9.82, 5.73, 9.43, 9.26, 3.29, 2.71, 1.26, 1.29, 2.17, 3.10, 3.11, 4.78, 5.40, 10.00, 4.48, 1.44, 1.13, 7.53, 1.49, 5.86, 5.90, 2.87, 2.40, 5.90, 9.33, 1.27, 2.05, 6.03, 9.60, 7.25, 3.04, 5.08, 7.46, 1.20, 4.36, 3.97, 1.82, 9.77, 8.32, 5.78, 1.36, 2.89, 4.37, 3.34, 4.10, 7.64, 7.91, 2.31, 2.81, 7.78, 1.55, 2.66, 9.31, 9.32, 3.34, 2.78, 5.42, 7.84, 6.92, 9.08, 4.52, 8.12, 1.06, 9.07, 9.12, 6.61, 4.02, 7.95, 8.60, 5.50, 9.00, 3.66, 1.67, 9.01, 3.13, 3.60, 9.57, 6.15, 8.01, 1.29, 1.59, 4.98, 4.57, 6.93, 5.69, 6.27, 9.53, 1.50, 1.13, 6.90, 3.83, 7.40, 6.64, 8.39, 2.84, 3.17, 6.05, 2.37, 6.67, 7.03, 3.19, 9.51, 4.53, 9.50, 3.32, 1.62, 9.69, 2.20, 5.00, 5.19, 3.08, 1.15, 9.45, 3.97, 2.45, 2.59, 1.37, 6.95, 3.91, 6.17, 6.06, 6.31, 4.89, 1.12, 9.84, 8.47, 3.51, 9.02, 8.47, 5.92, 1.57, 6.09, 3.18, 8.92, 9.66, 6.77, 8.15, 8.35, 8.28, 2.54, 5.47, 8.41, 9.96, 2.22, 9.26, 1.37, 5.87, 9.92, 3.00, 9.27, 9.82, 1.86, 1.45, 9.18, 1.64, 3.35, 7.04, 2.02, 5.34, 1.71, 6.73, 6.43, 1.75, 7.79, 5.75, 3.09, 7.81, 1.21, 5.45, 1.82, 5.56, 9.41, 8.40, 6.11, 3.48, 2.95, 2.83, 9.62, 5.44, 8.06, 6.71, 8.27, 2.20, 9.14, 3.27, 4.57, 3.91, 3.79, 8.75, 4.55, 3.84, 8.59, 4.60, 7.13, 2.49, 6.98, 1.90, 3.28, 5.34, 3.87, 7.93, 3.85, 4.27, 2.91, 3.86, 2.52, 4.97, 9.10, 6.86, 9.42, 9.30, 6.56, 2.34, 2.17, 6.41, 8.89, 8.99, 3.58, 4.12, 4.59, 9.48, 8.94, 5.57, 2.61, 5.03, 2.16, 6.91, 5.28, 1.53, 3.47, 7.18, 9.04, 3.96, 8.16, 7.31, 3.52, 7.08, 1.04, 2.21, 2.82, 5.15, 3.97, 4.49, 9.11, 9.44, 5.22, 8.36, 2.02, 9.99, 3.23, 7.77, 5.42, 7.32, 7.22, 2.59, 2.84, 6.67, 6.02, 4.33, 2.14, 4.52, 7.89, 4.56, 3.39, 5.11, 4.21, 1.47, 8.28, 7.30, 4.99, 2.97, 3.53, 2.96, 8.31, 7.23, 4.43, 2.33, 3.50, 3.77, 7.99, 2.88, 5.14, 4.08, 9.70, 1.11, 9.65, 5.85, 5.54, 6.42, 3.40, 3.33, 4.03, 1.80, 2.38, 8.57, 8.73, 6.62, 5.05, 4.77, 3.51, 8.38, 2.07, 3.61, 4.64, 8.59, 6.69, 5.33, 5.13, 1.05, 8.56, 3.21, 1.14, 4.27, 9.88, 4.46, 4.15, 4.09, 7.89, 3.99, 8.81, 6.00, 1.12, 7.74, 3.57, 7.68, 5.46, 6.44, 7.93, 5.20, 3.22, 8.05, 9.70, 7.73, 5.16, 8.66, 9.38, 4.54, 9.22, 9.57, 3.85, 8.94, 5.46, 7.86, 8.14, 1.21, 7.87, 1.16, 5.45, 8.07, 7.53, 6.63, 7.97, 6.59, 6.65, 7.86, 9.69, 1.14, 7.52, 2.32, 6.07, 2.99, 8.21, 3.40, 7.60, 1.51, 9.96, 8.71, 4.22, 5.18, 2.96, 6.96, 2.49, 7.56, 5.50, 8.32, 3.45, 5.89, 4.80, 9.76, 7.28, 9.68, 1.30, 3.30, 6.36, 2.41, 8.97, 7.63, 5.03, 8.70, 9.88, 4.17, 6.22, 6.66, 8.78, 7.59, 6.28, 4.28, 5.11, 7.29, 8.21, 4.56, 9.24, 6.38, 5.94, 7.00, 8.52, 9.10, 5.99, 5.70, 8.49, 3.65, 5.33, 5.74, 6.56, 6.44, 5.29, 2.77, 1.08, 3.63, 6.52, 4.33, 3.01, 3.28, 8.02, 7.07, 3.24, 2.33, 9.80, 8.87, 4.36, 3.93, 7.72, 5.07, 3.47, 3.26, 3.96, 7.37, 8.24, 9.05, 8.24, 4.37, 2.79, 1.97, 1.99, 1.70, 4.47, 9.09, 7.65, 1.70, 1.44, 2.39, 4.35, 1.09, 1.79, 7.77, 8.35, 4.91, 7.16, 2.44, 3.78, 1.02, 6.39, 6.96, 5.72, 4.26, 5.74, 1.76, 2.35, 8.45, 8.63, 3.11, 2.07, 8.79, 8.43, 5.87, 6.82, 4.13, 6.29, 7.60, 9.40, 5.23, 3.07, 5.55, 5.63, 3.98, 6.20, 3.16, 6.70, 5.83, 2.70, 9.12, 2.76, 7.30, 9.93, 1.25, 4.61, 7.49, 2.79, 2.44, 6.70, 8.85, 7.90, 9.16, 5.47, 5.27, 5.34, 9.03, 6.66, 1.38, 2.62, 7.38, 9.94, 1.94, 5.89, 2.30, 7.62, 4.07, 3.90, 8.71, 2.51, 8.22, 7.15, 7.41, 2.76, 6.32, 8.76, 3.66, 6.35, 4.72, 2.18, 3.88, 4.96, 5.11, 5.71, 7.55, 7.81, 2.37, 4.30, 9.25, 2.54, 2.04, 5.61, 9.76, 3.29, 6.91, 9.57, 5.84, 2.60, 6.72, 8.53, 5.02, 7.41, 7.66, 7.14, 4.06, 2.10, 8.13, 7.65, 2.00, 9.58, 6.97, 7.48, 3.81, 9.91, 3.03, 7.85, 1.24, 3.21, 4.96, 8.00, 1.35, 1.55, 8.13, 3.59, 6.95, 9.13, 4.41, 4.44, 9.06, 4.04, 8.51, 5.41, 8.63, 3.47, 4.16, 5.56, 5.48, 6.58, 4.48, 1.39, 3.00, 6.30, 2.38, 9.54, 3.10, 6.42, 7.52, 1.71, 7.01, 2.29, 8.41, 8.72, 4.77, 6.56, 6.48, 4.74, 7.26, 1.36, 1.41, 4.14, 5.50, 9.17, 3.72, 7.69, 1.23, 6.17, 1.98, 8.55, 4.99, 7.21, 3.74, 8.16, 2.28, 7.34, 6.78, 3.56, 9.81, 3.27, 1.95, 9.04, 4.31, 6.34, 6.78, 2.60, 8.98, 6.18, 1.46, 4.94, 9.56, 5.09, 2.22, 5.64, 9.84, 9.88, 3.87, 6.85, 3.70, 2.29, 8.47, 4.12, 1.92, 8.00, 5.75, 6.30, 4.39, 4.24, 7.08, 8.58, 6.01, 7.42, 4.29, 4.28, 8.95, 4.09, 5.60, 2.56, 9.25, 1.78, 2.67, 1.18, 8.26, 2.57, 9.93, 5.01, 4.20, 7.64, 7.39, 3.54, 2.96, 1.65, 2.58, 4.25, 2.35, 5.25, 8.09, 6.60, 2.92, 3.20, 1.31, 6.92, 8.64, 9.28, 8.25, 2.43, 9.72, 6.52, 7.21, 9.47, 8.09, 6.33, 5.77, 5.10, 5.21, 1.62, 4.56, 3.50, 7.88, 2.26, 3.71, 6.34, 4.90, 7.84, 2.16, 4.29, 2.97, 2.21, 4.91, 3.63, 7.03, 5.66, 4.18, 7.77, 8.62, 9.20, 6.05, 2.36, 3.19, 4.22, 8.45, 7.79, 8.52, 5.54, 4.58, 5.46, 7.33, 9.61, 5.92, 8.77, 5.26, 1.78, 9.34, 7.22, 8.19, 4.79, 9.23, 6.55, 9.77, 7.98, 4.73, 4.92, 3.23, 7.10, 8.42, 9.18, 3.95, 3.93, 8.43, 2.10, 6.99, 1.43, 4.51, 3.18, 4.44, 9.27, 3.31, 3.60, 3.64, 6.12, 7.68, 9.05, 5.81, 6.32, 2.12, 3.73, 6.26, 1.20, 9.55, 1.26, 7.36, 2.75, 8.44, 6.82, 3.95, 2.64, 2.68, 4.95, 9.87, 8.24, 2.04, 1.39, 9.95, 4.71, 4.87, 4.11, 6.14, 5.55, 1.50, 3.71, 7.44, 9.30, 8.39, 6.58, 9.60, 5.94, 9.26, 7.58, 6.73, 4.01, 9.48, 5.82, 8.56, 6.87, 6.06, 5.93, 9.80, 6.79, 1.00, 3.50, 7.73, 9.68, 2.77, 3.25, 8.79, 9.38, 4.63, 9.06, 5.27, 3.49, 7.10, 5.22, 1.55, 3.90, 7.20, 9.61, 9.45, 6.29, 2.53, 8.60, 3.14, 1.89, 9.32, 8.33, 3.48, 8.88, 8.33, 9.21, 2.32, 2.19, 7.42, 5.35, 9.86, 7.19, 2.64, 1.74, 1.52, 7.01, 5.27, 4.69, 4.70, 2.23, 7.92, 6.10, 3.07, 1.96, 2.86, 4.25, 2.18, 5.86, 7.96, 8.65, 1.45, 4.09, 8.84, 7.69, 2.50, 6.00, 1.67, 8.19, 8.17, 2.76, 6.79, 2.34, 7.36, 1.57, 2.26, 8.44, 1.48, 6.01, 3.61, 9.67, 7.34, 2.40, 1.82, 9.51, 6.54, 1.20, 7.55, 9.97, 8.20, 4.01, 1.53, 6.19, 3.76, 7.45, 4.88, 9.08, 6.90, 4.87, 7.46, 1.23, 8.04, 2.90, 1.01, 9.75, 2.36, 7.07, 5.99, 2.42, 2.85, 8.80, 9.49, 9.71, 5.52, 4.72, 8.14, 7.14, 8.54, 7.71, 5.84, 1.51, 2.28, 1.07, 4.93, 8.70, 3.12, 4.05, 5.17, 8.20, 3.89, 3.82, 6.26, 6.35, 9.84, 2.14, 5.81, 1.19, 7.24, 7.75, 7.69, 9.45, 4.53, 6.91, 5.58, 2.24, 1.76, 3.46, 2.98, 1.84, 6.14, 4.16, 4.64, 7.88, 2.46, 2.09, 1.54, 5.15, 6.94, 4.40, 8.81, 8.96, 2.82, 4.63, 1.58, 9.79, 4.47, 7.98, 4.05, 3.05, 1.93, 4.74, 5.51, 4.91, 3.35, 3.25, 5.79, 9.62, 1.90, 8.91, 8.10, 5.19, 5.64, 8.34, 9.35, 2.65, 9.47, 2.08, 4.42, 6.09, 9.77, 1.98, 3.92, 3.38, 1.72, 4.11, 1.84, 4.13, 3.06, 8.26, 4.38, 5.96, 5.30, 7.14, 4.64, 6.74, 9.00, 4.81, 3.11, 9.14, 8.98, 6.64, 2.45, 9.97, 4.58, 7.02, 4.21, 6.99, 8.68, 5.95, 1.42, 5.36, 1.85, 6.84, 5.62, 9.91, 7.37, 1.27, 1.96, 3.15, 8.50, 1.47, 1.06, 2.25, 9.15, 5.43, 8.12, 3.54, 5.05, 6.37, 6.05, 8.86, 6.47, 9.13, 4.17, 3.66, 5.65, 1.10, 5.80, 1.00, 6.72, 7.31, 3.55, 8.61, 7.71, 9.96, 2.48, 7.49, 7.26, 8.55, 5.61, 1.86, 1.28, 9.99, 4.43, 5.76, 8.71, 8.01, 6.60, 3.03, 2.06, 8.29, 5.83, 8.05, 4.66, 5.24, 1.68, 1.73, 4.25, 2.13, 2.53, 2.91, 4.87, 1.25, 7.97, 8.80, 9.41, 9.66, 5.37, 3.80, 4.38, 4.81, 1.94, 6.04, 9.31, 3.59, 6.43, 6.57, 6.38, 1.02, 1.34, 6.84, 3.94, 7.72, 5.88, 5.03, 8.78, 6.17, 7.33, 3.08, 4.08, 2.66, 5.80, 9.15, 9.29, 6.76, 5.16, 5.88, 4.32, 1.72, 3.54, 4.99, 7.63, 4.49, 9.18, 1.95, 2.83, 5.31, 9.03, 2.90, 7.75, 4.76, 4.42, 9.17, 5.77, 3.84, 8.89, 4.40, 3.99, 2.21, 8.53, 6.28, 3.86, 1.17, 8.36, 8.17, 3.46, 3.69, 3.74, 5.17, 8.25, 3.43, 5.96, 8.87, 6.80, 7.90, 5.39, 1.16, 2.00, 4.93, 7.04, 1.19, 9.53, 5.69, 6.75, 3.44, 1.83, 8.49, 3.36, 6.31, 6.23, 6.74, 2.56, 9.95, 4.31, 7.35, 3.42, 8.99, 8.07};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    // printf("Sorted Array: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%.2f ", arr[i]);
    // }
    return 0;
}
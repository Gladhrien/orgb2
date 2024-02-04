#include <stdio.h>
#include <math.h>

// An iterative binary search function adapted for float arrays.
int binarySearch(float arr[], int l, int r, float x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid with a tolerance for floating point comparison
		if (fabs(arr[m] - x) < 0.000001)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// If we reach here, then element was not present
	return -1;
}

// Driver code
int main(void)
{
	int n = sizeof(arr) / sizeof(arr[0]);
	float x = 83077.0f; // Example target value as float
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present in array")
				: printf("Element is present at index %d", result);
	return 0;
}

#include <stdio.h>
#include "arrayext.h"



void reverse_array_in_place(int arr[], int n) {
	if (arr == NULL) {
		fprintf(stderr, "Error: Null pointer passed to reverse_array_in_place.\n");
		return;
	}

	if (n < 0) {
		fprintf(stderr, "Error: Negative size passed to reverse_array_in_place.\n");
		return;
	}

	// No need to reverse if the array has 0 or 1 element
	if (n <= 1) {
		return;
	}

	for (int i = 0; i < n / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}
}

double average_array(int arr[], int n) {
	if (arr == NULL) {
		fprintf(stderr, "Error: Null pointer passed to average_array.\n");
		return 0;
	}

	if (n <= 0) {
		fprintf(stderr, "Error: Negative size passed to average_array.\n");
		return 0;
	}
	
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	
	return sum / n;
}

void minmax_array(int arr[], int n, int* min, int* max) {
	if (arr == NULL || min == NULL || max == NULL) {
		fprintf(stderr, "Error: Null pointer passed to minmax_array.\n");
		return;
	}

	if (n <= 0) {
		fprintf(stderr, "Error: Negative size passed to minmax_array.\n");
		return;
	}

	*min = arr[0];
	*max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < *min) {
			*min = arr[i];
		}
		if (arr[i] > *max) {
			*max = arr[i];
		}
	}
}
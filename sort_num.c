#include "basic.h"
#include "sort_num.h"

void swap(int *aptr, int *bptr) {
	int tmp = *aptr;
	*aptr = *bptr;
	*bptr = tmp;
}

int partition(int *arr, int front_idx, int end_idx) {
	int pivot = arr[end_idx];
	int i = front_idx - 1;
	int j;

	for(j = front_idx; j < end_idx; j++) {
		if(arr[j] < pivot) {
			i ++;
			swap(&arr[i], &arr[j]);
		}
	}
	i ++;
	swap(&arr[i], &arr[end_idx]);

	return i;
}

void quicksort(int *arr, int front_idx, int end_idx) {
	if(front_idx < end_idx) {
		int pivot_idx = partition(arr, front_idx, end_idx);
		quicksort(arr, front_idx, pivot_idx - 1);
		quicksort(arr, pivot_idx + 1, end_idx);
	}
}

void merge(int *arr, int front_idx, int mid_idx, int end_idx) {
	int i, j, k;
	int n1 = mid_idx - front_idx + 1; // numbers of left side data
	int n2 = end_idx - mid_idx; // numbers of right side data

	/* 1. Copy left/right side of data into temp array left[] and right[] */
	int left[n1], right[n2];
	for(i = 0; i < n1; i ++) {
		left[i] = arr[front_idx + i];
	}
	for(j = 0; j < n2; j ++) {
		right[j] = arr[mid_idx + 1 + j];
	}

	/* 2. Merge the left[] and right[] array into arr[], 
	      according to the size of the number           */
	i = 0; j = 0; k = front_idx;
	while(i < n1 && j < n2) {
		// Compare the size of left[i] and right[j], putting the smaller one into arr[]
		if(left[i] <= right[j]) {
			arr[k] = left[i];
			i ++;
		}
		else {
			arr[k] = right[j];
			j ++;
		}
		k ++;
	}

	/* 3. Copy the remaining number into arr[] */
	while(i < n1) {
		arr[k] = left[i];
		i ++;
		k ++;
	}
	while(j < n2) {
		arr[k] = right[j];
		j ++;
		k ++;
	}
	
}

void mergesort (int *arr, int front_idx, int end_idx) {
	if(front_idx < end_idx) {
		int mid_idx = (front_idx + end_idx) / 2;
		mergesort(arr, front_idx, mid_idx);
		mergesort(arr, mid_idx + 1, end_idx);
		merge(arr, front_idx, mid_idx, end_idx);
	}
}

void heapify(int *arr, int n, int origRoot_idx) {
	int root_idx = origRoot_idx;
	int left_idx = 2 * origRoot_idx + 1;
	int right_idx = 2 * origRoot_idx + 2;

	if(left_idx < n && arr[left_idx] > arr[root_idx]) {
		root_idx = left_idx;
	}
	if(right_idx < n && arr[right_idx] > arr[root_idx]) {
		root_idx = right_idx;
	}

	if(root_idx != origRoot_idx) {
		swap(&arr[root_idx], &arr[origRoot_idx]);
		heapify(arr, n, root_idx);
	}
}

void heapsort(int *arr, int n) {
	int i;
	for(i = n / 2 - 1; i >= 0; i --) {
		heapify(arr, n, i);
	}

	for(i = n - 1; i >= 0; i --) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
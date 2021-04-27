#include "basic.h"
#include "sort_string.h"

void swap(char *aptr, char *bptr) {
	char *tmp = malloc(sizeof(char) * 100);

	strcpy(tmp, aptr);
	strcpy(aptr, bptr);
	strcpy(bptr, tmp);

	free(tmp);
}

int partition(char **arr, int front_idx, int end_idx) {
	char *pivot = arr[end_idx];
	int i = front_idx - 1;
	int j;

	for(j = front_idx; j < end_idx; j++) {
		if(strcmp(arr[j], pivot) < 0) {
			i ++;
			swap(arr[i], arr[j]);
		}
	}
	i ++;
	swap(arr[i], arr[end_idx]);

	return i;
}

void quicksort(char **arr, int front_idx, int end_idx) {
	if(front_idx < end_idx) {
		int pivot_idx = partition(arr, front_idx, end_idx);
		quicksort(arr, front_idx, pivot_idx - 1);
		quicksort(arr, pivot_idx + 1, end_idx);
	}
}

void merge(char **arr, int front_idx, int mid_idx, int end_idx) {
	int i, j, k;
	int n1 = mid_idx - front_idx + 1; // numbers of left side data
	int n2 = end_idx - mid_idx; // numbers of right side data

	/* 1. Copy left/right side of data into temp array left[] and right[] */
	char *left[n1], *right[n2];
	for(i = 0; i < n1; i ++) {
		left[i] = malloc(sizeof(char) * 100);
	}
	for(i = 0; i < n2; i ++) {
		right[i] = malloc(sizeof(char) * 100);
	}

	for(i = 0; i < n1; i ++) {
		strcpy(left[i], arr[front_idx + i]);
	}
	for(j = 0; j < n2; j ++) {
		strcpy(right[j], arr[mid_idx + 1 + j]);
	}

	/* 2. Merge the left[] and right[] array into arr[], 
	      according to the size of the number */
	i = 0; j = 0; k = front_idx;
	while(i < n1 && j < n2) {
		// Compare the size of left[i] and right[j], putting the smaller one into arr[]
		if(strcmp(left[i], right[j]) <= 0) {
			strcpy(arr[k], left[i]);
			i ++;
		}
		else {
			strcpy(arr[k], right[j]);
			j ++;
		}
		k ++;
	}

	/* 3. Copy the remaining number into arr[] */
	while(i < n1) {
		strcpy(arr[k], left[i]);
		i ++;
		k ++;
	}
	while(j < n2) {
		strcpy(arr[k], right[j]);
		j ++;
		k ++;
	}

	/* 4. free */
	for(i = 0; i < n1; i ++) {
		free(left[i]);
	}
	for(i = 0; i < n2; i ++) {
		free(right[i]);
	}
}

void mergesort (char **arr, int front_idx, int end_idx) {
	if(front_idx < end_idx) {
		int mid_idx = (front_idx + end_idx) / 2;
		mergesort(arr, front_idx, mid_idx);
		mergesort(arr, mid_idx + 1, end_idx);
		merge(arr, front_idx, mid_idx, end_idx);
	}
}

void heapify(char **arr, int n, int origRoot_idx) {
	int root_idx = origRoot_idx;
	int left_idx = 2 * origRoot_idx + 1;
	int right_idx = 2 * origRoot_idx + 2;

	if(left_idx < n && strcmp(arr[left_idx], arr[root_idx]) > 0) {
		root_idx = left_idx;
	}
	if(right_idx < n && strcmp(arr[right_idx], arr[root_idx]) > 0) {
		root_idx = right_idx;
	}

	if(root_idx != origRoot_idx) {
		swap(arr[root_idx], arr[origRoot_idx]);
		heapify(arr, n, root_idx);
	}
}

void heapsort(char **arr, int n) {
	int i;
	for(i = n / 2 - 1; i >= 0; i --) {
		heapify(arr, n, i);
	}

	for(i = n - 1; i >= 0; i --) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
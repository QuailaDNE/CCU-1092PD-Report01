#include "basic.h"
#include "sort_num.h"

void main() {
	int *input = malloc(sizeof(int) * N);
	int i = 0;
	int num;
	double time_used;
	
	while(scanf("%d", &num) != EOF) {
		input[i] = num;
		i ++;
	}

	// Quick Sort
	gettimeofday(&start, NULL);
	quicksort(input, 0, N - 1);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	time_used = diff.tv_sec + (double)diff.tv_usec/1000000.0;
	printf("QuickSort_num Time Used = %f s \n", time_used);

	//Merge Sort
	gettimeofday(&start, NULL);
	mergesort(input, 0, N - 1);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	time_used = diff.tv_sec + (double)diff.tv_usec/1000000.0;
	printf("MergeSort_num Time Used = %f s \n", time_used);

	//Heap Sort
	gettimeofday(&start, NULL);
	heapsort(input, N);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	time_used = diff.tv_sec + (double)diff.tv_usec/1000000.0;
	printf("HeapSort_num Time Used  = %f s \n", time_used);
	
	// free
	free(input);
}

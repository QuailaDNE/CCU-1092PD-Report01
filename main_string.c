#include "basic.h"
#include "sort_string.h"

void main() {
	int i = 0;
	int num;
	double time_used;
	
	//char *input[N];
	char **input = malloc(sizeof(char *) * N);
	for(i = 0; i < N; i ++) {
		input[i] = malloc(sizeof(char) * 100);
		memset(input[i], '\0', 100);
	}

	i = 0;
	while(fgets(input[i], 4096, stdin)) { //2048?
		i ++;
	}

	// Quick Sort
	gettimeofday(&start, NULL);
	quicksort(input, 0, N - 1);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	time_used = diff.tv_sec + (double)diff.tv_usec/1000000.0;
	printf("QuickSort_string Time Used = %f s \n", time_used);

	// Merge Sort
	gettimeofday(&start, NULL);
	mergesort(input, 0, N - 1);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	time_used = diff.tv_sec + (double)diff.tv_usec/1000000.0;
	printf("MergeSort_string Time Used = %f s \n", time_used);

	//Heap Sort
	gettimeofday(&start, NULL);
	heapsort(input, N);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	time_used = diff.tv_sec + (double)diff.tv_usec/1000000.0;
	printf("HeapSort_string Time Used  = %f s \n", time_used);

	// free
	for(i = 0; i < N; i ++) {
		free(input[i]);
	}
	free(input);
}
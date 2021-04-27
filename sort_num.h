void swap(int *aptr, int *bptr);

int partition(int *arr, int front_idx, int end_idx);
void quicksort(int *arr, int front_idx, int end_idx);

void merge(int *arr, int front_idx, int mid_idx, int end_idx);
void mergesort(int *arr, int front_idx, int end_idx);

void heapify(int *arr, int n, int i);
void heapsort(int *arr, int n);
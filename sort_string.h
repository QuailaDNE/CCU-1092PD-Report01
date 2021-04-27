void swap(char *aptr, char *bptr);

int partition(char **arr, int front_idx, int end_idx);
void quicksort(char **arr, int front_idx, int end_idx);

void merge(char **arr, int front_idx, int mid_idx, int end_idx);
void mergesort(char **arr, int front_idx, int end_idx);

void heapify(char **arr, int n, int i);
void heapsort(char **arr, int n);

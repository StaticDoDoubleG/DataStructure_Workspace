#include "functions.h"

clock_t start;
clock_t end;

int** Set;
int* h;
int* tempArr;
bool allocated = 0;

//[Application]--------------

//Funtions In Main
void SortCheck() {
	printf("\n[Sort Check, n = 30]\n");

	Allocation(30, true);

	printf("\n<Bubble Sort(Fixed)>\n");
	printf("생성된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[0][i]);
	}
	printf("\n");
	BubbleSort(Set[0], 30);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[0][i]);
	}
	printf("\n");

	printf("\n<Selection Sort>\n"); 
	printf("생성된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[1][i]);
	}
	printf("\n");
	SelectionSort(Set[1], 30);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[1][i]);
	}
	printf("\n");

	printf("\n<Insertion Sort>\n");
	printf("생성된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[2][i]);
	}
	printf("\n");
	InsertionSort(Set[2], 30);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[2][i]);
	}
	printf("\n");

	printf("\n<Merge Sort>\n"); 
	printf("생성된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[3][i]);
	}
	printf("\n");
	tempArr = (int*)malloc(sizeof(int) * 30);
	Mergesort(Set[3], tempArr, 0, 30 - 1);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[3][i]);
	}
	printf("\n");
	free(tempArr);

	printf("\n<Quick Sort>\n"); //
	printf("생성된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[4][i]);
	}
	printf("\n");
	QuickSort(Set[4], 0, 30 - 1);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[4][i]);
	}
	printf("\n");

	printf("\n<Randomized Quick Sort>\n"); //
	printf("생성된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[4][i]);
	}
	printf("\n");
	swap(Set[4], 0, RandomReturn(30));
	QuickSort(Set[4], 0, 30 - 1);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[4][i]);
	}
	printf("\n");

	printf("\n<Heap Sort>\n"); 
	printf("생성된 행렬: ");
	for(int i = 0; i < 30; i++) {
		printf("%2d ", Set[5][i]);
	}
	printf("\n");
	Heapsort(Set[5], 30);
	printf("정렬된 행렬: ");
	for (int i = 0; i < 30; i++) {
		printf("%2d ", Set[5][i]);
	}
	printf("\n");

	free(Set);
}

void SRD() {
	printf("\n1/ Sort Random Data\n");
	for (int i = 1; i <= 10; i++) {
		printf("\nn = %d일 때\n", i * 10000);
		Allocation(i * 10000, true);

		printf("<Bubble Sort(Fixed)>     ");
		start = clock();
		BubbleSort(Set[0], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);
		
		printf("<Selection Sort>         ");
		start = clock();
		SelectionSort(Set[1], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);

		printf("<Insertion Sort>         ");
		start = clock();
		InsertionSort(Set[2], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);

		printf("<Merge Sort>             ");
		tempArr = (int*)malloc(sizeof(int) * i * 10000);
		start = clock();
		Mergesort(Set[3], tempArr, 0, i * 10000 - 1);
		end = clock();
		free(tempArr);
		printf("%5dms\n", end - start);

		printf("<Quick Sort>             ");
		start = clock();
		QuickSort(Set[4], 0, i * 10000 - 1);
		end = clock();
		printf("%5dms\n", end - start);

		printf("<Heap Sort>              ");
		start = clock();
		Heapsort(Set[5], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);
		Release();
	}
}

void SOD() {
	printf("\n2/ Sort Ordered Data\n");
	for (int i = 1; i <= 10; i++) {
		printf("\nn = %d일 때\n", i * 10000);
		Allocation(i * 10000, false);

		printf("<Bubble Sort(Fixed)>     ");
		start = clock();
		BubbleSort(Set[0], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);
		/*
		printf("<Selection Sort>         ");
		start = clock();
		SelectionSort(Set[1], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);
		*/
		printf("<Insertion Sort>         ");
		start = clock();
		InsertionSort(Set[1], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);
		/*
		printf("<Merge Sort>             ");
		tempArr = (int*)malloc(sizeof(int) * i * 10000);
		start = clock();
		Mergesort(Set[3], tempArr, 0, i * 10000 - 1);
		end = clock();
		free(tempArr);
		printf("%5dms\n", end - start);
		*/
		printf("<Quick Sort>             ");
		start = clock();
		QuickSort(Set[2], 0, i * 10000 - 1);
		end = clock();
		printf("%5dms\n", end - start);
		/*
		printf("<Heap Sort>              ");
		start = clock();
		Heapsort(Set[5], i * 10000);
		end = clock();
		printf("%5dms\n", end - start);
		*/
		printf("<Radomized Quick Sort>   ");
		swap(Set[3], 0, RandomReturn(i * 10000));
		start = clock();
		QuickSort(Set[3], 0, i * 10000 - 1);
		//RandomizedQuickSort(Set[3], 0, i * 10000 - 1);
		end = clock();
		printf("%5dms\n", end - start);

		Release();
	}
}

void RandomTest() {
	for (int i = 1; i <= 10; i++) {
		printf("\n<%d0만인 경우>\n", i);
		for (int j = 1; j <= 10; j++) {
			printf("리턴 값: %d\n", RandomReturn(i * 100000));
		}
	}
}

//
void Allocation(int in, bool random) {
	h = (int*)malloc(sizeof(int) * in);
	for (int i = 0; i < in; i++) {
		h[i] = RandomReturn(in);
	}
	if (!random) {
		QuickSort(h, 0, in - 1);
	}
	Set = (int**)malloc(sizeof(int*) * 6);
	for (int i = 0; i < 6; i++) {
		Set[i] = (int*)malloc(sizeof(int) * in);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < in; j++) {
			Set[i][j] = h[j];
		}
	}
	Set = (int**)malloc(sizeof(int*) * 6);
	for (int i = 0; i < 6; i++) {
		Set[i] = (int*)malloc(sizeof(int) * in);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < in; j++) {
			Set[i][j] = h[j];
		}
	}
	free(h);
}

void Release() {
	for (int i = 0; i < 6; i++) {
		free(Set[i]);
		Set[i] = 0;
	}
	free(Set);
	Set = 0;
}

//Random related
int RandomReturn(int in) {
	return ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) \
		* ((in + 1) - 1)) + 1);
}

//[Sorts]--------------------

//Bubble Sort
void BubbleSort(int A[], int n) { //Fixed
	int swapped = 1;
	for (int pass = n - 1; pass > 0 && swapped; pass--) {
		swapped = 0;
		for (int i = 0; i < pass; i++) {
			if (A[i] > A[i + 1]) {
				int temp = A[i];
				A[i] = A[i + 1]; A[i + 1] = temp; swapped = 1;
			}
		}
	}
}

//Selection Sort
void SelectionSort(int A[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		//printf("현재 제일 작은 수: %2d\n", A[min]);
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;
	}
} 

//Insertion Sort
void InsertionSort(int A[], int n) {
	int i, j, key;
	for (i = 1; i <= n - 1; i++) {
		key = A[i];
		for (j = i - 1; j >= 0 && A[j] > key; j--) { 
			A[j + 1] = A[j];
		}
		A[j + 1] = key;
	}
}

//Merge Sort
void Mergesort(int A[], int temp[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Mergesort(A, temp, left, mid); Mergesort(A, temp, mid + 1, right); 
		Merge(A, temp, left, mid + 1, right);
	}
}

void Merge(int A[], int temp[], int left, int right, int right_end) {
	int i, j, left_end, size, temp_pos;
	left_end = right - 1;
	size = right_end - left + 1;
	i = left;
	j = right; 
	temp_pos = left;
	while ((i <= left_end) && (j <= right_end)) {
		if (A[i] <= A[j]) {
			temp[temp_pos] = A[i]; temp_pos = temp_pos + 1; i = i + 1;
		}
		else {
			temp[temp_pos] = A[j];
			temp_pos = temp_pos + 1;
			j = j + 1;
		}
	}
	while (i <= left_end) { 
		temp[temp_pos] = A[i]; 
		temp_pos = temp_pos + 1;
		i = i + 1;
	}
	while (j <= right_end) { 
		temp[temp_pos] = A[j]; 
		temp_pos = temp_pos + 1; 
		j = j + 1;
	}
	for (i = left; i <= right_end; i++) {
		A[i] = temp[i];
	}
}

//Quick Sort
void QuickSort(int A[], int left, int right) {
	int pivot;
	if (left < right) {
		pivot = Partition(A, left, right); 
		QuickSort(A, left, pivot - 1); 
		QuickSort(A, pivot + 1, right);
	}
}

int Partition(int A[], int left, int right) {
	int low, high, pivot_item = A[left]; 
	low = left;
	high = right;
	while (low < high) {
		while (low <= right && A[low] <= pivot_item) {
			low++;
		}
		while (left <= high && A[high] > pivot_item) {
			high--;
		}
		if (low < high) {
			swap(A, low, high); // swap은 별도 구현
		}
	}
	A[left] = A[high];
	A[high] = pivot_item;
	return high;
}

void swap(int A[], int left, int right) {
	int temp = A[left];
	A[left] = A[right];
	A[right] = temp;
}
/*
//Randomized Quick Sort
void RandomizedQuickSort(int A[], int left, int right) {
	int pivot;
	if (left < right) {
		pivot = Partition_RQS(A, left, right);
		QuickSort(A, left, pivot - 1);
		QuickSort(A, pivot + 1, right);
	}
}

int Partition_RQS(int A[], int left, int right) {
	int low, high, pivot_index, pivot_item;
	low = left;
	high = right;
	pivot_index = RandomReturn(right - left);
	swap(A, left, pivot_index);
	pivot_item = A[left];

	while (low < high) {
		while (low <= right && A[low] <= pivot_item) {
			low++;
		}
		while (left <= high && A[high] > pivot_item) {
			high--;
		}
		if (low < high) {
			swap(A, low, high); // swap은 별도 구현
		}
	}
	A[left] = A[high];
	A[high] = pivot_item;
	return high;
}
*/
//Heap Sort
struct Heap {
	int* array;
	int count;
	int capacity;
	int heap_type;
};

struct Heap* CreateHeap(int capacity, int heap_type) {
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap)); 
	if (h == NULL) {
		printf("Memory Error");
		return NULL;
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int) * h->capacity); 
	if (h->array == NULL) {
		printf("Memory Error");
		return NULL;
	}
	return h;
}

int Parent(struct Heap* h, int i) {
	if (i <= 0 || i >= h->count) {
		return -1;
	}
	return (i - 1) / 2;
}

int LeftChild(struct Heap* h, int i) {
	int left = 2 * i + 1;
	if ((i < 0) || (left >= h->count)) {
		return -1;
	}
	return left;
}

int RightChild(struct Heap* h, int i) {
	int right = 2 * i + 2;
	if ((i < 0) || (right >= h->count)) {
		return -1;
	}
	return right;
}

void Heapify(struct Heap* h, int i) {
	int left, right, max, temp;
	left = LeftChild(h, i);
	right = RightChild(h, i);
	if (left != -1 && h->array[left] > h->array[i]) {
		max = left;
	}
	else {
		max = i;
	}
	if (right != -1 && h->array[right] > h->array[max]) {
		max = right;
	}
	if (max != i) {
		//h->array[i]와 h->array[max]를 swap하기 
		temp = h->array[i];
		h->array[i] = h->array[max]; 
		h->array[max] = temp;
		Heapify(h, max);
	}
}

void ResizeHeap(struct Heap* h) { // realloc으로 간단하게 구현 가능 
	int *array_old = h->array;
	h->array = (int*)malloc(sizeof(int) * h->capacity * 2);
	if (h->array == NULL) {
		printf("Memory Error");
		return;
	}
	for (int i = 0; i < h->capacity; i++) h->array[i] = array_old[i];
	h->capacity *= 2;
	free(array_old);
}

void BuildHeap(struct Heap* h, int A[], int n) {
	int last_index;
	if (h == NULL) return;
	while (n > h->capacity)
		ResizeHeap(h);
	for (int i = 0; i < n; i++) {
		h->array[i] = A[i];
	}
	h->count = n;
	last_index = n - 1;
	for (int i = Parent(h, last_index); i >= 0; i--) {
		Heapify(h, i);
	}
}

void Heapsort(int A[], int n) {
	int org_size, i, temp;
	struct Heap* h = CreateHeap(n, 1); // type 1이 max heap이라고 가정 
	BuildHeap(h, A, n);
	org_size = h->count;
	for (i = n - 1; i > 0; i--) { // n-1부터 1까지 반복
		temp = h->array[0]; // h->array[0]이 가장 큰 항목이다 
		h->array[0] = h->array[h->count - 1];
		h->array[h->count - 1] = temp; 
		h->count--;
		Heapify(h, 0);
	}
	h->count = org_size; 
	for (i = 0; i < n; i++) {
		A[i] = h->array[i];
	}
}
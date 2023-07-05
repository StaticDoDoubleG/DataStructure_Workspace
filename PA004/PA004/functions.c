#include "functions.h"

clock_t start;
clock_t end;

int* arr;

int UnsortedLinearSearch(int A[], int size, int data) {
    for (int i = 0; i < size; i++) {
        if (A[i] == data)   return i;
    }
    return -1;
}

int BinarySearchIterative(int A[], int size, int data) {
    int mid;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == data)
            return mid;
        else if (A[mid] < data)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void LinearSearch(int in) {
    Initialize(in);
    start = clock();
    for (int i = 0; i < 1000; i++) {
        //int num = UnsortedLinearSearch(arr, in * 1000000, RandomReturn(in));
        //printf("인덱스 값: %d", num);
        UnsortedLinearSearch(arr, in * 1000000, RandomReturn(in));
    }
    end = clock();
    free(arr);
    printf("Array Size가 %d일 때 Random Linear Search 소요시간: %lfms\n", in * 1000000, (end - start) / 1000.0);
}

void BinarySearch(int in) {
    Initialize(in);
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        //int num = BinarySearchIterative(arr, in * 1000000, RandomReturn(in));
        //printf("인덱스 값: %d", num);
        BinarySearchIterative(arr, in * 1000000, RandomReturn(in));
    }
    end = clock();
    free(arr);
    printf("Array Size가 %d일 때 Random Binary Search 소요시간: %lfms\n", in * 1000000, (end - start) / 1000000.0);
}

void Initialize(int in) {
    arr = (int*)malloc(in * 1000000 * sizeof(int));
    for (int i = 0; i < in * 1000000; i++) {
        arr[i] = i * 2;
    }
    
}

int RandomReturn(int in) {
    return ((double)rand() / RAND_MAX) * (in * 2000000 - 1);
}
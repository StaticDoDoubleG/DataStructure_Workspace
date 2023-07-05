#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Functions for Main()

void SortCheck(); //0
void SRD();       //1
void SOD();       //2
void RandomTest();

//Other Functions
void Allocation(int in, bool random);
void Release();
int RandomReturn(int in);

//Sort
void BubbleSort(int A[], int n);

void SelectionSort(int A[], int n);

void InsertionSort(int A[], int n);

void Mergesort(int A[], int temp[], int left, int right);
void Merge(int A[], int temp[], int left, int right, int right_end);

void QuickSort(int A[], int left, int right);
int Partition(int A[], int left, int right);
void swap(int A[], int left, int right);

//void RandomizedQuickSort(int A[], int left, int right);
//int Partition_RQS(int A[], int left, int right);

struct Heap* CreateHeap(int capacity, int heap_type);
int Parent(struct Heap* h, int i);
int LeftChild(struct Heap* h, int i);
int RightChild(struct Heap* h, int i);
void Heapify(struct Heap* h, int i);
void ResizeHeap(struct Heap* h);
void BuildHeap(struct Heap* h, int A[], int n);
void Heapsort(int A[], int n);
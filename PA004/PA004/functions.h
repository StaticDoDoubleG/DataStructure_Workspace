#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Functions for Main()
void LinearSearch(int in);	//1
void BinarySearch(int in);	//2
void LinearSearchPrompt();  //1
void BinarySearchPrompt();  //2
void TestCase();

//Functions of Sort
int UnsortedLinearSearch(int A[], int size, int data);  //1
int BinarySearchIterative(int A[], int size, int data); //2

//Other Functions
void Initialize(int in);
int RandomReturn(int in);
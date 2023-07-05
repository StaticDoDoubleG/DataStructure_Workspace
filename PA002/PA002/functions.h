#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct ListNode;
/*
struct ListNode {
	int data;
	struct ListNode* next;
};

/*
시간 측정 함수 참고자료
clock_t start;
clock_t end;
unsigned long long i;

start = clock();
//시간을 측정하고자 하는 코드 시작
for (i = 0; i < 1000000000;)
	i++;
// 시간을 측정하고자 하는 코드 끝
end = clock();
printf("Time: %d millisec\n", end - start);
*/

//Main Functions
//void SinglyLinkedList_test();
//void initialize();
void Insert(struct ListNode** h);
void Read(struct ListNode* h);
void Delete(struct ListNode** h);
void info(struct ListNode* h);

//Array Related
void array_insertion(int index, int data);

//LinkedList Related
void LinkedList_insertion(struct ListNode** h, int data, int position);
int LinkedList_traverse(struct ListNode* h, int position);
void LinkedList_Deletion(struct ListNode** h, int position);
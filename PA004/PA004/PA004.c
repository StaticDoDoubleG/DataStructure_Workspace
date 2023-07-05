//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit

#include "functions.h"

int main() {
	//학생 정보
	printf("컴퓨터공학부 202211390 최준원\n");
	printf("실행환경: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n명령을 선택하세요.\n1/ Linear search time complexity \n2/ Binary search time complexity\n3/ 종료\n\n선택 번호: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
			while (getchar() != '\n');
			continue;
		}
		else {
			switch (num) {
			case 1:
				LinearSearchPrompt();
				break;
			case 2:
				BinarySearchPrompt();
				break;
			case 3:
				//TestCase();
				//break;
				return 0;
			default:
				printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
				break;
			}
		}
	}
}

void LinearSearchPrompt() {
	printf("\n1/Linear Search time complexity\n");
	for (int i = 0; i < 10; i++) {
		LinearSearch(i + 1);
	}
}
void BinarySearchPrompt() {
	printf("\n2/Binary Search time complexity\n");
	for (int i = 0; i < 10; i++) {
		BinarySearch(i + 1);
	}
}

void TestCase() {
	for (int i = 0; i < 30; i++) {
		printf("랜덤: %d\n", RandomReturn(10));
	}
}
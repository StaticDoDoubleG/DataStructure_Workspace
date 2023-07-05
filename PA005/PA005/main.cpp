//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit

#include "functions.h"

int main() {
	//학생 정보
	printf("컴퓨터공학부 202211390 최준원\n");
	printf("실행환경: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n명령을 선택하세요.\n1/ Insert Randomly\n2/ Insert in Order\n3/ Random Test\n4/ 종료\n\n선택 번호: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
			while (getchar() != '\n');
			continue;
		}
		else {
			switch (num) {
			case 1:
				RIRF();
				break;
			case 2:
				OIRF();
				break;
			case 3:
				RandomTest();
				break;
			case 4:
				return 0;
			default: 
				printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
				break;
			}
		}
	}
}

void RIRF() {
	printf("\n1/ Insert Randomly Find Randomly\n");
	printf("\nBinary Search Tree에서 수행\n");
	BST_RIRF();
	printf("\nBalanced Binary Search Tree에서 수행\n");
	BBST_RIRF();
}

void OIRF() {
	printf("\n2/ Insert in Order Find Randomly\n");
	printf("\nBinary Search Tree에서 수행\n");
	BST_OIRF();
	printf("\nBalanced Binary Search Tree에서 수행\n");
	BBST_OIRF();
}

void RandomTest() {
	for (int i = 1; i <= 10; i++) {
		printf("\n<%d0만인 경우>\n", i);
		for (int j = 1; j <= 10; j++) {
			printf("리턴 값: %d\n", RandomReturn(i * 100000));
		}
	}
}
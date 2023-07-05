//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit

#include "functions.h"

int main() {
	//학생 정보
	printf("컴퓨터공학부 202211390 최준원\n");
	printf("실행환경: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n명령을 선택하세요.\n1/ Push n만번 후 Pop n만번 수행 비교\n2/ Push Pop 1번 Time Complexity\n3/ Array 2배 증가 시 수행시간 증가 증명\n4/ Push 1번 후 Pop 1번을 n만번 수행 비교\n5/ 종료\n\n선택 번호: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
			while (getchar() != '\n');
			continue;
		}
		else {
			switch (num) {
			case 1:
				pnpnTime();
				break;
			case 2:
				p1p1Time();
				break;
			case 3:
				doublingTime();
				break;
			case 4:
				p1p1RotateTime();
				break;
			case 5:
				return 0;
			default:
				printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
				break;
			}
		}
	}
}

void pnpnTime() { //1번 문제 함수
	printf("\nPush n만번 후 Pop n만번 수행 비교\n");
	printf("\n**Dynamic Array**");
	for (int i = 1; i <= 10; i++) {
		printf("\nDynamic Array에서 %d0만 수행시간: %d", i * 10, pnpnDnstk(i));
	}
	printf("\n\n**Linked List**");
	for (int i = 1; i <= 10; i++) {
		printf("\nLinked List에서 %d0만 수행시간: %d", i * 10, pnpnLnstk(i));
	}
	printf("\n");
}

void p1p1Time() { //2번 문제 함수
	printf("\nPush Pop 1번 Time Complexity\n");
	printf("\nDynamic Array에서 측정\n");
	for (int i = 1; i <= 10; i++) {
		pnpnDnstk_measure(i);
	}
	printf("\n\nLinked List에서 측정\n");
	for (int i = 1; i <= 10; i++) {
		pnpnLnstk_measure(i);
	}
	//measureTimeComplexity();
	printf("\n");
}

void doublingTime() { //3번 문제 함수
	printf("\nArray 2배 증가 시 수행시간 증가 증명\n");
	Dnstk10M();
	printf("\n");
}

void p1p1RotateTime() { //4번 문제 함수
	printf("\nPush 1번 후 Pop 1번을 n만번 수행 비교\n");
	printf("\n**Dynamic Array**");
	for (int i = 1; i <= 10; i++) {
		printf("\nDynamic Array에서 %d0만 수행시간: %d", i * 10, p1p1RotateDnstk(i));
	}
	printf("\n\n**Linked List**");
	for (int i = 1; i <= 10; i++) {
		printf("\nLinked List에서 %d0만 수행시간: %d", i * 10, p1p1RotateLnstk(i));
	}
	printf("\n");
}
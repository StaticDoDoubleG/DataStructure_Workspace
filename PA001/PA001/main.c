//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit
#include "essentials.h"

int main() {
	//학생 정보
	printf("컴퓨터공학부 202211390 최준원\n");
	printf("실행환경: Windows 11 64bit\n");

	char a;
	int choice;

	while (1) {
		printf("\n 1) 1번문제, 2) 2번문제 3) 3번문제, 4) 4번문제, 5) 종료");
		printf("\n번호 입력: ");
		scanf("%c", &a);
		if (isdigit(a)) {	
			choice = a - '0';
			
			switch (choice) {
			case 1:
				factorialOne2Ten();
				break;
			case 2:
				fibonacciOne2Ten();
				break;
			case 3:
				showSOFonREC();
				break;
			case 4:
				showIterationIsFine();
				break;
			case 5:
				return 0;
			default:
				printf("\n선택 가능한 범위 내의 숫자를 입력해주세요!");
				//while (getchar() != '\n');
				break;
			}
		}
		else {
			printf("\n번호를 입력해주시기 바랍니다!");
			//while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
}

void factorialOne2Ten() { //1번 문제 함수
	for (int i = 0; i < 10;i++) {
		printf("\ninput number: %d", (i+1));
		printf("\nrecursive: %d", fact_rec(i+1));
		printf("\n");
		printf("iteration: %d\n", fact_it(i+1));
	}
}
void fibonacciOne2Ten() { //2번 문제 함수
	for (int i = 0;i < 10;i++) {
		printf("\ninput number: %d", (i+1));
		printf("\nrecursive: ");
		for (int j = 0; j < i+1; j++) {
			printf("%d", fib_rec(j));
			if (j != i) {
				printf(", ");
			}
		}
		printf("\n");
		printf("iteration: ");
		for (int j = 0; j < i + 1; j++) {
			printf("%d", fib_it(j));
			if (j != i) {
				printf(", ");
			}
		}
		printf("\n");
	}

}
void showSOFonREC() { //3번 문제 함수
	int n;
	printf("정수를 입력해주세요: ");
	scanf("%d", &n);
	printf("\ninput number: %d", n);
	for (int i = 0; i < n;i++) {
		printf("\nrecursive: %d", fact_rec(i + 1));
		printf("\n");
	}
	
}
void showIterationIsFine() { //4번 문제 함수
	int n;
	printf("정수를 입력해주세요: ");
	scanf("%d", &n);
	printf("\ninput number: %d", n);
	for (int i = 0; i < n;i++) {
		printf("\niteration: %d\n", fact_it(i + 1));
		printf("\n");
	}
}
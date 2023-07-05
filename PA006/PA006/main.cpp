//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit

#include "functions.h"

int main() {
	//학생 정보
	printf("컴퓨터공학부 202211390 최준원\n");
	printf("실행환경: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n명령을 선택하세요.\n0/ Sort Check\n1/ Sort Random Data\n2/ Sort Ordered Data\n3/ 종료\n\n선택 번호: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
			while (getchar() != '\n');
			continue;
		}
		else {
			switch (num) {
			case 0:
				SortCheck();
				break;
			case 1:
				SRD();
				break;
			case 2:
				SOD();
				break;
			case 3:
				return 0;
			default: 
				printf("\n입력이 잘못됐습니다. 다시 입력해주세요.\n");
				break;
			}
		}
	}
}


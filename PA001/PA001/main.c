//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit
#include "essentials.h"

int main() {
	//�л� ����
	printf("��ǻ�Ͱ��к� 202211390 ���ؿ�\n");
	printf("����ȯ��: Windows 11 64bit\n");

	char a;
	int choice;

	while (1) {
		printf("\n 1) 1������, 2) 2������ 3) 3������, 4) 4������, 5) ����");
		printf("\n��ȣ �Է�: ");
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
				printf("\n���� ������ ���� ���� ���ڸ� �Է����ּ���!");
				//while (getchar() != '\n');
				break;
			}
		}
		else {
			printf("\n��ȣ�� �Է����ֽñ� �ٶ��ϴ�!");
			//while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
}

void factorialOne2Ten() { //1�� ���� �Լ�
	for (int i = 0; i < 10;i++) {
		printf("\ninput number: %d", (i+1));
		printf("\nrecursive: %d", fact_rec(i+1));
		printf("\n");
		printf("iteration: %d\n", fact_it(i+1));
	}
}
void fibonacciOne2Ten() { //2�� ���� �Լ�
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
void showSOFonREC() { //3�� ���� �Լ�
	int n;
	printf("������ �Է����ּ���: ");
	scanf("%d", &n);
	printf("\ninput number: %d", n);
	for (int i = 0; i < n;i++) {
		printf("\nrecursive: %d", fact_rec(i + 1));
		printf("\n");
	}
	
}
void showIterationIsFine() { //4�� ���� �Լ�
	int n;
	printf("������ �Է����ּ���: ");
	scanf("%d", &n);
	printf("\ninput number: %d", n);
	for (int i = 0; i < n;i++) {
		printf("\niteration: %d\n", fact_it(i + 1));
		printf("\n");
	}
}
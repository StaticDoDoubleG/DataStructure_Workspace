//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit

#include "functions.h"

int main() {
	//�л� ����
	printf("��ǻ�Ͱ��к� 202211390 ���ؿ�\n");
	printf("����ȯ��: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n����� �����ϼ���.\n1/ Push n���� �� Pop n���� ���� ��\n2/ Push Pop 1�� Time Complexity\n3/ Array 2�� ���� �� ����ð� ���� ����\n4/ Push 1�� �� Pop 1���� n���� ���� ��\n5/ ����\n\n���� ��ȣ: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
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
				printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
				break;
			}
		}
	}
}

void pnpnTime() { //1�� ���� �Լ�
	printf("\nPush n���� �� Pop n���� ���� ��\n");
	printf("\n**Dynamic Array**");
	for (int i = 1; i <= 10; i++) {
		printf("\nDynamic Array���� %d0�� ����ð�: %d", i * 10, pnpnDnstk(i));
	}
	printf("\n\n**Linked List**");
	for (int i = 1; i <= 10; i++) {
		printf("\nLinked List���� %d0�� ����ð�: %d", i * 10, pnpnLnstk(i));
	}
	printf("\n");
}

void p1p1Time() { //2�� ���� �Լ�
	printf("\nPush Pop 1�� Time Complexity\n");
	printf("\nDynamic Array���� ����\n");
	for (int i = 1; i <= 10; i++) {
		pnpnDnstk_measure(i);
	}
	printf("\n\nLinked List���� ����\n");
	for (int i = 1; i <= 10; i++) {
		pnpnLnstk_measure(i);
	}
	//measureTimeComplexity();
	printf("\n");
}

void doublingTime() { //3�� ���� �Լ�
	printf("\nArray 2�� ���� �� ����ð� ���� ����\n");
	Dnstk10M();
	printf("\n");
}

void p1p1RotateTime() { //4�� ���� �Լ�
	printf("\nPush 1�� �� Pop 1���� n���� ���� ��\n");
	printf("\n**Dynamic Array**");
	for (int i = 1; i <= 10; i++) {
		printf("\nDynamic Array���� %d0�� ����ð�: %d", i * 10, p1p1RotateDnstk(i));
	}
	printf("\n\n**Linked List**");
	for (int i = 1; i <= 10; i++) {
		printf("\nLinked List���� %d0�� ����ð�: %d", i * 10, p1p1RotateLnstk(i));
	}
	printf("\n");
}
//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit

#include "functions.h"

int main() {
	//�л� ����
	printf("��ǻ�Ͱ��к� 202211390 ���ؿ�\n");
	printf("����ȯ��: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n����� �����ϼ���.\n1/ Insert Randomly\n2/ Insert in Order\n3/ Random Test\n4/ ����\n\n���� ��ȣ: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
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
				printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
				break;
			}
		}
	}
}

void RIRF() {
	printf("\n1/ Insert Randomly Find Randomly\n");
	printf("\nBinary Search Tree���� ����\n");
	BST_RIRF();
	printf("\nBalanced Binary Search Tree���� ����\n");
	BBST_RIRF();
}

void OIRF() {
	printf("\n2/ Insert in Order Find Randomly\n");
	printf("\nBinary Search Tree���� ����\n");
	BST_OIRF();
	printf("\nBalanced Binary Search Tree���� ����\n");
	BBST_OIRF();
}

void RandomTest() {
	for (int i = 1; i <= 10; i++) {
		printf("\n<%d0���� ���>\n", i);
		for (int j = 1; j <= 10; j++) {
			printf("���� ��: %d\n", RandomReturn(i * 100000));
		}
	}
}
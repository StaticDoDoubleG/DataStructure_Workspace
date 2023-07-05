//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit

#include "functions.h"

int main() {
	//�л� ����
	printf("��ǻ�Ͱ��к� 202211390 ���ؿ�\n");
	printf("����ȯ��: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n����� �����ϼ���.\n1/ Linear search time complexity \n2/ Binary search time complexity\n3/ ����\n\n���� ��ȣ: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
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
				printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
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
		printf("����: %d\n", RandomReturn(10));
	}
}
//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit

#include "functions.h"

int main() {
	//�л� ����
	printf("��ǻ�Ͱ��к� 202211390 ���ؿ�\n");
	printf("����ȯ��: Windows 11 64bit\n");

	while (1) {

		int num;

		printf("\n����� �����ϼ���.\n0/ Sort Check\n1/ Sort Random Data\n2/ Sort Ordered Data\n3/ ����\n\n���� ��ȣ: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
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
				printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
				break;
			}
		}
	}
}


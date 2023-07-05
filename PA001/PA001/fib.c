//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit
#include "essentials.h"

int fib_rec(int n) {
	if (n == 0) { //ù��° �Ǻ���ġ ���� 0�̴�.
		return 0;
	}
	else if (n == 1) { //�ι�° �Ǻ���ġ ���� 1�̴�.
		return 1;
	}
	else { //����° �Ǻ���ġ �����ʹ� �� �� �� ���� ���̴�.
		return fib_rec(n - 1) + fib_rec(n - 2);
	}
}

int fib_it(int n) {
	int a = 0;
	int b = 1;
	int next = 0;

	for (int i = 0; i < n; i++) {
		next = a + b;
		a = b;
		b = next;
	}
	return a;
}
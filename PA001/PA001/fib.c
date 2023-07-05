//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit
#include "essentials.h"

int fib_rec(int n) {
	if (n == 0) { //첫번째 피보나치 수는 0이다.
		return 0;
	}
	else if (n == 1) { //두번째 피보나치 수는 1이다.
		return 1;
	}
	else { //세번째 피보나치 수부터는 그 전 두 수의 합이다.
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
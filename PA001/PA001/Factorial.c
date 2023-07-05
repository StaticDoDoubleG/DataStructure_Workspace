//컴퓨터공학부 202211390 최준원
//실행환경: Windows 11 64bit
#include "essentials.h"

int fact_rec(int n) {
	// base case: 0! = 1, 1! = 1	
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	// recursion step: (n-1)!에 n을 곱함
	else
		return n * fact_rec(n - 1);
}

int fact_it(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}
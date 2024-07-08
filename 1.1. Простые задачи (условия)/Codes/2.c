#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double A, B, C;

	scanf("%lf", &A);
	scanf("%lf", &B);
	scanf("%lf", &C);
	printf("%lf\n", A * B * C);

	return 0;
}

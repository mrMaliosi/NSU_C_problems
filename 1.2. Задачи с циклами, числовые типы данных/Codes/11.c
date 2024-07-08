#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	scanf("%d", &N);
	long long answer = 0;
	for (int a = 1; a*a*a <= N; ++a)
	{
		for (int b = a; a*b*b <= N; ++b)
		{
			answer += N / (b*a) - b + 1;
		}
	}

	printf("%lld", answer);
	return 0;
}

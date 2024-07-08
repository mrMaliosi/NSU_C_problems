#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[10005] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, x;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		q[x] += 1;
	}

	for (int i = 1; i < 10005; ++i)
	{
		if (q[i] != 0)
		{
			printf("%d: %d\n", i, q[i]);

		}
	}

	return 0;
}

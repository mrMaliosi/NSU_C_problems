#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[1000005] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; ++i)
	{
		if (q[i] == 0)
		{
			for (int j = i + i; j <= N; j += i)
			{
				q[j] = -1;
			}
		}

	}


	for (int i = 2; i <= N; ++i)
	{
		if (q[i] == 0) printf("%d ", i);
	}

	return 0;
}

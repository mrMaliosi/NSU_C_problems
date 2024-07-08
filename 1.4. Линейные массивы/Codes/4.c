#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[1005] = { 0 };
int o[1005] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, x, ans = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		if (x >= 0) q[x] += 1;
		else o[-x] += 1;
	}

	for (int i = 0; i < 1005; ++i)
	{
		if (q[i] > 0)
		{
			++ans;
		}

		if (o[i] > 0)
		{
			++ans;
		}
	}

	printf("%d", ans);
	return 0;
}


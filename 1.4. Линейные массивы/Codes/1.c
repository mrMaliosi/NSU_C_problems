#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, x, ans = 0;
	int q[105];
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &q[i]);
	}

	for (int j = 0; j < N; ++j)
	{
		ans = 0;
		for (int i = j + 1; i < N; ++i)
		{
			if (q[j] > q[i]) ++ans;
		}
		printf("%d ", ans);
	}


	return 0;
}

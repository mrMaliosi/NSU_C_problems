#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[100005];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &q[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		ans = 0;
		for (int j = i; j <= N; j += i)
		{
			ans += q[j];
		}

		printf("%d\n", ans);
	}



	return 0;
}

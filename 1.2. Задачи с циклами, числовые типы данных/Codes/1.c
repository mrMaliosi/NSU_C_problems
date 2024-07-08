#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		ans += i;
	}

	printf("%d\n", ans);

	return 0;
}

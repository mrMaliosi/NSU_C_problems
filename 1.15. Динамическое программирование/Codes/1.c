#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[45];


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 3;
	scanf("%d", &N);
	for (int i = 3; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%d", dp[N]);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[10005][105];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, K, ost;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &dp[i][0]);
	}

	for (int i = 0; i < K; ++i)
	{
		dp[0][i + 1] = i;
	}

	ost = dp[1][0] % K;
	if (ost < 0)
	{
		ost = K + ost;
	}
	dp[1][ost + 1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		ost = dp[i][0] % K;
		if (ost < 0)
		{
			ost = K + ost;
		}
		for (int j = 1; j <= K; ++j)
		{
			if (dp[i - 1][j] == 1)
			{
				dp[i][(j - 1 + ost) % K + 1] = 1;
				if (j - 1 - ost < 0)
				{
					dp[i][K + (j - 1 - ost) + 1] = 1;
				}
				else
				{
					dp[i][j - ost] = 1;
				}
			}
		}
	}

	if (dp[N][1] == 1)
	{
		printf("Divisible");
	}
	else
	{
		printf("Not divisible");
	}

	return 0;
}

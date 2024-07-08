#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[105][30005];
int T[30005];
int G[205][30005];

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	return b;
}

int main() {								//Ну что ж, пора делать деньги)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, K, Time, tmax = -1;
	scanf("%d %d %d", &N, &K, &Time);
	int t;
	for (int i = 0; i < N; ++i)					//Ввод времени
	{
		scanf("%d", &t);
		T[i] = t;
		if (t > tmax)
		{
			tmax = t;
		}
	}

	int p;										//приведение массива Ганстеров к рабочему состоянию
	for (int i = 0; i < 205; ++i)
	{
		for (int j = 0; j < 30005; ++j)
		{
			G[i][j] = -1;
		}
	}

	int k;										//суммы
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &p);
		k = 0;
		while (G[k][T[i]] != -1)
		{
			k += 2;
		}
		G[k][T[i]] = p;
	}

	int s;										//плечи
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &s);
		k = 1;
		while (G[k][T[i]] != -1)
		{
			k += 2;
		}
		G[k][T[i]] = s;
	}

	k = 1;
	while (-1 != G[k][0])
	{
		if (0 == G[k][0])
		{
			dp[0][0] += G[k - 1][0];
		}
		k += 2;
	}

	for (int i = 1; i <= tmax; ++i)
	{
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		k = 1;
		while (-1 != G[k][i])
		{
			if (0 == G[k][i])
			{
				dp[0][i] += G[k - 1][i];
			}
			k += 2;
		}

		for (int j = 1; (j <= K) && (j <= i); ++j)
		{
			dp[j][i] = max(dp[j - 1][i - 1], max(dp[j][i - 1], dp[j + 1][i - 1]));
			k = 1;
			while (-1 != G[k][i])
			{
				if (j == G[k][i])
				{
					dp[j][i] += G[k - 1][i];
				}
				k += 2;
			}
		}
	}

	int maxi = 0;
	for (int j = 0; (j <= K) && (j <= tmax); ++j)
	{
		if (dp[j][tmax] > maxi)
		{
			maxi = dp[j][tmax];
		}
	}

	printf("%d", maxi);

	return 0;
}

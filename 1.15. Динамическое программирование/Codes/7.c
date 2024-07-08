#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[265][265];
char letters[265];
int numbers[265];
char numeric[265];

int code(char a)
{
	if ((a == 'A') || (a == 'B') || (a == 'C'))
	{
		return 2;
	}
	if ((a == 'D') || (a == 'E') || (a == 'F'))
	{
		return 3;
	}
	if ((a == 'G') || (a == 'H') || (a == 'I'))
	{
		return 4;
	}
	if ((a == 'J') || (a == 'K') || (a == 'L'))
	{
		return 5;
	}
	if ((a == 'M') || (a == 'N'))
	{
		return 6;
	}
	if ((a == 'P') || (a == 'R') || (a == 'S'))
	{
		return 7;
	}
	if ((a == 'T') || (a == 'U') || (a == 'V'))
	{
		return 8;
	}
	if ((a == 'W') || (a == 'X') || (a == 'Y'))
	{
		return 9;
	}
	if ((a == 'O') || (a == 'Q') || (a == 'Z'))
	{
		return 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Nl, Nn;
	int i, j;
	scanf("%s\n", &letters);
	scanf("%s", &numeric);

	for (j = 0; numeric[j] != '\0'; ++j)
	{
		dp[0][j] = j;
		numbers[j] = numeric[j] - '0';
	}
	dp[0][j] = j;
	Nn = j;

	for (j = 0; letters[j] != '\0'; ++j)
	{
		dp[j][0] = j;
	}
	dp[j][0] = j;
	Nl = j;

	for (i = 1; i <= Nl; ++i)						//Алгоритм Ахо (алгоритм Вагнера-Фишера)
	{
		for (j = 1; j <= Nn; ++j)
		{
			if (code(letters[i - 1]) == numbers[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				if (dp[i][j - 1] <= dp[i - 1][j])
				{
					dp[i][j] = dp[i][j - 1] + 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + 1;
				}

			}
		}
	}

	/*for (int i = 0; i <= Nl; ++i)
	{
		for (j = 0; j <= Nn; ++j)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/

	int count = 0;
	i = Nl;
	j = Nn;
	while ((i > 0) && (j > 0))
	{
		if ((dp[i - 1][j] <= dp[i][j - 1]) && (dp[i - 1][j] < dp[i][j]))
		{
			--i;
		}
		else if ((dp[i][j - 1] <= dp[i - 1][j]) && (dp[i][j - 1] < dp[i][j]))
		{
			--j;
		}
		else if (dp[i][j] == dp[i - 1][j - 1])
		{
			--i;
			--j;
			++count;
		}
	}

	printf("%d", count);

	return 0;
}

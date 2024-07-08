#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int dp[1005][1005];

int main() {									//О мой бог, первая задача, которой не было в презентации!
	freopen("input.txt", "r", stdin);			//Спустя час в пэинте... Ладно, я понял, почему большинство задач даны в презентации
	freopen("output.txt", "w", stdout);			//Спустя ещё час... ПАМАГИТЕ!!!
	unsigned int N;					//Итак, я прочитал вики ИТМО. Ну, я был довольно близок в своих рассуждениях. Надо было протсо не 
	scanf("%u", &N);							//увлекаться циклами

	for (unsigned int i = 0; i <= N; ++i)
	{
		dp[0][i] = 1;
	}

	for (unsigned int i = 1; i <= N; ++i)
	{
		for (unsigned int j = 1; j <= N; ++j)
		{
			if (j <= i)
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - j][j]) % 1000000007;
			}
			else
			{
				dp[i][j] = dp[i][i];
			}
		}
	}

	printf("%u", dp[N][N]);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[20][20];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M, a, l;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		l = 0;
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &a);
			if (a == 1)
			{
				++l;
			}
			else if (l != 0)
			{
				printf("%d ", l);
				l = 0;
			}
			q[i][j] = a;
		}
		if (l != 0)
		{
			printf("%d\n", l);
		}
		else printf("\n");
	}

	for (int i = 0; i < M; ++i)
	{
		l = 0;
		for (int j = 0; j < N; ++j)
		{
			if (q[j][i] == 1)
			{
				++l;
			}
			else if (l != 0)
			{
				printf("%d ", l);
				l = 0;
			}
		}
		if (l != 0) printf("%d\n", l);
		else printf("\n");
	}

	return 0;
}

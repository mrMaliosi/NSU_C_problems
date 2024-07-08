#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[1000][1000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M, st, y = 0, step = 0;
	char a;
	scanf("%d %d %d", &N, &M, &st);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%c", &a);
			if (a == '\n') --j;
			if (a == 'N') q[i][j] = -1;
			if (a == 'E') q[i][j] = -2;
			if (a == 'S') q[i][j] = -3;
			if (a == 'W') q[i][j] = -4;
		}
	}

	--st;
	while (q[y][st] < 0)
	{
		if (q[y][st] == -1)
		{
			q[y][st] = step;
			++step;
			--y;
		}
		else if (q[y][st] == -2)
		{
			q[y][st] = step;
			++step;
			++st;
		}
		else if (q[y][st] == -3)
		{
			q[y][st] = step;
			++step;
			++y;
		}
		else if (q[y][st] == -4)
		{
			q[y][st] = step;
			++step;
			--st;
		}

		if ((y < 0) || (y == N) || (st < 0) || (st == M))
		{
			printf("%d step(s) to exit", step);
			return 0;
		}
	}



	printf("%d step(s) before a loop of %d step(s)", q[y][st], step - q[y][st]);

	return 0;
}

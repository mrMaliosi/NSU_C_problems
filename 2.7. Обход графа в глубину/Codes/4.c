#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


char q[1005][1005];
int visited[1005][1005];

void DFS(int x, int y, int visited[][1005], char q[][1005], int colour, int N)
{
	visited[x][y] = colour;

	if (x > 0)
	{
		if (visited[x - 1][y] == 0)
		{
			DFS(x - 1, y, visited, q, colour, N);
		}
	}

	if (y > 0)
	{
		if (visited[x][y - 1] == 0)
		{
			DFS(x, y - 1, visited, q, colour, N);
		}
	}

	if (x < N - 1)
	{
		if (visited[x + 1][y] == 0)
		{
			DFS(x + 1, y, visited, q, colour, N);
		}
	}

	if (y < N - 1)
	{
		if (visited[x][y + 1] == 0)
		{
			DFS(x, y + 1, visited, q, colour, N);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	scanf("%d\n", &N);
	char a;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%c", &q[i][j]);
			if (q[i][j] == '*')
			{
				visited[i][j] = -1;
			}
		}
		scanf("%c", &a);
	}

	int colour = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == 0)
			{
				DFS(i, j, visited, q, colour, N);
				++colour;
			}
		}

	}

	--colour;
	printf("%d", colour - 1);
	return 0;
}
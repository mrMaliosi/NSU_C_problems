#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[405][405];
int sum_down[405];
int sum_right[405];
int sum_ch = 0;
int ans[405];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	scanf("%d %d", &N, &M);
	int x, y;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &x, &y);
		if (q[x][y] == 0)
		{
			++sum_down[y];
			++sum_right[x];
		}
		q[x][y] = 1;
	}

	int b = 0;
	for (int i = 1; i <= N; ++i)
	{
		if ((sum_down[i] == 0) && (sum_right[i] != -1))
		{
			ans[b] = i;
			++b;
			for (int j = 1; j <= N; ++j)
			{
				sum_down[j] -= q[i][j];
				q[i][j] *= 0;
			}
			sum_right[i] = -1;
			++sum_ch;
			i = 0;
		}
	}

	if (sum_ch == N)
	{
		for (int i = 0; i < b; ++i)
		{
			printf("%d ", ans[i]);
		}
	}
	else
	{
		printf("bad course");
	}


	return 0;
}

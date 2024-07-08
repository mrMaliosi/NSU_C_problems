#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double q[1500][1500];

void bin_coef(double q[][1500], int n)
{
	q[0][0] = 1;
	q[1][0] = 1;
	q[1][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		q[i][0] = 1;
		for (int j = 1; j < i; ++j)
		{
			q[i][j] = q[i - 1][j - 1] + q[i - 1][j];
		}

		q[i][i] = 1;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = 1000, Q, n, k;
	scanf("%d", &Q);
	bin_coef(q, N);

	for (int i = 0; i < Q; ++i)
	{
		scanf("%d %d", &n, &k);
		printf("%0.10g\n", q[n][k]);
	}

	return 0;
}

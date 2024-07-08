#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double q[1000005];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, r, l = 0, m, ans;
	double X, eps = 1000000000;
	scanf("%d %lf", &N, &X);
	r = N;
	m = (r + l) / 2;

	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &q[i]);
	}

	while ((l <= r) && (X != q[m]))
	{
		if (X < q[m])
		{
			if (q[m] - X <= eps)
			{
				eps = q[m] - X;
				ans = m;
			}
			r = m - 1;
		}
		else
		{
			if (X - q[m] < eps)
			{
				eps = X - q[m];
				ans = m;
			}
			l = m + 1;
		}

		m = (r + l) / 2;
	}

	if (ans == N)
	{
		ans = N - 1;
	}

	if (X == q[m])
	{
		for (int i = 0; i < N; ++i)
		{
			if (q[i] == X)
			{
				printf("%d", i);
				return 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			if (q[ans] == q[i])
			{
				printf("%d", i);
				return 0;
			}
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[1000005];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, X, r, l = 0, m;
	scanf("%d %d", &N, &X);
	r = N;
	m = (r + l) / 2;

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &q[i]);
	}

	while ((l <= r) && (X != q[m]))
	{
		if (X < q[m])
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}

		m = (r + l) / 2;
	}

	if (X == q[m]) printf("%d\n", m);
	else printf("-1");



	return 0;
}

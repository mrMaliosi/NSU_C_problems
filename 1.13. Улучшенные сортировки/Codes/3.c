#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>

int q[300005];
int ans[3000005];

void shuffle(int* q, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		int j = rand() % n;
		int c = q[i];
		q[i] = q[j];
		q[j] = c;
	}
}

void quick_sort(int* q, int l, int r)
{
	int m = q[(l + r) / 2];
	int i = l, j = r, c;
	while (i < j)
	{
		while (q[i] < m)
		{
			++i;
		}

		while (q[j] > m)
		{
			--j;
		}

		if (i <= j)
		{
			c = q[i];
			q[i] = q[j];
			q[j] = c;
			++i;
			--j;
		}
	}

	if (l < j)
	{
		quick_sort(q, l, j);
	}
	if (i < r)
	{
		quick_sort(q, i, r);
	}
}

int repeat_killer3000(int* q, int* ans, int n)			//всё ещё с нами!
{
	ans[0] = q[0];
	int j = 0;
	for (int i = 1; i < n; ++i)
	{
		if (ans[j] != q[i])
		{
			++j;
			ans[j] = q[i];
		}
	}

	return j + 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, l;
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
	}

	shuffle(&q, n);
	quick_sort(&q, 0, n - 1);
	l = repeat_killer3000(&q, &ans, n);

	printf("%d\n", l);
	for (int i = 0; i < l; ++i)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}

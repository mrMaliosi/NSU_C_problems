#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>

int q[1000005];

void shell_sort(int q[], int N)
{
	int h = 1;
	while (h < N / 6)
	{
		h = 3 * h + 1;
	}

	int j, k, x;
	while (h >= 1)
	{
		for (int i = 0; i < h; ++i)
		{
			j = i + h;
			while (j < N)
			{
				x = q[j];
				k = j - h;
				while ((k >= i) && (q[k] > x))
				{
					q[k + h] = q[k];
					k = k - h;
				}
				q[k + h] = x;
				j = j + h;
			}
		}

		h = (h - 1) / 3;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
	}
	shell_sort(q, n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", q[i]);
	}

	return 0;
}

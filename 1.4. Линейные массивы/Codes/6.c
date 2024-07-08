#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[5500];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, maxi = 0, mini_l = 0, mini_r = 0, s = 0, l = 0, r, ans = 0;
	scanf("%d", &n);
	r = n - 1;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
		ans += q[i];
	}

	for (int i = 0; i < n; ++i)
	{
		maxi += q[i];
		s += q[n - 1 - i];

		if (maxi < 0)
		{
			if (i + 1 <= r)
			{
				maxi = 0;
				l = i + 1;
			}

		}

		if (s <= 0)
		{
			if (n - i - 2 >= l)
			{
				s = 0;
				r = n - i - 2;
			}
		}
	}

	for (int i = 0; i < l; ++i)
	{
		mini_l += q[i];
	}

	for (int i = n - 1; i > r; --i)
	{
		mini_r += q[i];
	}

	if (l == r)
	{
		maxi = -99999;
		for (int i = 0; i < n; ++i)
		{
			if (maxi < q[i])
			{
				maxi = q[i];
				l = i;
				r = i;
			}
		}

		printf("%d %d %d", l, r, maxi);
		return 0;
	}

	printf("%d %d %d", l, r, ans - mini_r - mini_l);

	return 0;
}

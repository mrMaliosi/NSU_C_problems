
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long q[1000005];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long n, k, x;
	scanf("%lld %lld", &n, &k);
	k = k % (n + 1);

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &q[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		x = q[(i + k) % k];
		q[(i + k) % k] = q[i];
		q[i] = x;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%lld ", q[i]);
	}

	printf("\n");

	return 0;
}
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[100005];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, x;
	scanf("%d %d", &n, &k);
	k = k % n;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
	}


	for (int i = 0; i < n / 2; ++i)
	{
		x = q[i];
		q[i] = q[n - 1 - i];
		q[n - 1 - i] = x;
	}

	for (int i = 0; i < k / 2; ++i)
	{
		x = q[i];
		q[i] = q[k - 1 - i];
		q[k - 1 - i] = x;
	}

	for (int i = k; i <= (n - 1 + k) / 2; ++i)
	{
		x = q[i];
		q[i] = q[n - 1 - i + k];
		q[n - 1 - i + k] = x;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", q[i]);
	}

	printf("\n");

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, p, k, l, x;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &p);
	scanf("%d", &k);
	scanf("%d", &l);

	if ((m % (l*(p - 1) + k)) != 0) x = m / (l*(p - 1) + k) + 1;
	else x = m / (l*(p - 1) + k);
	if ((n % (l*x)) != 0) p = n / (l*x) + 1;
	else p = n / (l*x);
	if (((n % (l*x)) % x) != 0) k = (n % (l*x))/x + 1;
	else k = (n % (l*x)) / x;

	printf("%d %d", p, k);
	return 0;
}
*/

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, p, k, l, x;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &p);
	scanf("%d", &k);
	scanf("%d", &l);

	x = (m - 1) / (l*(p - 1) + k) + 1;
	p = (n - 1) / (l*x) + 1;
	k = ((n - 1) % (l*x)) / x + 1;


	printf("%d %d", p, k);
	return 0;
}

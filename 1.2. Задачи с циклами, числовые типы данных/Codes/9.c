#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double x, ans = 0, eps, y = 0, r, i = 1;
	scanf("%lf", &x);
	scanf("%lf", &eps);
	r = x;
	while ((r > eps)||(-r > eps))
	{
		y += r;
		r = ((r * i) * x * x) / (i + 2);
		i += 2;
		r = -r;
	}
	y += r;

	printf("%0.5lf", y);
	return 0;
}
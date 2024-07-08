#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double a, b, c;
	double x, x2 = 0.00000;
	scanf("%lf %lf %lf", &a, &b, &c);
	if ((a == 0) && (b == 0) && (c != 0)) printf("ERROR");
	else if ((a == 0) && (b == 0) && (c == 0)) printf("MANY");
	else if (((a > 0) && (b == 0) && (c > 0)) || ((a < 0) && (b == 0) && (c < 0))) printf("ERROR");
	else if ((a == 0) && (b != 0))
	{
		x = (-c) / b;
		printf("1\n%0.5lf", x);
	}
	else if (((a > 0) && (b == 0) && (c < 0)) || ((a < 0) && (b == 0) && (c > 0)))
	{
		x = sqrt((-c)/a);
		printf("2\n%0.5lf %0.5lf", -x, x);
	}
	else if ((a != 0) && (b == 0) && (c == 0)) printf("1\n%0.5lf", 0);
	else if ((a != 0) && (b != 0) && (c == 0))
	{
		x = min((-b) / a, 0);
		x2 = max((-b) / a, 0);
		printf("2\n%0.5lf %0.5lf", x, x2);
	}
	else if (b*b - 4 * a*c < 0)
	{
		printf("NO");
	}
	else if (b*b - 4 * a*c == 0)
	{
		x = -b / (2 * a);
		printf("1\n%0.5lf", x);
	}
	else
	{
		x = min(((-b) + sqrt(b*b - 4 * a*c)) / (2 * a), ((-b) - sqrt(b*b - 4 * a*c)) / (2 * a));
		x2 = max(((-b) + sqrt(b*b - 4 * a*c)) / (2 * a), ((-b) - sqrt(b*b - 4 * a*c)) / (2 * a));
		printf("2\n%0.5lf %0.5lf", x, x2);
	}

	return 0;
}

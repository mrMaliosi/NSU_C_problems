#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x1, y1, x2, y2, x3, y3;
	double a, b, c, p, s;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);

	a = sqrt((pow((x2 - x1), 2) + pow((y2 - y1),2)));
	b = sqrt((pow((x3 - x2), 2) + pow((y3 - y2), 2)));
	c = sqrt((pow((x3 - x1), 2) + pow((y3 - y1), 2)));
	p = a + b + c;
	s = sqrt((p / 2)*((p / 2) - a)*((p / 2) - b)*((p / 2) - c));

	printf("%0.3lf\n", p);
	printf("%0.3lf", s);

	return 0;
}

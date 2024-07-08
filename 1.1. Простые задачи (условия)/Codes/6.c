#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x, y, z;
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	if (x <= 0)
	{
		printf("-1");
		return 0;
	}
	if (y <= 0)
	{
		printf("-2");
		return 0;
	}
	if (z <= 0)
	{
		printf("-3");
		return 0;
	}

	printf("%d\n", 2*x*y + 2*y*z + 2*x*z);

	return 0;
}

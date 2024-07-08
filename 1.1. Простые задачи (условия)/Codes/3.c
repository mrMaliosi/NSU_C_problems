#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (a < b)
	{
		if (a < c)
		{
			printf("%d\n", a);
		}
		else
		{
			printf("%d\n", c);
		}
	}
	else
	{
		if (b < c)
		{
			printf("%d\n", b);
		}
		else 
		{
			printf("%d\n", c);
		}
	}

	return 0;
}

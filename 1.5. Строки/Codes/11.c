#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a;
	int c = 0, j = 10, sum = 0, b;
	scanf("%c", &a);
	while (a != '.')
	{
		if ((a >= '0') && (a <= '9'))
		{
			b = a - '0';
			c = c*j + b;
		}
		else
		{
			sum += c;
			c = 0;
		}
		scanf("%c", &a);
	}

	sum += c;

	printf("%d\n", sum);

	return 0;
}

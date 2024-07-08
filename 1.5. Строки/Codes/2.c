#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int d = 1;
	char a;
	scanf("%c", &a);

	while (a != '.')
	{
		if ((d == 2) && (a != 'A'))
		{
			printf("DOES NOT FIT");
			return 0;
		}

		scanf("%c", &a);
		++d;
	}

	if (d == 4)
	{
		printf("FITS");
	}
	else
	{
		printf("DOES NOT FIT");
	}
	

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a[100], b[100];
	scanf("%s %s", a, b);

	if (strcmp(a, "purple") == 0)
	{
		for (int i = 0; i < strlen(b); ++i)
		{
			if ((b[i] == 'R') || (b[i] == 'B'))
			{
				printf("%d ", i + 1);
			}
		}
	}

	if (strcmp(a, "green") == 0)
	{
		for (int i = 0; i < strlen(b); ++i)
		{
			if ((b[i] == 'Y') || (b[i] == 'B'))
			{
				printf("%d ", i + 1);
			}
		}
	}

	if (strcmp(a, "orange") == 0)
	{
		for (int i = 0; i < strlen(b); ++i)
		{
			if ((b[i] == 'R') || (b[i] == 'Y'))
			{
				printf("%d ", i + 1);
			}
		}
	}

	return 0;
}

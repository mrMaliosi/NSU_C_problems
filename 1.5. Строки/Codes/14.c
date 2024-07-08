#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a;
	int s = 0;
	while (scanf("%c", &a) == 1)
	{
		if (s == 0)
		{
			if (a == '/')
			{
				s = 1;
			}
			else
			{
				printf("%c", a);
			}
		}
		else if (s == 1)
		{
			if (a == '/')
			{
				s = 2;
			}
			else if (a == '*')
			{
				s = 3;
			}
			else
			{
				s = 0;
				printf("/%c", a);
			}
		}
		else if (s == 2)		
		{
			if (a == '\n')
			{
				s = 0;
				printf("\n");
			}
		}
		else if (s == 3)
		{
			if (a == '*')
			{
				s = 4;
			}
			if (a == '\n')
			{
				printf("\n");
			}
		}
		else if (s == 4)
		{
			if (a == '/')
			{
				s = 0;
			}
			else if (a == '\n')
			{
				s = 3;
				printf("\n");
			}
			else
			{
				s = 3;
			}
		}

	}

	return 0;
}

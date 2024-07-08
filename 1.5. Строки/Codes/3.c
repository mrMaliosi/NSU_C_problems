#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a[1000], b = 'a';
	int ch = 0;
	fgets(a, sizeof(a), stdin);

	for (int i = 0; a[i] != '\0'; ++i)
	{
		if (a[i] == ' ')
		{
			if (ch == 1)
			{
				ch = 0;
				++b;
			}
			else
			{
				if ((b - 'a') % 2 == 0)
				{
					printf("PLAYER 2");
					return 0;
				}
				else
				{
					printf("PLAYER 1");
					return 0;
				}
			}
		}
		else if (a[i] == b)
		{
			ch = 1;
		}
	}

	if (ch == 1)
	{
		printf("NO WINNER");
	}
	else
	{
		if ((b - 'a') % 2 == 0)
		{
			printf("PLAYER 2");
			return 0;
		}
		else
		{
			printf("PLAYER 1");
			return 0;
		}
	}

	

	return 0;
}

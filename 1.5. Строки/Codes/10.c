#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int q[27] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a, b[200];
	int ch = 1, len = 0;
	scanf("%c", &a);
	q[a - 'a'] = 1;

	while (a != ' ')
	{
		scanf("%c", &a);
		q[a - 'a'] = 1;
	}


	while (a != '\n')
	{
		scanf("%c", &a);
		if (a == ' ')
		{
			if (ch == 1)
			{
				for (int i = 0; i < len; ++i)
				{
					printf("%c", b[i]);
				}
				printf("\n");
			}
			len = 0;
			ch = 1;
		}
		else
		{
			if (q[a - 'a'] == 1)
			{
				ch = 0;
			}
			else
			{
				b[len] = a;
				++len;
			}
		}
	}

	if (ch == 1)
	{
		for (int i = 0; i < len; ++i)
		{
			printf("%c", b[i]);
		}
	}
	printf("\n");

	return 0;
}

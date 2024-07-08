#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q[30] = { 0 };
	char a, b[30];
	scanf("%c", &a);

	while (a != ' ')
	{
		q[a - 'A'] = 1;
		scanf("%c", &a);
	}

	scanf("%s", &b);
	for (int i = 0; b[i] != '\0'; ++i)
	{
		q[b[i] - 'A'] = 0;
		scanf("%c", &a);
	}

	int ch = 1;
	for (int i = 0; i < 26; ++i)
	{
		if (q[i] == 1)
		{
			printf("%c", 'A' + i);
			ch = 0;
		}
	}

	if (ch == 1) printf("Empty Set");


	return 0;
}

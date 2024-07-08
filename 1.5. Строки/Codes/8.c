#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a;
	int ch = 0, ans = 0;
	scanf("%c", &a);
	while (a != '\n')
	{
		if (a != '.')
		{
			ch = 1;
		}
		else
		{
			if (ch == 1)
			{
				++ans;
				ch = 0;
			}
		}
		scanf("%c", &a);
	}

	if (ch == 1) ++ans;

	printf("%d\n", ans);

	return 0;
}

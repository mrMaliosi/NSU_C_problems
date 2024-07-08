#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char * start, int len)
{
	int x;
	for (int i = 0; i < len / 2; ++i)
	{
		x = start[i];
		start[i] = start[len - 1 - i];
		start[len - 1 - i] = x;
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char a[200];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", a);
		reverse(a, strlen(a));
		printf("%s\n", a);
	}

	return 0;
}

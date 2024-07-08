#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a[100];
	int l;
	scanf("%s", a);

	l = strlen(a);
	if (a[l - 2] == 'e')
	{
		a[l - 1] = 'r';
		a[l] = '\0';
	}
	else if ((a[l - 2] == 'r') && (a[l - 3] == 'e'))
	{
		a[l - 2] = 's';
		a[l - 1] = 't';
		a[l] = '\0';
	}
	else
	{
		a[l - 1] = 'e';
		a[l] = 'r';
		a[l + 1] = '\0';
	}

	printf("%s", a);


	return 0;
}

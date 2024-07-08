#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a, p;				//p - предыдущий элемент
	int s = 0;
	scanf("%c", &a);

	for (int i = 0; a != '.'; ++i)
	{
		p = a;
		s += a - '0';
		scanf("%c", &a);
	}

	if ((s % 3 == 0) && ((p - '0') % 5 == 0))
	{
		printf("YES");
	}
	else printf("NO");
	

	return 0;
}

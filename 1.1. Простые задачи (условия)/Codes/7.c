#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int h, m, s, k;
	scanf("%d", &h);
	scanf("%d", &m);
	scanf("%d", &s);
	scanf("%d", &k);

	k += h * 3600 + m * 60 + s;
	h = (k / 3600) % 24;
	m = (k / 60) % 60;
	s = k% 60;



	printf("%d", h);
	printf(" ");
	printf("%d", m);
	printf(" ");
	printf("%d", s);

	return 0;
}

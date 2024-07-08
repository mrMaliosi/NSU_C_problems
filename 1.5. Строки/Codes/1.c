#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a[4];
	scanf("%s", a);

	if (strcmp(a, "Mon") == 0) printf("1");
	if (strcmp(a, "Tue") == 0) printf("2");
	if (strcmp(a, "Wed") == 0) printf("3");
	if (strcmp(a, "Thu") == 0) printf("4");
	if (strcmp(a, "Fri") == 0) printf("5");
	if (strcmp(a, "Sat") == 0) printf("6");
	if (strcmp(a, "Sun") == 0) printf("7");


	return 0;
}

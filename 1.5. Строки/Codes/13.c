#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char q[10005000];

char * concat(char * pref, char * suff)
{
	while (*suff != '\0') 
	{
		++pref;
		*pref = *suff;
		++suff;
	}
	
	return pref;
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char* p;
	char a[200];
	scanf("%d", &n);
	q[0] = '\0';

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", a);
		p = concat(q, a);
		*q += *p;
	}

	printf("%s\n", q);
	return 0;
}

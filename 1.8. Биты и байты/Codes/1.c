#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <malloc.h>

typedef unsigned int BARR_ELTYPE;
#define BARR_ELBITS (CHAR_BIT * sizeof(BARR_ELTYPE))
#define BARR_FREE(barr) free(barr)																//обнуление битового массива
#define VALUE_BITS(barr) (CHAR_BIT * sizeof(unsigned long))										//количество бит

BARR_ELTYPE bitarray[BARR_ELBITS] = { 0 };

unsigned long bit_count2(unsigned long a)
{
	int ans = 0, ansm = 0;
	while (a != 0)
	{
		if (a & 1)
		{
			++ans;
		}
		else
		{
			ansm = max(ans, ansm);
			ans = 0;
		}
		a >>= 1;
	}

	ansm = max(ans, ansm);
	return ansm;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, ans;
	scanf("%d", &a);
	ans = bit_count2(a);
	printf("%d", ans);

	return 0;
}
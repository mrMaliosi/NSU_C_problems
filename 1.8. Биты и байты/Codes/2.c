#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

typedef unsigned int BARR_ELTYPE;
#define BARR_ELBITS (CHAR_BIT * sizeof(BARR_ELTYPE))	
#define VALUE_BITS (CHAR_BIT * sizeof(unsigned long))	

void vivod_rev(unsigned int a)
{
	for (int i = 0; i < BARR_ELBITS; ++i)
	{
		printf("%d", a & 1);
		a >>= 1;
	}
	printf("\n");
}

unsigned long bit_rev1(unsigned long a)
{
	unsigned long ans = 0;
	int i;

	for (i = 0; i < VALUE_BITS; ++i)
	{
		ans = (ans << 1) | (a & 1);
		a >>= 1;
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	scanf("%d", &a);
	b = bit_rev1(a);
	vivod_rev(b);
	printf("%d\n", b);
	vivod_rev(a);

	return 0;
}

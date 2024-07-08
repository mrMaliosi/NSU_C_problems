#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

typedef unsigned int BARR_ELTYPE;
#define BARR_ELBITS (CHAR_BIT * sizeof(BARR_ELTYPE))	
#define VALUE_BITS (CHAR_BIT * sizeof(unsigned long))	

unsigned long bit_2(unsigned long a)
{
	unsigned long ans = 1;
	int i;

	for (i = 0; (a & 1) != 1; ++i)
	{
		if ((a & 1) != 1)
		{
			ans *= 2;
		}
		else
		{
			return ans;
		}
		a >>= 1;
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, N, b;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a);
		b = bit_2(a);
		printf("%d\n", b);
	}

	return 0;
}
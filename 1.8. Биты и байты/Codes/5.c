#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

typedef unsigned int bitword;
#define VALUE_BITS (CHAR_BIT * sizeof(bitword))
bitword q[1000000];


void bitsetSet(bitword* arr, int idx, int newval)		//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
{
	int i = idx / VALUE_BITS;
	int j = idx % VALUE_BITS;
	if (newval == 1)
	{
		newval = newval << (VALUE_BITS - 1 - j);
		arr[i] |= newval;
	}
	else
	{
		newval = 1;
		newval = newval << (VALUE_BITS - 1 - j);
		newval = ~newval;
		arr[i] &= newval;
	}

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M, num, idx, newval, left, right, ans;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &q[i]);
	}

	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &newval, &idx);
		bitsetSet(q, idx, newval);
	}

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", q[i]);
	}
	return 0;
}
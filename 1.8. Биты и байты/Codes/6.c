#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

typedef unsigned int bitword;
#define VALUE_BITS (CHAR_BIT * sizeof(bitword))
bitword q[1000000];

void bitsetZero(bitword* arr, int num)			//инициализирует массив битов длины num, устанавлива€ все его биты в ноль
{
	for (int i = 0; i < (num - 1) / VALUE_BITS + 1; ++i)
	{
		*(arr + i) = 0;
	}
}

int bitsetGet(const bitword* arr, int idx);		//возвращает значение idx-ого бита (0 или 1) //ѕќ„≈ћ”??????????

int bitsetGet(const bitword* arr, int idx)
{
	int i = idx / VALUE_BITS;
	int j = idx % VALUE_BITS;
	int b = 1 << (VALUE_BITS - 1 - j);
	return b & arr[i] ? 1 : 0;
}


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

//возвращает 1, если среди битов с номерами k
//дл€ left <= k < right есть единичный, и 0 иначе
int bitsetAny(const bitword* arr, int left, int right)
{
	int i = left / VALUE_BITS;
	int j = left % VALUE_BITS;
	int b = 1;
	while (i * VALUE_BITS + j < right)
	{
		if (j == VALUE_BITS)
		{
			j = 0;
			++i;
			while (arr[i] == 0)
			{
				++i;
				if (i * VALUE_BITS >= right)
				{
					return 0;
				}
			}
		}

		b = 1 << (VALUE_BITS - 1 - j);
		if (arr[i] & b)
		{
			return 1;
		}
		++j;
	}

	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, t, num, idx, newval, left, right, ans;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &t);
		if (t == 0)
		{
			scanf("%d", &num);
			bitsetZero(q, num);
		}
		else if (t == 1)
		{
			scanf("%d", &idx);
			ans = bitsetGet(q, idx);
			printf("%d\n", ans);
		}
		else if (t == 2)
		{
			scanf("%d %d", &idx, &newval);
			bitsetSet(q, idx, newval);
		}
		else if (t == 3)
		{
			scanf("%d %d", &left, &right);
			if (bitsetAny(q, left, right) == 1)
			{
				printf("some\n");
			}
			else
			{
				printf("none\n");
			}
		}
	}

	return 0;
}
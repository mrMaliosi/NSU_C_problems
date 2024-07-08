#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

typedef unsigned int bitword;

#define VALUE_BITS (CHAR_BIT * sizeof(bitword))

bitword q[1000000];

void bitsetZero(bitword* arr, int num)			//инициализирует массив битов длины num, устанавливая все его биты в ноль
{
	for (int i = 0; i < (num - 1) / VALUE_BITS + 1; ++i)
	{
		*(arr + i) = 0;
	}
}

int bitsetGet(const bitword* arr, int idx);		//возвращает значение idx-ого бита (0 или 1) //ПОЧЕМУ??????????

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
//для left <= k < right есть единичный, и 0 иначе
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

//установить в val значение всех k-ых битов для left <= k < right
void bitsetSetSeg(bitword* arr, int left, int right, int newval)
{
	int i = left / VALUE_BITS;
	int j = left % VALUE_BITS;
	int b = 1;
	while (i * VALUE_BITS + j < right)
	{
		if (newval == 1)
		{
			b = 1 << (VALUE_BITS - 1 - j);
			arr[i] |= b;
		}
		else
		{
			b = 1 << (VALUE_BITS - 1 - j);
			b = ~b;
			arr[i] &= b;
		}
		++j;

		if (j == VALUE_BITS)
		{
			j = 0;
			++i;
			while (i * VALUE_BITS + VALUE_BITS <= right)
			{
				arr[i] = newval * 4294967295;				//2^32 - 1 (все единицы)
				++i;
			}
		}
	}
}

//посчитать, сколько битов равно единице на отрезке left <= k < right
int bitsetCount(const bitword* arr, int left, int right);

int bitsetCount(const bitword* arr, int left, int right)
{
	int ans = 0, value;
	int i = left / VALUE_BITS;
	int j = left % VALUE_BITS;
	unsigned int b = 1, m;
	while (i * VALUE_BITS + j < right)
	{
		b = 1 << (VALUE_BITS - 1 - j);
		if (arr[i] & b)
		{
			++ans;
		}
		else
		{
			m = arr[i];
			b = ~b;
			m &= b;
			if (m == 0)
			{
				j = 31;
			}
		}
		++j;

		if (j == VALUE_BITS)
		{
			j = 0;
			++i;
			while (arr[i] == 0)
			{
				++i;
				if (i * VALUE_BITS >= right)
				{
					return ans;
				}
			}

			while (i * VALUE_BITS + VALUE_BITS <= right)
			{
				value = arr[i];
				value = (value & 0x55555555) + ((value >> 1) & 0x55555555);
				value = (value & 0x33333333) + ((value >> 2) & 0x33333333);
				value = (value & 0x0f0f0f0f) + ((value >> 4) & 0x0f0f0f0f);
				value = (value & 0x00ff00ff) + ((value >> 8) & 0x00ff00ff);
				value = (value & 0x0000ffff) + ((value >> 16) & 0x0000ffff);
				ans += value;
				++i;
			}

			if ((arr[i] < 256) && (i * VALUE_BITS + 24 < right))				//2^24 (оптимизация)
			{
				j += 24;
			}
			else if ((arr[i] < 65536) && (i * VALUE_BITS + 16 < right))				//2^16 (оптимизация)
			{
				j += 16;
			}
			else if ((arr[i] < 16777216) && (i * VALUE_BITS + 8 < right))				//2^8 (оптимизация)
			{
				j += 8;
			}

		}
	}

	return ans;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, t, num, idx, newval, left, right, ans, one;
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
			scanf("%d %d %d", &left, &right, &newval);
			bitsetSetSeg(q, left, right, newval);
		}
		else if (t == 4)
		{
			scanf("%d %d", &left, &right);
			one = bitsetCount(q, left, right);
			printf("%d\n", one);
		}

	}

	return 0;
}
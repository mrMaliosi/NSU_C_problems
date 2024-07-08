#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define simple 9999991
#define base 31

/////////////////Интерфейс целочисленного списка///////////////////
typedef struct List {
	int key;
	int colour;
	char* s;
} list;


list q[simple] = { 0, 0, 0, NULL };

int Compare(int start, int start2, int B, char s[])
{
	for (int i = 0; i < B; ++i)
	{
		if (s[start + i] != s[start2 + i])
		{
			return 0;
		}
	}
	return 1;
}


char S[1000500];


int hesh_functionator(char q[], int pos, int start)							//ТРЕПЕЩИ, ПЭРРИ УТКОНОС, я СПЛАГИАТИЛ ХЭШ-функционатор!!!
{
	int a = 0;
	for (int i = start; i < pos; ++i)
	{
		a = (a * 31 + q[i]) % simple;
	}
	return a;
}

int power_finder(int power, int b)
{
	int k = 1;
	for (int i = 0; i < power - 1; i++)
	{
		k = (k * b) % simple;
	}
	return k;
}

int move_hesh(int code, char left_symbol, char right_symbol, int len, int POW)
{
	int new_hesh = (code - (int)left_symbol * POW) % simple;
	if (new_hesh < 0)
	{
		new_hesh = simple + new_hesh;
	}
	new_hesh = (new_hesh * 31 + (int)right_symbol) % simple;
	if (new_hesh < 0)
	{
		new_hesh = simple + new_hesh;
	}
	return new_hesh;
}



int al[26] = { 2, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7 };

int hesh_functionator3000(char q[], int pos, int start)							//ТРЕПЕЩИ, ПЭРРИ УТКОНОС, я ИХОБРЁЛ ХЭШ-функционатор3000!!!
{
	int a = 0;
	for (int i = start; i < pos; ++i)
	{
		a = a + al[q[i] - 'a'];
	}
	return a;
}



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int sum = 0, colour = 1, N, B;
	scanf("%d %d\n", &N, &B);
	scanf("%s", S);
	int start = 0;
	int code, code2;
	int POW = power_finder(B, 31);
	code = hesh_functionator(S, start + B, start);
	q[code].colour = 0;
	q[code].s = S;
	++start;
	printf("0 ");
	int b = 0;
	for (int i = 1; i <= N - B; i++)
	{
		code = move_hesh(code, *(S + i - 1), *(S + i + B - 1), B, POW);
		int k = 0, is_pushed = 0, pos = -1, isEqual;
		while (!is_pushed)
		{
			pos = (code + 13 * k + 7 * k * k) % simple;							//Закрытое хэширование
			if (q[pos].s == NULL)
			{
				q[pos].colour = colour;
				q[pos].s = S + i;
				printf("%d ", colour++);
				is_pushed = 1;
			}
			else
			{
				isEqual = 0;
				int j = 0;
				for (; j < B && *(q[pos].s + j) == *(S + i + j); j++);			//Сравнение строк
				if (j == B && *(q[pos].s + B - 1) == *(S + i + B - 1))
				{
					printf("%d ", q[pos].colour);
					is_pushed = 1;
				}
			}
			k++;
		}
	}

	return 0;
}

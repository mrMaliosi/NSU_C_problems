#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a[30];

void next_permut(int a[], int n)
{
	int ch = 0, i;
	for (i = n - 2; (i >= 0); --i)
	{
		if (a[i] < a[i + 1])
		{
			ch = 1;
			break;
		}
	}

	if (ch == 1)
	{
		int mini = 99999999, minis;
		for (int j = i + 1; j < n; ++j)
		{
			if ((mini > a[j]) && (a[j] > a[i]))
			{
				mini = a[j];
				minis = j;
			}
		}

		a[minis] = a[i];
		a[i] = mini;

		for (int j = i + 1; j < n - j + i; ++j)
		{
			int x = a[j];
			a[j] = a[n - j + i];
			a[n - j + i] = x;
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char c;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%c", &c);
		if ((c != ' ') && (c != '\n'))
		{
			a[i] = c - 'a' + 1;
		}
		else --i;
		
	}

	next_permut(a, n);

	for (int i = 0; i < n; ++i)
	{
		printf("%c ", a[i] - 1 + 'a');
	}
	

	return 0;
}

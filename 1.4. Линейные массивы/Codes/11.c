#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mv[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int y1, y2, m1, m2, d1, d2, ans1 = 0, ans2 = 0, x;
	scanf("%d %d %d", &d1, &m1, &y1);
	scanf("%d %d %d", &d2, &m2, &y2);

	if ((y1 < 1) || (y1 > 2050))
	{
		printf("ERROR");
		return 0;
	}

	if ((y2 < 1) || (y2 > 2050))
	{
		printf("ERROR");
		return 0;
	}

	if ((m1 == 1) || (m1 == 3) || (m1 == 5) || (m1 == 7) || (m1 == 8) || (m1 == 10) || (m1 == 12))		//проверка на дни-мес€цы
	{
		if ((d1 > 31) || (d1 < 1))
		{
			printf("ERROR");
			return 0;
		}
	}
	else if ((m1 == 4) || (m1 == 6) || (m1 == 9) || (m1 == 11))
	{
		if ((d1 > 30) || (d1 < 1))
		{
			printf("ERROR");
			return 0;
		}
	}
	else if (m1 == 2)
	{
		if ((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 != 0)))
		{
			if ((d1 > 29) || (d1 < 1))
			{
				printf("ERROR");
				return 0;
			}
		}
		else if ((d1 > 28) || (d1 < 1))
		{
			printf("ERROR");
			return 0;
		}
	}
	else
	{
		printf("ERROR");
		return 0;
	}

	if ((m2 == 1) || (m2 == 3) || (m2 == 5) || (m2 == 7) || (m2 == 8) || (m2 == 10) || (m2 == 12))
	{
		if ((d2 > 31) || (d2 < 1))
		{
			printf("ERROR");
			return 0;
		}
	}
	else if ((m2 == 4) || (m2 == 6) || (m2 == 9) || (m2 == 11))
	{
		if ((d2 > 30) || (d2 < 1))
		{
			printf("ERROR");
			return 0;
		}
	}
	else if (m2 == 2)
	{
		if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 != 0)))
		{
			if ((d2 > 29) || (d2 < 1))
			{
				printf("ERROR");
				return 0;
			}
		}
		else if ((d2 > 28) || (d2 < 1))
		{
			printf("ERROR");
			return 0;
		}
	}
	else
	{
		printf("ERROR");
		return 0;
	}

	if ((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 != 0)))
	{
		ans1 += d1;
		--m1;
		while (m1 > 0)
		{
			ans1 += mv[m1 - 1];
			--m1;
		}
	}
	else
	{
		ans1 += d1;
		--m1;
		while (m1 > 0)
		{
			ans1 += m[m1 - 1];
			--m1;
		}
	}

	if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 != 0)))
	{
		ans2 += d2;
		--m2;
		while (m2 > 0)
		{
			ans2 += mv[m2 - 1];
			--m2;
		}
	}
	else
	{
		ans2 += d2;
		--m2;
		while (m2 > 0)
		{
			ans2 += m[m2 - 1];
			--m2;
		}
	}

	--y1;
	--y2;
	while (y1 > 0)
	{
		if ((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 != 0)))
		{
			ans1 += 366;
		}
		else ans1 += 365;
		--y1;
	}

	while (y2 > 0)
	{
		if ((y2 % 400 == 0) || ((y2 % 4 == 0) && (y2 % 100 != 0)))
		{
			ans2 += 366;
		}
		else ans2 += 365;
		--y2;
	}

	if (ans2 > ans1)
	{
		x = ans2;
		ans2 = ans1;
		ans1 = x;
	}

	printf("%d", ans1 - ans2);


	return 0;
}
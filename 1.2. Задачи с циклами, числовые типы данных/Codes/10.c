#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, i = 0, r = 0, rs, a;
	scanf("%d", &k);

	for (int j = 1; 1 > 0; ++j)
	{
		if (j == pow(10, r + 1)) ++r;
		rs = r;
		while (rs >= 0)
		{
			++i;
			if (i == k)
			{
				a = pow(10, rs);
				a = j / a;
				printf("%d\n", a%10);
				return 0;
			}
			--rs;
		}
	}

}

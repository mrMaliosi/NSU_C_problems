#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, koren, n = -1;
	scanf("%d", &k);
	koren = sqrt(8 * (k - 1) + 1);
	if (8 * (k - 1) + 1 == koren * koren)
	{
		if (((-1) + koren) % 2 == 0)
		{
			n = ((-1) + koren) / 2;
		}
	}

	if ((n != -1)&&(k == ((1 + n)*n)/2 + 1)) printf("1");
	else printf("0");

	return 0;
}

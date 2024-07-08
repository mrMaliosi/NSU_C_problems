#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* f;
	f = fopen("input.bin", "rb");
	int A, B;
	long long int ans, a, b;
	fread(&A, sizeof(int), 1, f);
	fread(&B, sizeof(int), 1, f);
	a = A;
	b = B;
	ans = a + b;
	if ((ans < 0) && (ans % 2 != 0))
	{
		ans = ans / 2 - 1;
	}
	else
	{
		ans = ans / 2;
	}


	fclose(f);
	f = fopen("output.bin", "wb");
	fwrite(&ans, sizeof(int), 1, f);
	fclose(f);

	return 0;
}
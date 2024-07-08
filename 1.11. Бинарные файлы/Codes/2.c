#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int reverce(unsigned int n)
{
	unsigned int a0 = n & 0xFF;
	unsigned int a1 = n & 0xFF00;
	unsigned int a2 = n & 0xFF0000;
	unsigned int a3 = n & 0xFF000000;
	n = ((a0 << 24) | (a1 << 8) | (a2 >> 8) | (a3 >> 24));
	return n;
}

int main()
{
	FILE* f;
	f = fopen("input.bin", "rb");
	int sum = 0, length, x;
	fread(&length, sizeof(int), 1, f);
	int ch = ftell(f);

	if (length <= 10000)
	{
		for (int i = 0; i < length; ++i)
		{
			fread(&x, sizeof(int), 1, f);
			sum += x;
		}
		fclose(f);

		f = fopen("output.bin", "wb");
		fwrite(&sum, sizeof(int), 1, f);
		fclose(f);
	}
	else
	{
		length = reverce(length);
		for (int i = 0; i < length; ++i)
		{
			fread(&x, sizeof(int), 1, f);
			sum += reverce(x);
		}
		fclose(f);

		f = fopen("output.bin", "wb");
		sum = reverce(sum);
		fwrite(&sum, sizeof(int), 1, f);
		fclose(f);
	}



	return 0;
}
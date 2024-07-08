#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1000500];
int b[1000500];
int res[2001000];

int merge(const int* a, int ak, const int* b, int bk, int* res)
{
	int i = 0, j = 0, l = 0;
	while ((i < ak) && (j < bk))
	{
		if (a[i] <= b[j])
		{
			res[l] = a[i];
			++i;
			++l;
		}
		else
		{
			res[l] = b[j];
			++j;
			++l;
		}
	}

	while (i < ak)
	{
		res[l] = a[i];
		++i;
		++l;
	}

	while (j < bk)
	{
		res[l] = b[j];
		++j;
		++l;
	}

	return l;
}

int main()
{
	FILE* f;

	f = fopen("input.bin", "rb");
	int N, M, l;
	fread(&N, sizeof(int), 1, f);
	fread(&M, sizeof(int), 1, f);

	for (int i = 0; i < N; ++i)
	{
		fread(&a[i], sizeof(int), 1, f);
	}

	for (int i = 0; i < M; ++i)
	{
		fread(&b[i], sizeof(int), 1, f);
	}

	l = merge(a, N, b, M, res);
	fclose(f);

	f = fopen("output.bin", "wb");
	for (int i = 0; i < l; ++i)
	{
		fwrite(&res[i], sizeof(int), 1, f);
	}
	fclose(f);

	return 0;
}
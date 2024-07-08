#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

///////////////Базовые функции v1.0///////////////
void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int* Min(int* a, int* b)
{
	if (b < a)
	{
		return b;
	}
	return a;
}

void str_o(char* q)
{
	while (*q != '\0')
	{
		printf("%c", *q);
		++q;
	}
}

void str_i(char* q)
{
	char a;
	while (scanf("%c", &a) == 1)
	{
		*q = a;
		++q;
	}
}

////////////Интерфейс кучи/////////////
typedef struct Hip {
	int length;
	int heap_size;
	int* arr;
} hip;

int is_empty(hip* H)
{
	if (H->heap_size == 0)
	{
		return 1;
	}
	return 0;
}

int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	if (i == 0)
	{
		return 1;
	}
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

void sift_up(int i, hip* H)
{
	if (H->arr[i] < H->arr[parent(i)])
	{
		Swap(&H->arr[i], &H->arr[parent(i)]);
		sift_up(parent(i), H);
	}
}

void sift_down(int i, hip* H)
{
	int l = left(i);
	int r = right(i);
	if (l < H->heap_size)
	{
		if (r < H->heap_size)
		{
			if (H->arr[r] > H->arr[l])
			{
				if (H->arr[i] > H->arr[l])
				{
					Swap(&H->arr[i], &H->arr[l]);
					sift_down(l, H);
				}
			}
			else
			{
				if (H->arr[i] > H->arr[r])
				{
					Swap(&H->arr[i], &H->arr[r]);
					sift_down(r, H);
				}
			}
		}
		else
		{
			if (H->arr[i] > H->arr[l])
			{
				Swap(&H->arr[i], &H->arr[l]);
				sift_down(l, H);
			}
		}
	}
}

hip* create(int size)
{
	hip* H = (hip*)malloc(sizeof(hip));
	H->length = size;
	H->heap_size = 0;
	H->arr = (int*)malloc(sizeof(int) * size);
	return H;
}

void push(int a, hip* H)
{
	H->heap_size++;
	H->arr[H->heap_size - 1] = a;
	sift_up(H->heap_size - 1, H);
}

int pop(hip* H)
{
	if (is_empty(H) == 0)
	{
		int a = H->arr[0];
		H->arr[0] = H->arr[H->heap_size - 1];
		H->heap_size--;
		sift_down(0, H);
		return a;
	}
	else
	{
		printf("Heap is empty\n");
		return -1;
	}
}
////////////Конец интерфейса кучи/////////////


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Q, ch = 0, j = 0, a = 0;
	char q[100];
	hip* H = create(200500);
	scanf("%d\n", &Q);
	for (int i = 0; i < Q; ++i)
	{
		gets_s(q, 100);
		if (q[1] == 'u')
		{
			j = 5;
			if (q[j] == '-')
			{
				ch = 1;
				++j;
			}
			while (q[j] != '\0')
			{
				a = a * 10 + q[j] - '0';
				++j;
			}

			if (ch == 1)
			{
				a = -a;
				ch = 0;
			}
			push(a, H);
			a = 0;
		}
		if (q[1] == 'o')
		{
			if (is_empty(H) == 0)
			{
				a = pop(H);
				printf("%d\n", a);
				a = 0;
			}
			else
			{
				printf("Heap is empty\n");
			}
		}

	}
	printf("\n");
	return 0;
}


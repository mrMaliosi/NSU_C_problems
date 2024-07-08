#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Hiperpoper {
	int distance;
	int node;
}hiphoper;

///////////////Базовые функции v1.0///////////////
void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Swap_h(hiphoper* a, hiphoper* b)
{
	hiphoper c = *a;
	*a = *b;
	*b = c;
}

int Min(int a, int b)
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
	hiphoper* arr;
} heap;

int is_empty(heap* H)
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

void sift_up(int i, heap* H)
{
	if (H->arr[i].distance < H->arr[parent(i)].distance)
	{
		Swap_h(&H->arr[i], &H->arr[parent(i)]);
		sift_up(parent(i), H);
	}
}

void sift_down(int i, heap* H)
{
	int l = left(i);
	int r = right(i);
	if (l < H->heap_size)
	{
		if (r < H->heap_size)
		{
			if (H->arr[r].distance > H->arr[l].distance)
			{
				if (H->arr[i].distance > H->arr[l].distance)
				{
					Swap_h(&H->arr[i], &H->arr[l]);
					sift_down(l, H);
				}
			}
			else
			{
				if (H->arr[i].distance > H->arr[r].distance)
				{
					Swap_h(&H->arr[i], &H->arr[r]);
					sift_down(r, H);
				}
			}
		}
		else
		{
			if (H->arr[i].distance > H->arr[l].distance)
			{
				Swap_h(&H->arr[i], &H->arr[l]);
				sift_down(l, H);
			}
		}
	}
}

heap* create(int size)
{
	heap* H = (heap*)malloc(sizeof(heap));
	H->length = size * 8;
	H->heap_size = 0;
	H->arr = (hiphoper*)malloc(sizeof(hiphoper) * size * 8);
	return H;
}

void push(hiphoper p, heap* H)
{
	H->heap_size++;
	H->arr[H->heap_size - 1] = p;
	sift_up(H->heap_size - 1, H);
}

hiphoper pop(heap* H)
{
	if (is_empty(H) == 0)
	{
		hiphoper a = H->arr[0];
		H->arr[0] = H->arr[H->heap_size - 1];
		H->heap_size--;
		sift_down(0, H);
		return a;
	}
	else
	{
		printf("Heap is empty\n");
		hiphoper a;
		a.distance = -1;
		a.node = -1;
		return a;
	}
}
////////////Конец интерфейса кучи/////////////

typedef struct list
{
	int data;
	int distance;
	struct list* next;
} list;

list* push_back(list* head, int data, int distance)
{
	list* p = (list*)malloc(sizeof(list));
	p->next = head;
	p->data = data;
	p->distance = distance;
	head = p;
	return head;
}

int q[505][505];
int previous[505];
int answ[505];


void FloydWarshall(int q[][505], int N)
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				q[i][j] = Min(q[i][j], q[i][k] + q[k][j]);
			}
		}
	}
	int f = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	char a;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%c", &a);
		for (int j = 1; j <= N; ++j)
		{
			scanf("%c", &a);
			q[i][j] = a - '0';
			if (q[i][j] == 0)
			{
				q[i][j] = 1000000500;
			}
		}
		q[i][i] = 0;
	}

	FloydWarshall(q, N);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (q[i][j] == 1000000500)
			{
				printf("0");

			}
			else
			{
				printf("1");
			}

		}
		printf("\n");
	}
	return 0;
}

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
	H->length = size;
	H->heap_size = 0;
	H->arr = (hiphoper*)malloc(sizeof(hiphoper) * size);
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

list* q[50005];
int d[100005];

void Initialize(int start, int n)
{
	for (int i = 1; i <= 50000; ++i)
	{
		d[i] = 1000005000;
	}
	d[start] = 0;
}

int Relax(int u, int v, int w)
{
	if (d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		return 1;
	}
	return 0;
}

void Deic(int start, int distance[], list* head, list* q[], int N)
{
	int ch = -1;
	Initialize(start, N);
	heap* qu = create(N);
	hiphoper p;
	p.distance = 0;
	p.node = start;
	push(p, qu);
	while (is_empty(qu) == 0)
	{
		p = pop(qu);
		start = p.node;
		head = q[start];
		while (head != NULL)
		{
			ch = Relax(start, head->data, head->distance);
			if (ch == 1)
			{
				p.distance = d[head->data];
				p.node = head->data;
				push(p, qu);
			}
			head = head->next;
		}

	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	int K, L;
	int x, y, t;
	scanf("%d", &N);
	scanf("%d %d", &K, &L);
	int xs = 0, ys = 0, ts = 0;
	scanf("%d %d %d", &x, &y, &t);
	while ((xs != x) || (ys != y) || (ts != t))
	{
		q[x] = push_back(q[x], y, t);
		q[y] = push_back(q[y], x, t);
		xs = x; ys = y; ts = t;
		scanf("%d %d %d", &x, &y, &t);
	}

	Deic(K, d, q[K], q, N);
	if (d[L] != 1000005000)
	{
		printf("%d", d[L]);
	}
	else
	{
		printf("no");
	}
}
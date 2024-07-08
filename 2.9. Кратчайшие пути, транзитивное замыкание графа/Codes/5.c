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
	H->length = size * 12;
	H->heap_size = 0;
	H->arr = (hiphoper*)malloc(sizeof(hiphoper) * size * 12);
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

int q[3005][3005];
int d[100005];
int previous[100005];
int ans[100005];
int ask[20][2];

void Initialize(int start, int n)
{
	for (int i = 1; i <= 3005; ++i)
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
		previous[v] = u;
		return 1;
	}
	return 0;
}

void Deic(int start, int distance[], int q[][3005], int N)
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
		for (int i = 1; i <= N; ++i)
		{
			if (q[start][i] >= 0)
			{
				ch = Relax(start, i, q[start][i]);
				if (ch == 1)
				{
					p.distance = d[i];
					p.node = i;
					push(p, qu);
				}
			}
		}

	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	int K;
	int x, y, t;
	scanf("%d %d", &N, &M);
	scanf("%d", &K);
	int xs = 0, ys = 0, ts = 0;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			q[i][j] = 100500;
		}
	}

	for (int i = 0; i < K; ++i)
	{
		scanf("%d %d", &x, &y);
		ask[i][0] = x;
		ask[i][1] = y;
	}

	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d %d", &x, &y, &t);
		q[x][y] = Min(q[x][y], t);
		q[y][x] = Min(q[y][x], t);
	}

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			if (q[i][j] == 100500)
			{
				q[i][j] = -1;
			}
		}
	}

	int b = 0;
	for (int i = 0; i < K; ++i)
	{
		y = ask[i][0];
		x = ask[i][1];
		Deic(y, d, q, N);
		if (d[x] != 1000005000)
		{
			printf("YES %d ", d[ask[i][1]]);
			ans[b] = x;
			++b;
			while (x != y)
			{
				ans[b] = previous[x];
				x = previous[x];
				++b;
			}
			printf("%d ", b);
			for (int j = b - 1; j >= 0; --j)
			{
				printf("%d ", ans[j]);
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
		b = 0;
	}
}

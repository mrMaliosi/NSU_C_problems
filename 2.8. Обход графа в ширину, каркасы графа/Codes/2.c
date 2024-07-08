#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

///////////////////////////�������////////////////////////////////
typedef struct _Queue
{
	int size; // ������ �������
	int first; // ����� ������� �������� �������
	int length; // ����� �������
	int* arr; // ��������� �� ������ �������
} queue;


queue* create(int size)
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->first = 0;
	q->length = 0;
	q->size = size;
	q->arr = (int*)malloc(sizeof(int) * size);
	return q;
}


int first(queue* q)				//������ �������� ������� �������� �������, �� ������ ���
{
	return (q->arr[q->first]);
}

int dequeue(queue* q) //������ �������� ������� �������� ������� � ������� ��� �� �������
{
	int a = q->arr[q->first++];
	q->length--;
	q->first %= q->size;
	return a;
}

void enqueue(int x, queue* q) //�������� � ����� ������� Q ����� ������� �� ��������� x
{
	q->arr[(q->first + q->length) % q->size] = x;
	q->length++;
}

int is_empty(queue* q) //���� ������� �����, �� ������� ���������� 1 (������), ����� � 0 (����).
{
	if (q->length == 0)
	{
		return 1;
	}
	return 0;
}

///////////����� ���������� �������///////////

int q[105][105];

void BFS(int x, int y, int q[][105], int N, int M)
{
	queue* qux = create(N * N);
	queue* quy = create(N * N);
	enqueue(x, qux);
	enqueue(y, quy);
	q[x][y] = 1;

	while (is_empty(qux) == 0)
	{
		x = dequeue(qux);
		y = dequeue(quy);

		if (x > 0)
		{
			if (q[x - 1][y] == 0)
			{
				enqueue(x - 1, qux);
				enqueue(y, quy);
				q[x - 1][y] = q[x][y] + 1;
			}
		}

		if (y > 0)
		{
			if (q[x][y - 1] == 0)
			{
				enqueue(x, qux);
				enqueue(y - 1, quy);
				q[x][y - 1] = q[x][y] + 1;
			}
		}

		if (x < M - 1)
		{
			if (q[x + 1][y] == 0)
			{
				enqueue(x + 1, qux);
				enqueue(y, quy);
				q[x + 1][y] = q[x][y] + 1;
			}
		}

		if (y < N - 1)
		{
			if (q[x][y + 1] == 0)
			{
				enqueue(x, qux);
				enqueue(y + 1, quy);
				q[x][y + 1] = q[x][y] + 1;
			}
		}
	}

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	scanf("%d %d\n", &M, &N);
	int x, y;
	char a;
	int xs, ys, xf, yf;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%c", &a);
			if (a == 'X')
			{
				q[i][j] = -1;
			}
			else if (a == 'S')
			{
				xs = i;
				ys = j;
			}
			else if (a == 'F')
			{
				xf = i;
				yf = j;
			}

		}
		scanf("%c", &a);
	}

	BFS(xs, ys, q, N, M);
	printf("%d", q[xf][yf] - 1);

	return 0;
}
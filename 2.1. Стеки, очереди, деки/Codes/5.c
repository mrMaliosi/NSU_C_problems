#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

int empty(queue* q) //���� ������� �����, �� ������� ���������� 1 (������), ����� � 0 (����).
{
	if (q->length == 0)
	{
		return 1;
	}
	return 0;
}

///////////�� ������ ����� ��������///////////

int lqueue(queue* q)					//����� �������� ���������� �������� ������� � ������� ��� (�� ���� ��� �����-��) 
{
	int pos = (q->first + q->length - 1) % q->size;
	int a = q->arr[pos];
	q->length--;
	return a;
}

void ya_tolko_sprosit(int x, queue* q)					//� ������ ��������... (������������� ����, ����������� ��������� ��� �������)
{
	if (q->first == 0)
	{
		q->arr[q->size - 1] = x;
		q->first = q->size - 1;
	}
	else
	{
		q->arr[q->first - 1] = x;
		q->first--;
	}

	q->length++;
}

int ruler(queue* q)
{
	return q->length;
}

void card_filling(queue* q1, queue* q2, int n)
{
	for (int i = 1; i <= n; ++i)
	{
		q1->arr[q1->first + i - 1] = i;
		q2->arr[q2->first + i - 1] = -i;
		q1->length++;
		q2->length++;
	}
}

int decode(char a)
{
	if ((a >= 'A') && (a <= 'F'))
	{
		return a - 'A' + 10;
	}
	else if ((a >= '0') && (a <= '9'))
	{
		return a - '0';
	}
}

void perfocard_master(int code, queue* q1, queue* q2)
{
	int a;
	if ((code & 8) == 8)
	{
		if ((code & 4) == 4)
		{
			if (empty(q2) == 0)
			{
				a = lqueue(q2);
				if ((code & 2) == 2)
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q2);
					}
					else
					{
						ya_tolko_sprosit(a, q2);
					}
				}
				else
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q1);
					}
					else
					{
						ya_tolko_sprosit(a, q1);
					}
				}
			}
		}
		else
		{
			if (empty(q2) == 0)
			{
				a = dequeue(q2);
				if ((code & 2) == 2)
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q2);
					}
					else
					{
						ya_tolko_sprosit(a, q2);
					}
				}
				else
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q1);
					}
					else
					{
						ya_tolko_sprosit(a, q1);
					}
				}
			}
		}
	}
	else
	{
		if ((code & 4) == 4)
		{
			if (empty(q1) == 0)
			{
				a = lqueue(q1);
				if ((code & 2) == 2)
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q2);
					}
					else
					{
						ya_tolko_sprosit(a, q2);
					}
				}
				else
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q1);
					}
					else
					{
						ya_tolko_sprosit(a, q1);
					}
				}
			}
		}
		else
		{
			if (empty(q1) == 0)
			{
				a = dequeue(q1);
				if ((code & 2) == 2)
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q2);
					}
					else
					{
						ya_tolko_sprosit(a, q2);
					}
				}
				else
				{
					if ((code & 1) == 1)
					{
						enqueue(a, q1);
					}
					else
					{
						ya_tolko_sprosit(a, q1);
					}
				}
			}
		}
	}
}

void perfocard_teller(queue* q)			//��������� ������ � �����������
{
	printf("%d ", ruler(q));
	while (empty(q) == 0)
	{
		printf("%d ", dequeue(q));
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	char a;
	int b;
	scanf("%d %d", &N, &M);
	queue* q1 = create(2 * N + 1);		//����� ������
	queue* q2 = create(2 * N + 1);		//������ ������
	card_filling(q1, q2, N);
	scanf("%c", &a);					//��������� �� ���� '\n'
	for (int i = 0; i < M; ++i)
	{
		scanf("%c", &a);
		b = decode(a);
		perfocard_master(b, q1, q2);
	}

	perfocard_teller(q1);
	perfocard_teller(q2);

	return 0;
}

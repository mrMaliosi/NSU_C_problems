#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

///////////////////////////ќчередь////////////////////////////////
typedef struct _Queue
{
	int size; // размер массива
	int first; // номер первого элемента очереди
	int length; // длина очереди
	int* arr; // указатель на начало массива
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


int first(queue* q)				//выдает значение первого элемента очереди, не удал€€ его
{
	return (q->arr[q->first]);
}

int dequeue(queue* q) //выдает значение первого элемента очереди и удал€ет его из очереди
{
	int a = q->arr[q->first++];
	q->length--;
	q->first %= q->size;
	return a;
}

void enqueue(int x, queue* q) //помещает в конец очереди Q новый элемент со значением x
{
	q->arr[(q->first + q->length) % q->size] = x;
	q->length++;
}

int is_empty(queue* q) //если очередь пуста, то функци€ возвращает 1 (истина), иначе Ц 0 (ложь).
{
	if (q->length == 0)
	{
		return 1;
	}
	return 0;
}

/////////// онец интерфейса очереди///////////

typedef struct list
{
	int data;
	struct list* next;
} list;

list* q[200005];
int visited[200005];
int distance[200005];

list* push(list* head, int data)
{
	list* p = (list*)malloc(sizeof(list));
	p->next = head;
	p->data = data;
	head = p;
	return head;
}

void BFS(int start, int visited[], int distance[], list* head, list* q[], int N)
{
	queue* qu = create(N);
	enqueue(start, qu);
	visited[start] = 1;
	distance[start] = 0;

	while (is_empty(qu) == 0)
	{
		start = dequeue(qu);
		head = q[start];
		while (head != NULL)
		{
			if (visited[head->data] == 0)
			{
				visited[head->data] = 1;
				distance[head->data] = distance[start] + 1;
				enqueue(head->data, qu);
			}
			head = head->next;
		}
	}

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	scanf("%d %d", &N, &M);
	int x, y;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &x, &y);
		q[x] = push(q[x], y);
	}

	BFS(1, visited, distance, q[1], q, N);

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", distance[i]);
		}
	}
	return 0;
}
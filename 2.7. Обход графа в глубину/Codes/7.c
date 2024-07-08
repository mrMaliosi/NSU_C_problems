#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list* next;
} list;

typedef struct Stack {
	struct list* top;
} stack;


list* q[100005];
list* qT[100005];						//Транспонированный граф 
int visited[100005];
int S[100005];
int components[100005];

//////////////////Для листа//////////////////
list* push_back(list* head, int data)
{
	list* p = (list*)malloc(sizeof(list));
	p->next = head;
	p->data = data;
	head = p;
	return head;
}

void DFS_T(int start, int visited[], list* head, list* q[], int S[], int* b)		//Обходим транспонированный граф
{
	visited[start] = 1;

	while (head != NULL)
	{
		if (visited[head->data] == 0)
		{
			DFS_T(head->data, visited, q[head->data], q, S, b);
		}
		head = head->next;
	}

	S[b[0]] = start;
	++b[0];
}

void DFS(int start, int visited[], list* head, list* q[], int colour)
{
	visited[start] = colour;

	while (head != NULL)
	{
		if (visited[head->data] == 0)
		{
			DFS(head->data, visited, q[head->data], q, colour);
		}
		head = head->next;
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
		q[x] = push_back(q[x], y);
		qT[y] = push_back(qT[y], x);
	}

	int g = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == 0)
		{
			DFS_T(i, visited, qT[i], qT, S, &g);
		}
	}

	int colour = 1;
	int a;
	for (int i = g - 1; i >= 0; --i)
	{
		a = S[i];
		if (components[a] == 0)
		{
			DFS(a, components, q[a], q, colour);
			++colour;
		}
	}

	printf("%d\n", colour - 1);
	for (int i = 1; i <= N; ++i)
	{
		printf("%d ", components[i]);
	}
	return 0;
}
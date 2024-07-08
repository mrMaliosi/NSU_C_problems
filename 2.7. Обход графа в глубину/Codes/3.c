#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list* next;
} list;

list* q[20005];
int visited[20005];

list* push(list* head, int data)
{
	list* p = (list*)malloc(sizeof(list));
	p->next = head;
	p->data = data;
	head = p;
	return head;
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
		q[x] = push(q[x], y);
		q[y] = push(q[y], x);
	}

	int colour = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == 0)
		{
			DFS(i, visited, q[i], q, colour);
			++colour;
		}
	}

	--colour;
	printf("%d\n", colour);
	for (int i = 1; i <= N; ++i)
	{
		printf("%d ", visited[i]);
	}
	return 0;
}
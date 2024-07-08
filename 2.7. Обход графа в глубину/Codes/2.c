#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list* next;
} list;

list* q[105];
int visited[105];
int colourfull_red[105];					//деёшь красно-чёрные деревья!
int colourfull_black[105];
int colours[105];

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
	int N, M = 0;
	scanf("%d", &N);
	int x, y, xs, ys;
	scanf("%d %d", &x, &y);
	xs = x;
	ys = y;
	q[x] = push(q[x], y);
	q[y] = push(q[y], x);
	++M;
	scanf("%d %d", &x, &y);
	while (((xs == x) && (ys == y)) != 1)
	{
		xs = x;
		ys = y;
		q[x] = push(q[x], y);
		q[y] = push(q[y], x);
		++M;
		scanf("%d %d", &x, &y);
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


	printf("%d", colour);
	return 0;
}
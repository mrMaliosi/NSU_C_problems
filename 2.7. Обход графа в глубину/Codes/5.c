#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list* next;
} list;

list* q[100005];
int visited[100005];
int ans[100005];
int answ[100005];

list* push(list* head, int data)
{
	list* p = (list*)malloc(sizeof(list));
	p->next = head;
	p->data = data;
	head = p;
	return head;
}

int DFS(int start, int visited[], list* head, list* q[], int* b, int* ch)
{
	visited[start] = 1;

	while (head != NULL)
	{
		if (visited[head->data] == 0)
		{
			DFS(head->data, visited, q[head->data], q, b, ch);
		}
		else if (visited[head->data] == 1)
		{
			ch[0] = 1;
			return 1;
		}
		head = head->next;
	}

	visited[start] = 2;
	ans[*b] = start;
	(*b)++;
	return 0;
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

	int b = 1;
	int f = 0;
	int ch = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] == 0)
		{
			ch = DFS(i, visited, q[i], q, &b, &f);
			if (f == 1)
			{
				printf("NO");
				return 0;
			}
		}
	}

	int c = b;
	printf("YES\n");
	for (int i = c - 1; i > 0; --i)
	{
		answ[ans[i]] = b - i;
	}

	for (int i = 1; i < b; ++i)
	{
		printf("%d ", answ[i]);
	}
	return 0;
}

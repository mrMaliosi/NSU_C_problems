#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



/////////////////Интерфейс целочисленного списка///////////////////
typedef struct List {
	int data;
	struct List* next;
} list;

list q[10000005] = { NULL };
int ans[1000005];

int push_after(list* head, int data)
{
	if (head == NULL)
	{
		list* p = (list*)malloc(sizeof(list));
		p->data = data;
		p->next = NULL;
		head = p;
		return 0;
	}
	else
	{
		while (head->next != NULL)
		{
			if (data == head->data)
			{
				return 1;
			}
			head = head->next;
		}

		if (data == head->data)
		{
			return 1;
		}

		list* p = (list*)malloc(sizeof(list));
		p->data = data;
		p->next = NULL;
		head->next = p;
		return 0;
	}
}


void zero_killer(list* head)
{
	head->data = -500000;
}


int hesh_function(int a)
{
	a = a + 1000000000;
	a = a / 200;
	return a;
}

int main() {
	FILE* f;
	f = fopen("input.bin", "rb");
	int N, a, code, ch = 0, j = 0;
	fread(&N, sizeof(int), 1, f);					//Mon dier, какой ужасный формат представления данных!
	zero_killer(&q[5000000]);
	for (int i = 0; i < N; ++i)
	{
		fread(&a, sizeof(int), 1, f);
		code = hesh_function(a);
		ch = push_after(&q[code], a);
		if (ch == 0)
		{
			ans[j] = a;
			++j;
		}
	}

	fclose(f);

	f = fopen("output.bin", "wb");
	fwrite(&j, sizeof(int), 1, f);
	for (int i = 0; i < j; ++i)
	{
		fwrite(&ans[i], sizeof(int), 1, f);
	}
	fclose(f);
	return 0;
}

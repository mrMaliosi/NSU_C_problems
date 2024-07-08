#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned int ul;					//Ћайфхаки ту-ру-ру

/////////////////»нтерфейс целочисленного списка///////////////////
typedef struct List {
	ul key;
	ul data;
	struct List* next;
} list;

list q[10000005] = { NULL };
ul ans[2000005];

int push_after(list* head, ul key, ul data)
{
	if (head == NULL)
	{
		list* p = (list*)malloc(sizeof(list));
		p->key = key;
		p->next = NULL;
		head = p;
		return 0;
	}
	else
	{
		while (head->next != NULL)
		{
			if ((key == head->key) && (head->data != data))
			{
				return 1;
			}
			else if (head->data == data)
			{
				return 0;
			}
			head = head->next;
		}

		if ((key == head->key) && (head->data != data))
		{
			return 1;
		}
		else if (head->data == data)
		{
			return 0;
		}

		list* p = (list*)malloc(sizeof(list));
		p->key = key;
		p->data = data;
		p->next = NULL;
		head->next = p;
		return 0;
	}
}

int data_miner(list* head, ul key)							//функци€, забирающа€ требуемые данные из хэш-таблицы, а возможно и данные с вашего компьютера
{
	while (head->next != NULL)
	{
		if (key == head->key)
		{
			return head->data;
		}
		head = head->next;
	}

	if (key == head->key)
	{
		return head->data;
	}

	list* p = (list*)malloc(sizeof(list));
	p->key = key;
	p->next = NULL;
	head->next = p;
	return 0;
}


ul hesh_function(ul a)
{
	return a % 9999991;
}

int main()
{
	ul a = 0, ch = 0, code, state, b, c;
	srand(time(NULL));
	while (ch != 1)
	{
		a = a + 1;
		printf("eval %u\n", a);
		fflush(stdout);
		scanf("%u", &state);
		code = hesh_function(state);
		ch = push_after(&q[code], state, a);			//€чейка хэш-таблицы, куда кладЄм значение, 
	}

	b = data_miner(&q[code], state);
	if (b > a)
	{
		c = b;
		b = a;
		a = c;
	}
	printf("answer %u %u\n", a, b);

	return 0;
}

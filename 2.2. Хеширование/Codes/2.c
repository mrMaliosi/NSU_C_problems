#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int ll;					//Лайфхаки ту-ру-ру

/////////////////Интерфейс целочисленного списка///////////////////
typedef struct List {
	ll data;
	struct List* next;
} list;

list q[10000005] = { NULL };
ll ans[2000005];

int push_after(list* head, ll data)
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


ll hesh_function(ll a)
{
	return a % 9999991;
}

ll generator(ll s, ll a, ll b, ll c, ll M)
{
	return (s * s * a + s * b + c) % M;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll M, a = 3000000000, b, c, state = 1, code = 0, ch = 0, j = 0, l = -1, r = -1;
	zero_killer(&q[0]);
	scanf("%lld", &M);
	scanf("%lld %lld %lld", &a, &b, &c);
	code = hesh_function(1);
	push_after(&q[code], 1);
	ans[j] = 1;
	++j;
	while (ch != 1)
	{
		state = generator(state, a, b, c, M);
		code = hesh_function(state);
		ch = push_after(&q[code], state);
		ans[j] = state;
		++j;
	}

	for (int i = 0; i < 2000005; ++i)
	{
		if (ans[i] == state)
		{
			if (l == -1)
			{
				l = i;
				printf("%lld ", l);
			}
			else if (r == -1)
			{
				r = i;
				printf("%lld", r);
				break;
			}
		}
	}

	return 0;
}

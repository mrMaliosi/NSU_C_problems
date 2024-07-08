//Господи, ПОЖАЛУЙСТА заработай... Я устал страдать...
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


/////////////////Интерфейс целочисленного списка///////////////////
struct list {
	int data;
	struct list* next;
};

typedef struct Stack {
	struct list* top;
} stack;

stack* stack_create()
{
	stack* S;
	S = (stack*)malloc(sizeof(stack));
	S->top = NULL;
	return S;
}

int top(stack* S)
{
	return (S->top->data);
}

int pop(stack* S)
{
	int a;
	struct list* p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	free(p);
	return a;
}

void push(stack* S, int a)
{
	struct list* p;
	p = (struct list*)malloc(sizeof(struct list));
	p->data = a;
	p->next = S->top;
	S->top = p;
}

int is_empty(stack* S)
{
	return (S->top == NULL);
}

/////////////////Интерфейс вещественного списка///////////////////
struct dlist {
	double data;
	struct dlist* next;
};

typedef struct dStack {
	struct dlist* top;
} dstack;

dstack* dstack_create()
{
	dstack* S;
	S = (dstack*)malloc(sizeof(dstack));
	S->top = NULL;
	return S;
}

double dtop(dstack* S)
{
	return (S->top->data);
}

double dpop(dstack* S)
{
	double a;
	struct dlist* p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	free(p);
	return a;
}

void dpush(dstack* S, double a)
{
	struct dlist* p;
	p = (struct dlist*)malloc(sizeof(struct dlist));
	p->data = a;
	p->next = S->top;
	S->top = p;
}

int dis_empty(dstack* S)
{
	return (S->top == NULL);
}
/////////////////Конец всех интерфейсов///////////////////

int code(char a)						//Присвоит код элементу и даже тебе. Да-да
{
	if (a == '^')
	{
		return -1;
	}
	else if (a == '+')
	{
		return 1;
	}
	else if (a == '-')
	{
		return 2;
	}
	else if (a == '*')
	{
		return 3;
	}
	else if (a == '/')
	{
		return 4;
	}
	return 0;
}


int Code(char a)
{
	if (a == '(')
	{
		return 1;
	}
	else if (a == ')')
	{
		return 2;
	}
	else if (a == '=')
	{
		return 3;
	}
	else if ((a == '+') || (a == '-'))
	{
		return 4;
	}
	else if ((a == '*') || (a == '/'))
	{
		return 5;
	}
}

void poland_cow(char q[], char* ans)
{
	stack* S = stack_create();
	int a = 0, ch = 0, start = 0;
	for (int i = 0; q[i] != '\n'; ++i)
	{
		if (start == 1)								//выражение началось, открываем доступ к основному блоку
		{
			start = 2;
		}

		if (start == 0)								//блок, нужный, если минус в начале (Денис, блок НУЖНЫЙ. НЕ "бесполезная фигня, не знаю, зачем я её тут написал")
		{											//выражение ещё не началось, надо подождать...
			if (q[i] == ' ')
			{
				//Великолепный коммент. Кто прочитал - тот солнышко:)
			}
			else if (q[i] == '-')
			{
				*ans = '^';										//Унарный минус 
				++ans;
				*ans = '1';
				++ans;
				*ans = ' ';
				++ans;
				push(S, '*');
				start = 1;									//выражение началось, но доступ к основному блоку закрыт
			}
			else if (q[i] == '(')
			{
				push(S, q[i]);
			}
			else
			{
				start = 2;
			}
		}

		if (start == 2)
		{
			if (q[i] == ' ')
			{
				//Лишний отступ. Всё ясно, пользователь - Питонист.
			}
			else if ((ch == 1) && (q[i] == '-'))
			{
				ch = 2;
			}
			else if ((ch == 2) && (q[i] == '-'))
			{
				ch = 1;
			}
			else if ((q[i] >= '0') && (q[i] <= '9'))
			{
				if (ch == 2)
				{
					*ans = '^';
					++ans;
				}
				ch = 0;

				while ((q[i] >= '0') && (q[i] <= '9'))
				{
					*ans = q[i];
					++ans;
					++i;
				}
				*ans = ' ';
				++ans;
				--i;
			}
			else if (q[i] == '(')
			{
				start = 0;
				push(S, q[i]);
			}
			else if (q[i] == ')')
			{
				while (top(S) != '(')
				{
					*ans = pop(S);
					++ans;
				}
				pop(S);
			}
			else if (is_empty(S) == 1)							//string time! (Блок операторов)
			{
				push(S, q[i]);
				ch = 1;
			}
			else if (Code(top(S)) < Code(q[i]))
			{
				push(S, q[i]);
				ch = 1;
			}
			else
			{
				while ((is_empty(S) == 0) && (Code(top(S)) >= Code(q[i])))
				{
					*ans = pop(S);
					++ans;
				}
				push(S, q[i]);
				ch = 1;
			}
		}
	}


	while (is_empty(S) == 0)				//выплёвываем всё, что осталось в стэке
	{
		*ans = pop(S);
		++ans;
	}
	*ans = '\0';
}

double stack_can_count(char* q)
{
	dstack* S = dstack_create();
	double a = 0, b = 0;
	while (*q != '\0')
	{
		if (*q != ' ')
		{
			int C = code(*q);				//код символа (-1 - '^', 0 - цифра, 1 - '+', 2 - '-', 3 - '*', 4 - '/')
			if (C == -1)
			{
				++q;
				while (*q != ' ')
				{
					a = a * 10 + *q - '0';
					++q;
				}
				--q;
				a = -a;
				dpush(S, a);
				a = 0;
			}
			else if (C == 0)
			{
				while (*q != ' ')
				{
					a = a * 10 + *q - '0';
					++q;
				}
				dpush(S, a);
				a = 0;
			}
			else if (C == 1)
			{
				b = dpop(S);
				a = dpop(S);
				a = a + b;
				dpush(S, a);
				a = 0;
				b = 0;
			}
			else if (C == 2)
			{
				b = dpop(S);
				a = dpop(S);
				a = a - b;
				dpush(S, a);
				a = 0;
				b = 0;
			}
			else if (C == 3)
			{
				b = dpop(S);
				a = dpop(S);
				a = a * b;
				dpush(S, a);
				a = 0;
				b = 0;
			}
			else if (C == 4)
			{
				b = dpop(S);
				a = dpop(S);
				a = a / b;
				dpush(S, a);
				a = 0;
				b = 0;
			}
		}
		++q;
	}
	return dpop(S);
}

void str_o(char* q)
{
	while (*q != '\0')
	{
		printf("%c", *q);
		++q;
	}
}

void str_i(char* q)
{
	char a;
	while (scanf("%c", &a) == 1)
	{
		*q = a;
		++q;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char s[500500];
	char* q;
	q = (char*)malloc(505000);
	double ans;
	str_i(s);
	poland_cow(s, q);
	//str_o(q);
	ans = stack_can_count(q);
	printf("%0.20f", ans);
	return 0;
}
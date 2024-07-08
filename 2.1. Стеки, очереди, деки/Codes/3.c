#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct list {				//*пометка для себя, структура отличается от предыдущей задачи. Необходимо будет провести унификацию
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

void push(stack* S, int a)					//*пометка для себя, ф-ия отличается от предыдущей задачи. Необходимо будет провести унификацию
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

int code(char a)						//*пометка для себя, ф-ия отличается от предыдущей задачи. Необходимо будет провести унификацию
{
	if (a == '+')
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

int stack_can_count(char* q)
{
	stack* S = stack_create();
	int a = 0, b = 0;
	while (*q != '\n')
	{
		if (*q != ' ')
		{
			int C = code(*q);				//код символа (0 - цифра, 1 - '+', 2 - '-', 3 - '*', 4 - '/')
			if (C == 0)
			{
				while (*q != ' ')
				{
					a = a * 10 + *q - '0';
					++q;
				}
				push(S, a);
				a = 0;
			}
			else if (C == 1)
			{
				b = pop(S);
				a = pop(S);
				a = a + b;
				push(S, a);
				a = 0;
				b = 0;
			}
			else if (C == 2)
			{
				b = pop(S);
				a = pop(S);
				a = a - b;
				push(S, a);
				a = 0;
				b = 0;
			}
			else if (C == 3)
			{
				b = pop(S);
				a = pop(S);
				a = a * b;
				push(S, a);
				a = 0;
				b = 0;
			}
			else if (C == 4)
			{
				b = pop(S);
				a = pop(S);
				a = a / b;
				push(S, a);
				a = 0;
				b = 0;
			}
		}
		++q;
	}
	return pop(S);
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
	char s[2005];
	int ans;
	str_i(s);
	ans = stack_can_count(s);
	printf("%d", ans);
	return 0;
}

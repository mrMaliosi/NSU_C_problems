#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct list {
	char data;
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

void push(stack* S, char a)
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

int code(char a)
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

void poland_record(char q[], char* ans)
{
	stack* S = stack_create();
	for (int i = 0; q[i] != '\n'; ++i)
	{
		if ((q[i] >= 'a') && (q[i] <= 'z'))
		{
			*ans = q[i];
			++ans;
		}
		else
		{
			if (is_empty(S) == 1)
			{
				push(S, q[i]);
			}
			else if (q[i] == '(')
			{
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
			else if (code(top(S)) < code(q[i]))
			{
				push(S, q[i]);
			}
			else
			{
				while ((is_empty(S) == 0) && (code(top(S)) >= code(q[i])))
				{
					*ans = pop(S);
					++ans;
				}
				push(S, q[i]);
			}
		}
	}

	while (is_empty(S) == 0)
	{
		*ans = pop(S);
		++ans;
	}
	*ans = '\0';
}

void str_v(char* q)
{
	while (*q != '\0')
	{
		printf("%c", *q);
		++q;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char a;
	int i = 0;
	char q[1005];
	char* ans;
	ans = (char*)malloc(1005);
	while (scanf("%c", &a) == 1)
	{
		q[i] = a;
		++i;
	}

	poland_record(q, ans);
	str_v(ans);
	printf("\n");

	return 0;
}

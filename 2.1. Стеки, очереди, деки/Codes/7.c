//With the power of stacks...
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/////////////////Интерфейс символьного списка///////////////////
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

char top(stack* S)
{
	return (S->top->data);
}

char pop(stack* S)
{
	char a;
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

void stack_free(stack* S)
{
	while (S->top != NULL)
	{
		struct list* p;
		p = S->top;
		S->top = p->next;
		free(p);
	}
}

int is_empty(stack* S)
{
	return (S->top == NULL);
}

int code(char a)
{
	if ((a == '(') || (a == ')'))
	{
		return 1;
	}
	else if ((a == '{') || (a == '}'))
	{
		return 2;
	}
	else if ((a == '[') || (a == ']'))
	{
		return 3;
	}
	else if ((a == '<') || (a == '>'))
	{
		return 4;
	}
	return 0;
}

int Luke_Skywalker(stack* S1, stack* S2)											//*multistack:D				
{
	stack* S3 = stack_create();
	int ch = 0;
	while ((is_empty(S2) != 1) && (is_empty(S1) != 1))
	{
		ch = 0;
		while ((is_empty(S2) != 1) && (is_empty(S1) != 1))
		{
			if (code(top(S1)) != code(top(S2)))									//Соответствующая скобка не найдена, ищем дальше...
			{
				push(S3, pop(S2));

			}
			else																//ЕСТЬ! Скобка схлопнулась!
			{
				ch = 1;
				pop(S1);
				pop(S2);
			}
		}

		if (ch == 1)
		{
			while ((is_empty(S3) != 1) && (is_empty(S1) != 1))						//Начинаем сначала.
			{
				if (code(top(S1)) != code(top(S3)))
				{
					push(S2, pop(S3));
				}
				else
				{
					pop(S1);
					pop(S3);
				}
			}
		}
		else
		{
			break;
		}
	}

	if ((is_empty(S2) == 1) && (is_empty(S3) == 1))
	{
		return 1;							//Люк спас галактику
	}
	else if ((is_empty(S2) != 1) || (is_empty(S3) != 1))
	{
		return 0;							//Пичалька:(
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, p1 = 0, p2 = 0, p3 = 0, p4 = 0, ch = -1, count = 0, ALARM = 0;
	char a;
	stack* S1 = stack_create();
	stack* S2 = stack_create();
	scanf("%d\n", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%c", &a);
		while (a != '\n')
		{
			++count;
			if (((a == '(') || (a == '{') || (a == '[') || (a == '<')) && (is_empty(S2) == 1))							//Первая логическая ветка. Встретили открывающую скобку при отсутствии закрывающих
			{
				push(S1, a);
			}
			else if ((a == ')') || (a == '}') || (a == ']') || (a == '>'))												//Вторая логическая ветка. Встретили закрывающую скобку
			{
				if ((is_empty(S1) != 1) && (code(a) == code(top(S1))))													//Пытаемся "схлопнуть скобки"
				{
					pop(S1);
					while ((is_empty(S2) != 1) && (is_empty(S1) != 1) && (code(top(S1)) == code(top(S2))))
					{
						pop(S1);
						pop(S2);
					}
				}
				else if (is_empty(S1) == 1)																				//Открывающих скобок нет, а закрывающая езь (не порядок)
				{
					while (a != '\n')
					{
						scanf("%c", &a);
					}
					push(S2, a);
					break;
				}
				else
				{
					push(S2, a);												//Всё норм, но скобки не схлопнулись
				}
			}
			else																//Третья логическая ветка. Встретили открывающую скобку, а закрывающие не схлопнуты( 
			{
				ch = Luke_Skywalker(S1, S2);									//Галактика погрязла в хаосе. Однако, есть ещё надежда...
																				//Молодой герой по имени Люк... Люк Скайвокер может победить тьму, в которую погрузилась галактика и принести нам надежду...
				if (ch == 0)
				{
					while (a != '\n')											//Не, ну если Люк не смог, то никто не сможет. Заканчивайте проверку						
					{
						scanf("%c", &a);
						ALARM = 1;
						break;
					}
				}
				else
				{
					push(S1, a);												//Люк справился. Хорош. Продолжаем проверку
				}

			}

			scanf("%c", &a);
		}

		if (ALARM == 1)
		{
			printf("NIL\n");
			ALARM = 0;
		}
		else if ((is_empty(S1) == 1) && ((is_empty(S2) == 1)))
		{
			printf("T\n");
		}
		else
		{
			Luke_Skywalker(S1, S2);										//Ты уничтожил Звезду смерти. Теперь ты должен восстановить равновесие в галактике...
			if ((is_empty(S1) == 1) && ((is_empty(S2) == 1)))
			{
				printf("T\n");
			}
			else
			{
				printf("NIL\n");
			}

		}

		stack_free(S1);
		stack_free(S2);
	}
	return 0;
}


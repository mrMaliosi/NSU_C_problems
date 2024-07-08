#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue
{
	int size; // размер массива
	int first; // номер первого элемента очереди
	int length; // длина очереди
	int* arr; // указатель на начало массива
} queue;


queue* create(int size)
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->first = 0;
	q->length = 0;
	q->size = size;
	q->arr = (int*)malloc(sizeof(int) * size);
	return q;
}


int first(queue* q)				//выдает значение первого элемента очереди, не удаляя его
{
	return (q->arr[q->first]);
}

int dequeue(queue* q) //выдает значение первого элемента очереди и удаляет его из очереди
{
	int a = q->arr[q->first++];
	q->length--;
	q->first %= q->size;
	return a;
}

int enqueue(int x, queue* q) //помещает в конец очереди Q новый элемент со значением x
{
	if (q->length != q->size)
	{
		q->arr[(q->first + q->length) % q->size] = x;
		q->length++;
		return 0;
	}
	else
	{
		printf("Memory overflow\n");
		return -1;						//код ошибки
	}
	return -2;					//чертовщина
}

int empty(queue* q) //если очередь пуста, то функция возвращает 1 (истина), иначе – 0 (ложь).
{
	if (q->length == 0)
	{
		return 1;
	}
	return 0;
}

void where_is_the_end(int code, queue* q)						//собственно циклический буфер. А где конец? А нет конца. 
{
	int a, i = 0, ch = 0, s = 0;
	while (code > 0)
	{
		scanf("%d", &a);
		if (enqueue(a, q) != 0)				//очередь переполнена, всем неводшим необходимо расходится
		{
			--code;
			while (code > 0)
			{
				scanf("%d", &a);
				--code;
			}
			return;
		}
		--code;
	}

	while (code < 0)
	{
		ch = 1;
		if (empty(q) != 1)
		{
			s += dequeue(q);
			++i;
			++code;
		}
		else
		{
			if (i != 0)
			{
				s = s / i;
				printf("%d\n", s);
			}
			printf("Empty queue\n");
			return;
		}
	}

	if (ch == 1)			//если хватило элементов в очереди на выкидывание 
	{
		ch = 0;
		s = s / i;
		printf("%d\n", s);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	int code;
	scanf("%d %d", &N, &M);
	queue* q = create(N);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &code);
		where_is_the_end(code, q);
		if (code > 0)
		{
			i += code;
		}
	}

	return 0;
}

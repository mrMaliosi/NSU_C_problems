//Ну что, потанцуем! 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

///////////////Базовые функции v1.0///////////////
void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int* Min(int* a, int* b)
{
	if (b < a)
	{
		return b;
	}
	return a;
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

////////////Интерфейс кучи (элементы от 0)/////////////
typedef struct Heap {
	int length;
	int heap_size;
	int* arr;
} heap;							//Денис внезапно вспомнил, что у него уровень английского B1+ 

int is_empty(heap* H)
{
	if (H->heap_size == 0)
	{
		return 1;
	}
	return 0;
}

int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	if (i == 0)
	{
		return 1;
	}
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

void sift_up(int i, heap* H)
{
	if (H->arr[i] > H->arr[parent(i)])
	{
		Swap(&H->arr[i], &H->arr[parent(i)]);
		sift_up(parent(i), H);
	}
}

void sift_down(int i, heap* H)
{
	int l = left(i);
	int r = right(i);
	if (l < H->heap_size)
	{
		if (r < H->heap_size)
		{
			if (H->arr[r] < H->arr[l])
			{
				if (H->arr[i] < H->arr[l])
				{
					Swap(&H->arr[i], &H->arr[l]);
					sift_down(l, H);
				}
			}
			else
			{
				if (H->arr[i] < H->arr[r])
				{
					Swap(&H->arr[i], &H->arr[r]);
					sift_down(r, H);
				}
			}
		}
		else
		{
			if (H->arr[i] < H->arr[l])
			{
				Swap(&H->arr[i], &H->arr[l]);
				sift_down(l, H);
			}
		}
	}
}

heap* create(int size)
{
	heap* H = (heap*)malloc(sizeof(heap));
	H->length = size;
	H->heap_size = 0;
	H->arr = (int*)malloc(sizeof(int) * size);
	return H;
}

void push(int a, heap* H)
{
	H->heap_size++;
	H->arr[H->heap_size - 1] = a;
	sift_up(H->heap_size - 1, H);
}

int top(heap* H)
{
	return H->arr[0];
}

int pop(heap* H)
{
	if (is_empty(H) == 0)
	{
		int a = H->arr[0];
		H->arr[0] = H->arr[H->heap_size - 1];
		H->heap_size--;
		sift_down(0, H);
		return a;
	}
	else
	{
		printf("Heap is empty\n");
		return -1;
	}
}

void imagine_that_heap_is_empty(heap* H)
{
	H->heap_size = 0;
}

void heap_become_array(int N, heap* H)			//лёгким движением ноликов и единиц куча превращается...
{
	int a;										//Куча превращается...
	for (int i = 0; i < N; ++i)					//Великолепная и бесподобная не финансовая пирамида (правда-правда)...
	{											//Превращается...
		a = H->arr[i];							//Я сказал превращается...
		printf("%d ", a);						//В элегантный набор символов!
	}
}
////////////Конец интерфейса кучи/////////////

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, R = 0, L = 0, ans;
	int q[200500], v, vp;
	char a;
	scanf("%d\n", &N);
	heap* H = create(N + 1);
	heap* Hp = create(N + 1);									//Hp - остаточная куча. Здесь хранятся уже пройденные, но ещё не удалённые значения. 
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &q[i]);
	}

	scanf("%c", &a);								//считываем '\n'
	for (int i = 0; i < 2 * N - 1; ++i)
	{
		scanf("%c", &a);
		if (a == 'R')
		{
			++R;
			push(q[R - 1], H);
			ans = top(H);
			printf("%d\n", ans);
		}
		else
		{
			++L;
			v = top(H);
			if (v > q[L - 1])							//Если набольший элемент кучи всё ещё принадлежит окну, то мы запоминаем, какой элемент больше не с нами (да шучу, он просто не входит в окно) 
			{
				push(q[L - 1], Hp);
				printf("%d\n", v);
			}
			else									//Если набольший элемент кучи больше не принадлежит окну, то начинаем убирать верхние элементы до тех пор, пока они являются уже использованными элементами
			{
				pop(H);
				v = top(H);
				if (is_empty(Hp) != 1)
				{
					vp = top(Hp);
					while ((is_empty(Hp) != 1) && (v == vp))
					{
						v = pop(H);
						vp = pop(Hp);
						v = top(H);
						vp = top(Hp);
					}
				}

				printf("%d\n", v);
			}
		}
	}


	return 0;
}
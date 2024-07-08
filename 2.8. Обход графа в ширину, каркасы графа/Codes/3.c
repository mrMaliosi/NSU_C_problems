#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct City {
	int x;
	int y;
	int N;
} city;

typedef struct Highway {
	int N1;
	int N2;
	double D;
} way;

/////////////////////DSU/////////////////////
void MakeSet(int p[], int x)				//Создаём дерево из одного элемента
{
	p[x] = x;
}

int Find(int p[], int x)					//Поиск корня дерева
{
	if (p[x] == x)
	{
		return x;
	}

	return p[x] = Find(p, p[x]);
}

int Unite(int p[], int x, int y)			//По идее, тут надо бы написать AVL-дерево, 
{											//но мне равится мысль о том, что хаос может создать порядок.
	x = Find(p, x);
	y = Find(p, y);
	if (x == y)
	{
		return 0;							//Объеденение уже произошло в прошлом
	}
	else
	{
		if (rand() % 2 == 0)
		{
			p[x] = y;
		}
		else
		{
			p[y] = x;
		}
		return 1;							//Объединение произведено успешно
	}
}
////////////////////Конец DSU//////////////////////

void shell_sort(way q[], int N)
{
	int h = 1;
	while (h < N / 6)
	{
		h = 3 * h + 1;
	}

	int j, k;
	double x;
	way c;
	while (h >= 1)
	{
		for (int i = 0; i < h; ++i)
		{
			j = i + h;
			while (j < N)
			{
				x = q[j].D;
				c = q[j];
				k = j - h;
				while ((k >= i) && (q[k].D > x))
				{
					q[k + h] = q[k];
					k = k - h;
				}
				q[k + h] = c;
				j = j + h;
			}
		}

		h = (h - 1) / 3;
	}
}

city C[1000];
way W[1000000];
int p[1000];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	scanf("%d", &N);
	int x, y;
	for (int i = 0; i < N; ++i)						//Нумерация городов с нуля, а дорог с единицы
	{												//Нет, я не сумасшедший, так надо
		scanf("%d %d", &x, &y);
		C[i].x = x;
		C[i].y = y;
		C[i].N = i + 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		MakeSet(p, i);								//инициализация леса
	}


	int M;											//Ввод уже построенных Хайвэев (ух, ну и словечко)
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &x, &y);
		Unite(p, x, y);
	}

	int b = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			W[b].N1 = C[i].N;
			W[b].N2 = C[j].N;
			W[b].D = sqrt((C[i].x - C[j].x) * (C[i].x - C[j].x) + (C[i].y - C[j].y) * (C[i].y - C[j].y));
			++b;
		}
	}
	shell_sort(W, b);

	//Алгоритм Краскала
	int ch = 0;
	for (int i = 0; i < b; ++i)
	{
		ch = Unite(p, W[i].N1, W[i].N2);
		if (ch == 1)
		{
			printf("%d %d\n", W[i].N1, W[i].N2);
		}
	}

	printf("\n");

	return 0;
}

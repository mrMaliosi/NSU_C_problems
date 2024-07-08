#define _CRT_SECURE_NO_WARNINGS		//О чудо, Денис снова что-то комментирует. Надолго ли?
#include <stdio.h>
#include <string.h>

char l[25][200];				//лист исключений
char q[10000][200];				//все слова в тексте
char b[200];					//просто строка
int ans[10000] = { 0 };			//количество слов номера i в тексте

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i = 1, j = 0, ch = 1;
	char a;

	scanf("%c", &a);
	l[0][0] = a;
	while (a != '\n')			//до перевода строки водим слова-исключения
	{
		scanf("%c", &a);
		if ((a != ' ') && (a != '\n'))
		{
			l[j][i] = a;
			++i;
		}
		else
		{
			l[j][i] = '\0';
			++j;
			i = 0;
		}
	}

	i = 0;
	int sch = 0;
	while (1 > 0)					//основной цикл обработки текста
	{
		scanf("%c", &a);
		if (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')))
		{
			if ((a >= 'A') && (a <= 'Z'))						//СМЕРТЬ БОЛЬШИМ БУКВАМ!
			{
				a = a - 'A' + 'a';
			}
			b[i] = a;
			++i;
		}
		else if (a == '*')							//Это конец текста?!
		{
			scanf("%c", &a);
			if (a == '*')
			{
				break;
			}
			else
			{
				b[i] = '*';
				++i;
				b[i] = a;
				++i;
			}
		}
		else if (i != 0)
		{
			b[i] = '\0';
			ch = 1;
			for (int k = 0; k < j; ++k)				//не является ли слово исключением?
			{
				if (strcmp(l[k], b) == 0)
				{
					ch = 0;
					break;
				}
			}
			if (ch == 1)							//хорошо, а мы тебя раньше видели или нет?
			{
				for (int k = 0; k < sch; ++k)
				{
					if (strcmp(q[k], b) == 0)
					{
						++ans[k];
						ch = 0;
						break;
					}
				}

				if (ch == 1)				//Не видели? Ну так давай к нам
				{
					strcpy(q[sch], b);
					++sch;
				}

				i = 0;

			}

		}
	}

	if (i != 0)									//если в конце осталось необработанное нами слово
	{
		b[i] = '\0';
		ch = 1;
		for (int k = 0; k < j; ++k)				//не является ли слово исключением?
		{
			if (strcmp(l[k], b) == 0)
			{
				ch = 0;
				break;
			}
		}
		if (ch == 1)							//хорошо, а мы тебя раньше видели или нет?
		{
			for (int k = 0; k < sch; ++k)
			{
				if (strcmp(q[k], b) == 0)
				{
					++ans[k];
					ch = 0;
					break;
				}
			}

			if (ch == 1)				//Не видели? Ну так давай к нам
			{
				strcpy(q[sch], b);
				++sch;
			}

			i = 0;

		}
	}

	int maxi = -1, maxp;
	for (i = 0; i < sch; ++i)			//находим самое частовстречаемое слово 
	{
		if (ans[i] > maxi)
		{
			maxi = ans[i];
			maxp = i;
		}
	}


	for (int i = 0; q[maxp][i] != '\0'; ++i)		//выводим самое частовстречаемое слово 
	{
		if ((q[maxp][i] >= 'a') && (q[maxp][i] <= 'z'))
		{
			printf("%c", q[maxp][i] - 'a' + 'A');
		}
		else										//Зачем? Ну, например, для апострофа
		{
			printf("%c", q[maxp][i]);
		}
	}

	return 0;
}

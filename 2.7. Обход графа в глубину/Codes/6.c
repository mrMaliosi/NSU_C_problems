#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef unsigned int ul;

/////////////////Интерфейс мультиграфа и списка///////////////////
typedef struct List {
	ul code1;					//совпадает с ключом
	ul code2;					//уменьшает количество сравнений (в теории)
	char* s;
	struct List* next;
} list;

typedef struct Multinode {
	ul code1;					//совпадает с ключом
	ul code2;					//уменьшает количество сравнений (в теории)
	int visited;				//отметка о посещении (ну прям не граф, а студент какой-то)
	char* s;
	struct Multinode* next;		//хэш-таблица
	struct List* node;			//список смежности для узла
} m_node;						//мультиузел для мультиграфа в мультикоде мульти-Малиновского

typedef struct Asker {
	char* s;
	ul code1;
	ul code2;
} asker;



m_node* q[1000005] = { NULL };
char S[25];
char string[25];
list* nodes = NULL;
asker askman[100005];

list* push(list* head, ul code1, ul code2, char* s)
{
	list* p = (list*)malloc(sizeof(list));
	p->next = head;
	p->code1 = code1;
	p->code2 = code2;
	p->s = (char*)malloc(sizeof(char) * (22));
	int i = 0;
	while (*s != '\0')
	{
		p->s[i] = *s;
		++i;
		++s;
	}
	p->s[i] = '\0';
	return p;
}

void unfair_of_life(list* head)		//Время пришло, воин...
{
	while (head != NULL)
	{
		list* p = head;
		head = head->next;
		free(p);
	}
}

ul push_after(m_node* head, ul code1, ul code2, char* s, m_node* q[], list* nodes)
{
	if (head == NULL)
	{
		m_node* p = (m_node*)malloc(sizeof(m_node));
		p->code1 = code1;
		p->code2 = code2;
		p->s = (char*)malloc(sizeof(char) * (22));
		p->visited = 0;
		p->node = nodes;
		int i = 0;
		while (*s != '\0')
		{
			p->s[i] = *s;
			++i;
			++s;
		}
		p->s[i] = '\0';
		p->next = NULL;
		head = p;
		q[code1] = head;
		return 1;
	}
	else
	{
		int i = 0;
		while (head->next != NULL)
		{
			if ((code2 == head->code2) && (strcmp(s, head->s) == 0))
			{
				return 0;
			}
			head = head->next;
			++i;
		}

		if ((code2 == head->code2) && (strcmp(s, head->s) == 0))			//Предельный случай
		{
			return 0;
		}

		m_node* p = (m_node*)malloc(sizeof(m_node));
		p->code1 = code1;
		p->code2 = code2;
		p->s = (char*)malloc(sizeof(char) * (22));
		p->node = nodes;
		p->visited = 0;
		i = 0;
		while (*s != '\0')
		{
			p->s[i] = *s;
			++i;
			++s;
		}
		p->s[i] = '\0';
		p->next = NULL;
		head->next = p;
		//q[code1] = p;
		return 1;
	}
}

ul hesh_functionator(char* q)							//ТРЕПЕЩИ, ПЭРРИ УТКОНОС, я СПЛАГИАТИЛ ХЭШ-функционатор!!!
{
	ul a = 0;
	while (*q != '\0')
	{
		a = (a * 31 + *q - 'a' + 1) % 1000003;
		++q;
	}
	return a;
}

ul al[27] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
ul hesh_functionator3000(char* q)						//ТРЕПЕЩИ, ПЭРРИ УТКОНОС, я ИЗОБРЁЛ ХЭШ-функционатор3000!!!
{
	ul a = 0;
	while (*q != '\0')
	{
		if (a == '_')
		{
			a = a + al[26];
		}
		else
		{
			a = a + al[*q - 'a'];
		}
		++q;
	}
	return a;
}

m_node* node_finder(m_node* head, ul code1, ul code2, char* s)
{
	while (head != NULL)
	{
		if ((code2 == head->code2) && (strcmp(s, head->s) == 0))
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void DFS(ul start, ul code2, char* s, m_node* q[], int* ch, int count)
{
	m_node* Starter;
	m_node* starter;
	list* head;
	Starter = q[start];
	while (Starter != NULL)
	{
		if ((code2 == Starter->code2) && (strcmp(s, Starter->s) == 0))
		{
			Starter = Starter;
			break;
		}
		Starter = Starter->next;
	}

	Starter->visited = 1;
	head = Starter->node;
	while (head != NULL)
	{
		starter = q[head->code1];
		while (starter != NULL)
		{
			if ((head->code2 == starter->code2) && (strcmp(head->s, starter->s) == 0))
			{
				starter = starter;
				break;
			}
			starter = starter->next;
		}

		if (starter == NULL)
		{

		}
		else if (starter->visited == 0)
		{
			DFS(starter->code1, starter->code2, starter->s, q, ch, count + 1);
			starter->visited = 2;
		}
		else if (starter->visited == 1)
		{
			++ch[0];
		}
		head = head->next;
	}
	Starter->visited = 2;
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	scanf("%d", &N);
	ul code1, code2, k;
	int ch = 1, b = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", S);
		code1 = hesh_functionator(S);
		code2 = hesh_functionator3000(S);
		askman[b].code1 = code1;
		askman[b].code2 = code2;
		askman[b].s = (char*)malloc(sizeof(char*) * (22));
		for (k = 0; S[k] != '\0'; ++k)
		{
			askman[b].s[k] = S[k];
		}
		askman[b].s[k] = '\0';
		scanf("%d", &M);
		for (int j = 0; j < M; ++j)
		{
			scanf("%s", string);
			code1 = hesh_functionator(string);
			code2 = hesh_functionator3000(string);
			nodes = push(nodes, code1, code2, string);
		}

		ch = push_after(q[askman[b].code1], askman[b].code1, askman[b].code2, S, q, nodes);
		nodes = NULL;
		if (ch == 0)
		{
			printf("multiple definition");
			return 0;
		}
		++b;
	}

	int f = 0;
	for (int i = 0; i < b; ++i)
	{
		m_node* starter;
		starter = node_finder(q[askman[i].code1], askman[i].code1, askman[i].code2, askman[i].s);
		if (starter->visited == 0)
		{
			DFS(askman[i].code1, askman[i].code2, askman[i].s, q, &f, 0);
			if (f != 0)
			{
				printf("loop detected");
				return 0;
			}
		}
	}

	printf("correct");
	return 0;
}

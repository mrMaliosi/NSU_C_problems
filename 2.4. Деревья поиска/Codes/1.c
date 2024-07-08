#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

typedef struct derevo {					//Каждый мужчина должен посадить дерево... Выполнено)
	int data;
	int count;
	struct derevo* left;
	struct derevo* right;
} tree;

int q[500500];

tree* Tree_create(tree* root, int a)
{
	if (root == NULL)
	{
		root = (tree*)malloc(sizeof(tree));
		root->data = a;
		root->count = 1;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (a < root->data)
	{
		root->left = Tree_create(root->left, a);
	}
	else if (a > root->data)
	{
		root->right = Tree_create(root->right, a);
	}
	else if (a == root->data)
	{
		root->count++;
	}
	return root;
}

void ha_ha_sort(tree* derevo, FILE* f)							//Зачем сортировать, когда можно просто правильно читать?)
{
	if (derevo == NULL)
	{
		return;
	}

	ha_ha_sort(derevo->left, f);
	while (derevo->count > 0)
	{
		fwrite(&derevo->data, sizeof(int), 1, f);
		derevo->count--;
	}

	ha_ha_sort(derevo->right, f);
	while (derevo->count > 0)
	{
		fwrite(&derevo->data, sizeof(int), 1, f);
		derevo->count--;
	}
	free(derevo);
}

int shuffleinator3000(int N, int q[])							//Трепещи, Пэрри утконос! Я изобрёл shuffleinator!
{
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		int j = rand() % N;
		int c = q[i];
		q[i] = q[j];
		q[j] = c;
	}

}

int main() {
	FILE* f;
	f = fopen("input.bin", "rb");
	if ((f = fopen("input.bin", "rb")) == NULL)
	{
		fprintf(stderr, "Открыть файл ввода не удалось\n");
		return 1;
	}

	int N;
	fread(&N, sizeof(int), 1, f);
	tree* derevo = NULL;
	int a;
	for (int i = 0; i < N; ++i)
	{
		fread(&a, sizeof(int), 1, f);
		q[i] = a;
	}
	fclose(f);

	f = fopen("output.bin", "wb");
	if ((f = fopen("output.bin", "wb")) == NULL)
	{
		fprintf(stderr, "Открыть файл вывода не удалось\n");
		return 2;
	}

	shuffleinator3000(N, q);
	for (int i = 0; i < N; ++i)
	{
		derevo = Tree_create(derevo, q[i]);
	}
	ha_ha_sort(derevo, f);
	fclose(f);

	return 0;
}

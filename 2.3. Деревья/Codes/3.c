#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
} tree;

tree* Tree_create(int a, tree* root)
{
	if (root == NULL)
	{
		root = (tree*)malloc(sizeof(tree));
		root->data = a;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (a < root->data)
	{
		root->left = Tree_create(a, root->left);
	}
	else if (a > root->data)
	{
		root->right = Tree_create(a, root->right);
	}
	return root;
}

int son_finder(tree* root)			//Найдём потерявшихся сыновей!
{
	int c = 0;
	if (root != NULL)
	{
		c += son_finder(root->left);
		c += son_finder(root->right);
	}
	else
	{
		return 1;
	}

	return c;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	tree* derevo = NULL;
	int a, c = 0;
	scanf("%d", &a);
	derevo = Tree_create(a, derevo);
	while (scanf("%d", &a) == 1)
	{
		Tree_create(a, derevo);
	}
	c = son_finder(derevo);
	printf("%d", c / 2);
	return 0;
}
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

void tree_scanner_straight(tree* root)			//Такой прямолинейный...
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		tree_scanner_straight(root->left);
		tree_scanner_straight(root->right);
	}
	else
	{
		return;
	}
}

void tree_scanner_reverse(tree* root)
{
	if (root != NULL)
	{
		tree_scanner_reverse(root->left);
		tree_scanner_reverse(root->right);
		printf("%d ", root->data);
	}
	else
	{
		return;
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	tree* derevo = NULL;
	int a;
	scanf("%d", &a);
	derevo = Tree_create(a, derevo);
	while (scanf("%d", &a) == 1)
	{
		Tree_create(a, derevo);
	}
	tree_scanner_straight(derevo);
	printf("\n");
	tree_scanner_reverse(derevo);
	return 0;
}
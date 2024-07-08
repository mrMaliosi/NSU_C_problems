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

int higher(tree* root, int h)
{
	int H1, H2;
	if (root != NULL)
	{
		H1 = higher(root->left, h + 1);
		H2 = higher(root->right, h + 1);
		if (H1 >= H2)
		{
			return H1;
		}
		else
		{
			return H2;
		}

	}
	else
	{
		return h - 1;
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	tree* derevo = NULL;
	int a, h = 0;
	scanf("%d", &a);
	derevo = Tree_create(a, derevo);
	while (scanf("%d", &a) == 1)
	{
		Tree_create(a, derevo);
	}
	h = higher(derevo, h);
	printf("%d", h);
	return 0;
}
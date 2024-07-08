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

int level_finder(tree* root, int level, int recursion_level)
{
	int c = 0;
	if (recursion_level == level)
	{
		return 1;
	}
	else
	{
		if (root->left != NULL)
		{
			c += level_finder(root->left, level, recursion_level + 1);
		}

		if (root->right != NULL)
		{
			c += level_finder(root->right, level, recursion_level + 1);
		}

	}

	return c;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	tree* derevo = NULL;
	int a, c = 0, level;
	scanf("%d", &level);
	scanf("%d", &a);
	derevo = Tree_create(a, derevo);
	while (scanf("%d", &a) == 1)
	{
		Tree_create(a, derevo);
	}
	c = level_finder(derevo, level, 0);
	printf("%d", c);
	return 0;
}
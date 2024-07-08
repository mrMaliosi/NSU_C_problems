#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/////////////////////////////////AVL-дерево/////////////////////////////////
typedef struct derevo {
	int data;
	int height;
	struct derevo* left;
	struct derevo* right;
} tree;

unsigned char height(tree* p)
{
	return p ? p->height : 0;			//если p существует, 
}

int bfactor(tree* p)
{
	return height(p->right) - height(p->left);				//-1 - перевес влево на 1, 1 - перевес вправо на 1;
}

void fixheight(tree* p)										//вычисление разницы в высотах левого и правого поддерева
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

tree* Leftrotator(tree* p)
{
	tree* q = p->right;
	p->right = q->left;
	q->left = p;
	fixheight(p);
	fixheight(q);
	return q;
}

tree* Rightrotator(tree* p)
{
	tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

tree* balance(tree* p)					// балансировка узла p
{
	fixheight(p);						//вычисление высоты p
	int balance = bfactor(p);
	if (balance == -2)					////высота левого поддерева больше высоты правого
	{
		if (bfactor(p->left) > 0)						//если:     7				, то низ повернём на 90 градусов влево
		{												//       v5
			p->left = Leftrotator(p->left);			    //          6
		}
		return Rightrotator(p);							//И перейдём к левобамбуковому случаю
	}
	if (balance == 2)					//высота правого поддерева больше высоты левого
	{
		if (bfactor(p->right) < 0)						//если:     6				, то низ повернём на 90 градусов вправо
		{												//            v7
			p->right = Rightrotator(p->right);			//          4
		}
		return Leftrotator(p);							//И перейдём к правобамбуковому случаю
	}

	return p; // балансировка не нужна
}

tree* add(tree* root, int a)
{
	if (root == NULL)
	{
		root = (tree*)malloc(sizeof(tree));
		root->data = a;
		root->height = 1;
		root->left = NULL;
		root->right = NULL;
		printf("added\n");
		return root;
	}
	else if (a < root->data)
	{
		root->left = add(root->left, a);
	}
	else if (a > root->data)
	{
		root->right = add(root->right, a);
	}
	else if (a == root->data)
	{
		printf("dupe\n");
		return root;
	}

	return balance(root);
}

tree* min_searcher(tree* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

tree* min_killer(tree* root)
{
	if (root->left != NULL)
	{
		root->left = min_killer(root->left);
	}
	else
	{
		return root->right;
	}
	return balance(root);
}


tree* Remove(tree* root, int a)
{
	if (root == NULL)
	{
		printf("miss\n");
		return root;
	}
	else if (root->data < a)
	{
		root->right = Remove(root->right, a);
	}
	else if (root->data > a)
	{
		root->left = Remove(root->left, a);
	}
	else if (root->data == a)
	{
		if ((root->left == NULL) && (root->right == NULL))
		{
			root = NULL;
			printf("removed\n");
			return root;
		}
		else if (root->right == NULL)
		{
			root = root->left;
			printf("removed\n");
		}
		else
		{
			tree* q = min_searcher(root->right);
			tree* l = root->left;
			tree* r = min_killer(root->right);
			root = q;
			root->left = l;
			root->right = r;
			printf("removed\n");
		}
	}

	/*if (root->right->data == root->data)
	{
		printf("Dead %d\n", a);
	}*/

	return balance(root);
}

void lower(tree* root, int a, int ch, int ans)
{
	if (root == NULL)
	{
		if (ch == 0)
		{
			printf("###\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	else if (a > root->data)
	{
		lower(root->right, a, ch, ans);
	}
	else if (a < root->data)
	{
		lower(root->left, a, 1, root->data);
	}
	else if (a == root->data)
	{
		printf("%d\n", root->data);
	}
}

///////////////////////////////Отладочные функции///////////////////////////////
int AVL(tree* root) //returns true if the given tree is AVL otherwise false.
{
	if (root == NULL)
	{
		return 1;
	}

	int leftheight = height(root->left);
	int rightheight = height(root->right);
	if (abs(leftheight - rightheight) <= 1 && AVL(root->left) && AVL(root->right))
	{
		return 1;
	}
	return 0;
}

void shuffleinator3000(int N, int q[])							//Трепещи, Пэрри утконос! Я изобрёл shuffleinator!
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

int q[16];

///////////////////////////////А здесь начинается шоу///////////////////////////////
char s[100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int M;
	scanf("%d", &M);
	tree* derevo = NULL;
	int a;
	for (int i = 0; i < M; ++i)
	{
		scanf("%s", s);
		if (s[0] == 'a')
		{
			scanf("%d", &a);
			derevo = add(derevo, a);
		}
		else if (s[0] == 'r')
		{
			scanf("%d", &a);
			derevo = Remove(derevo, a);
		}
		else if (s[0] == 'l')
		{
			scanf("%d", &a);
			lower(derevo, a, 0, 0);
		}

	}

	return 0;
}

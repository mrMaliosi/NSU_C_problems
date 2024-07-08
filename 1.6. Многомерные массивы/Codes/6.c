#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 251

int k[N][N];				//����
char q[N][N];				//�����-�� ������������� �������
char b[63000];				//������ ������

void vvod_massiva_2_char(char a[][N], int n)				//������� ��� ����� ���������� ������� ���� char (�� ������, � �����������!)
{
	char c;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%c", &c);
			if ((c == ' ') || (c == '\n'))
			{
				--j;
			}
			else
			{
				q[i][j] = c;
			}
		}
	}
}

void vvod_massiva_2_int(int a[][N], int n)				//������� ��� ����� ���������� ������� ���� int 
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, dl = 0;		//����� �������������� ������
	scanf("%d", &n);	//���� �����
	n = 2 * n;
	vvod_massiva_2_int(k, n);
	vvod_massiva_2_char(q, n);

	//4 �������� ��� �����������
	for (int i = 0; i < n; ++i)			//0�
	{
		for (int j = 0; j < n; ++j)
		{
			if (k[i][j] == 1)
			{
				b[dl] = q[i][j];
				q[i][j] = '*';			//�������� ������ ��� ��������������
				++dl;
			}
		}
	}

	for (int j = 0; j < n; ++j)				//90�
	{
		for (int i = n - 1; i >= 0; --i)
		{
			if (k[i][j] == 1)
			{
				if (q[j][n - 1 - i] != '*')			//� � ���� (������) ������ ����� �� ��������?
				{
					b[dl] = q[j][n - 1 - i];
					q[j][n - 1 - i] = '*';
					++dl;
				}
				else
				{
					printf("No");
					return 0;
				}
			}
		}
	}


	for (int i = n - 1; i >= 0; --i)		//180�
	{
		for (int j = n - 1; j >= 0; --j)
		{
			if (k[i][j] == 1)
			{
				if (q[n - 1 - i][n - 1 - j] != '*')			//� � ���� (������) ������ ����� �� ��������?
				{
					b[dl] = q[n - 1 - i][n - 1 - j];
					q[n - 1 - i][n - 1 - j] = '*';
					++dl;
				}
				else
				{
					printf("No");
					return 0;
				}
			}
		}
	}


	for (int j = n - 1; j >= 0; --j)				//270�
	{
		for (int i = 0; i < n; ++i)
		{
			if (k[i][j] == 1)
			{
				if (q[n - 1 - j][i] != '*')			//� � ���� (������) ������ ����� �� ��������?
				{
					b[dl] = q[n - 1 - j][i];
					q[n - 1 - j][i] = '*';
					++dl;
				}
				else
				{
					printf("No");
					return 0;
				}
			}
		}
	}
	b[dl] = '\0';

	for (int i = 0; i < dl; ++i)			//����� ��������������� ���������
	{
		printf("%c", b[i]);
	}
	printf("\n");
	return 0;
}

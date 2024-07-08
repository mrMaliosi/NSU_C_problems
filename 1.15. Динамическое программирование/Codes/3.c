#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[205][50005];
int W[205];
int C[205];
int Ans[205];

int main() {											//��, �� ��� ����.
	freopen("input.txt", "r", stdin);					//��� ���� �������������� ������...
	freopen("output.txt", "w", stdout);					//�� ��� �, ���� �������������� ������...
	int N, M;											//����� ���������!)
	int w, c;											//�� � ���� ������ ���������, �� � �������� ����� ���������� (��-��-��!) 
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)							//��� ������� �� ����. �����, ������ �����. ��� � �� � ������. (�������...)
	{
		scanf("%d %d", &w, &c);							//����� ����� �����, � ��� ��� ��� ���!
		W[i] = w;
		C[i] = c;										//������ ���-�� ���� �� ���� �... �������!
	}
	//������� ����� �... ���������
	for (int i = 0; i <= M; ++i)
	{													//������ ���-�� ������ � ���... (ATTENSION! �������� ������ ������� ���������������-���������� ����������!)
		dp[0][W[0] + i] = C[0];							//�� ��������� ���������� ��������� � ���������� ������� ���������, ��� ����� ����� ���������. 
	}													//�������� ���)

	//���������� ������
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			while ((j < W[i]) && (j <= M))
			{
				dp[i][j] = dp[i - 1][j];
				++j;
			}

			if (C[i] + dp[i - 1][j - W[i]] >= dp[i - 1][j])
			{
				dp[i][j] = C[i] + dp[i - 1][j - W[i]];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	/*for (int i = 0; i < N; ++i)
	{
		printf("%d %d ", W[i], C[i]);
		for (int j = 0; j < M; ++j) 
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/

	//����� ���������
	int maxi = -1, maxp;
	for (int i = 0; i <= M; ++i)
	{
		if (dp[N - 1][i] > maxi)
		{
			maxi = dp[N - 1][i];
			maxp = i;
		}
	}

	//�������� ���
	int K = 0, Wans = maxp, Cans = dp[N - 1][maxp], b = 0, j;
	for (j = N - 1; j > 0; --j)
	{
		if (dp[j][maxp] != dp[j - 1][maxp])
		{
			++K;
			Ans[b] = j + 1;
			maxp -= W[j];
			++b;
		}
	}

	if (maxp != 0)
	{
		++K;
		Ans[b] = j + 1;
	}
	else
	{
		--b;
	}
	


	printf("%d %d %d\n", K, Wans, Cans);
	for (b = b; b >= 0; --b)
	{
		printf("%d ", Ans[b]);
	}
	return 0;
}

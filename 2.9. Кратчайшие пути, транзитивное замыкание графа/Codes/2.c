#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector <vector <int> > q(1000);
vector <vector <int> > T(1000);
int d[305];
int ans[305][305];
int previous[305];
int answ[305];

void Initialize(int start, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        d[i] = 1000005000;
    }
    d[start] = 0;
}

int Relax(int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        previous[v] = u;
        return 1;
    }
    return 0;
}

void Deic(int start, int n)
{
    int ch = -1;
    Initialize(start, n);
    priority_queue <pair <int, int>, deque <pair <int, int> >, greater<pair <int, int> > > qu;
    pair <int, int> p;
    p.first = 0;
    p.second = start;
    qu.push(p);
    while (qu.empty() != 1)
    {
        start = qu.top().second;
        qu.pop();
        for (int i = 0; i < q[start].size(); ++i)
        {
            ch = Relax(start, q[start][i], T[start][i]);
            if (ch == 1)
            {
                p.first = d[q[start][i]];
                p.second = q[start][i];
                qu.push(p);
            }
        }

    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, P, K;
    int x, y, t;
    cin >> N >> M >> P >> K;
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y >> t;
        q[x].push_back(y);
        q[y].push_back(x);
        T[x].push_back(t);
        T[y].push_back(t);
    }

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            ans[i][j] = -1;
        }
    }

    int b = 0;
    for (int i = 0; i < P; ++i)
    {
        cin >> x >> y;
        if (ans[x][y] == -1)
        {
            Deic(x, N);
            cout << d[y] << " ";
            answ[b] = y;
            ++b;
            while (y != x)
            {
                answ[b] = previous[y];
                y = previous[y];
                ++b;
            }
            cout << b << " ";
            for (int j = b - 1; j >= 0; --j)
            {
                cout << answ[j] << " ";
            }

            for (int j = 1; j <= N; ++j)
            {
                ans[x][j] = d[j];
            }
            cout << endl;
        }
        else
        {
            Deic(x, N);
            cout << d[y] << " ";
            answ[b] = y;
            ++b;
            while (y != x)
            {
                answ[b] = previous[y];
                y = previous[y];
                ++b;
            }
            cout << b << " ";
            for (int j = b - 1; j >= 0; --j)
            {
                cout << answ[j] << " ";
            }
            cout << endl;
        }
        b = 0;
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> x >> y;
        if (ans[x][y] == -1)
        {
            Deic(x, N);
            cout << d[y] << endl;
            for (int j = 1; j <= N; ++j)
            {
                ans[x][j] = d[j];
            }
        }
        else
        {
            cout << ans[x][y] << endl;
        }

    }
}
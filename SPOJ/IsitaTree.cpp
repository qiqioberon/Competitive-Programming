#include <iostream>
#include <vector>
using namespace std;
bool visited[10000];
vector<vector<int>> adjacentList(10000);
void dfs(int v)
{
    visited[v] = true;
    for (auto ver : adjacentList[v])
    {
        if (!visited[ver])
        {
            dfs(ver);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        visited[a] = false;
        visited[b] = false;
        adjacentList[a].push_back(b);
        adjacentList[b].push_back(a);
    }
    int res = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            res++;
        }
    }
    if (res == 1 && e == v - 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj(100000);
vector<int> jarak(100000);
int p;
void dfs(int u, int f)
{
    for (auto data : adj[u])
    {
        if (data == f)
            continue;
        jarak[data] = jarak[u] + 1;
        if (jarak[data] > jarak[p])
            p = data;
        dfs(data, u);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    jarak[p] = 0;
    dfs(p, 0);
    cout << jarak[p];
}
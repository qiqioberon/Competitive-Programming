#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int SIZEE = 2005;
vector<vector<int>> adj(SIZEE);
vector<int> color(SIZEE);
bool bipartite = true;
void dfs(int a, int b)
{
    color[a] = (b == 5 ? 10 : 5);
    for (auto data : adj[a])
    {
        if (color[data] == 0)
        {
            dfs(data, color[a]);
        }
        else if (color[data] == color[a])
        {
            bipartite = false;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    int v, e;
    for (int j = 1; j <= tc; j++)
    {
        cin >> v >> e;
        bipartite = true;
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= v; i++)
        {
            color[i] = 0;
        }
        for (int data = 1; data <= v; data++)
        {
            if (color[data] == 0)
            {
                dfs(data, 5);
            }
        }
        cout << "Scenario #" << j << ":\n";
        if (bipartite)
            cout << "No suspicious bugs found!" << endl;
        else
            cout << "Suspicious bugs found!" << endl;

        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
        }
    }
}
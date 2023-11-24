#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int tc, total, angka;
    priority_queue<int> pq1, pq2;
    cin >> tc;
    while (tc--)
    {
        cin >> total;
        for (int query = 2; query > 0; query--)
            for (int i = 0; i < total; i++)
            {
                cin >> angka;
                if (query == 2)
                    pq1.push(angka);
                if (query == 1)
                    pq2.push(angka);
            }

        int perkalian, res = 0;
        while (!pq1.empty() && !pq2.empty())
        {
            perkalian = pq1.top() * pq2.top();
            pq1.pop();
            pq2.pop();
            res += perkalian;
        }
        cout << res << endl;
    }
}
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for (int j = 1; j <= tc; j++)
    {
        int need, offer, angka;
        priority_queue<int> pq;
        cin >> need >> offer;
        for (int i = 0; i < offer; i++)
        {
            cin >> angka;
            pq.push(angka);
        }
        int jumlah = 0, step = 0;
        while (!pq.empty())
        {
            step++;
            int x = pq.top();
            pq.pop();
            jumlah += x;
            // cout << "Jumlah " << jumlah << endl;
            if (jumlah >= need)
            {
                break;
            }
        }
        cout << "Scenario #" << j << ":" << endl;
        if (jumlah >= need)
        {
            cout << step << endl
                 << endl;
        }
        else
            cout << "impossible" << endl
                 << endl;
    }
}
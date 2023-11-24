#include <iostream>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    ll angka;
    priority_queue<ll, vector<ll>, greater<ll>> pq, menus;
    ll minus = 0, jumlah = 0;
    while (t--)
    {
        cin >> angka;
        if (angka < 0)
        {
            minus += angka;
            menus.push(angka);
        }
        else
        {
            pq.push(angka);
            jumlah += angka;
        }
    }

    if (minus == 0)
    {
        jumlah -= (2 * pq.top());
    }
    else if (jumlah == 0)
    {
        jumlah = (2 * menus.top()) - minus;
    }
    else
    {
        jumlah -= minus;
    }
    cout << abs(jumlah);
}
#include <iostream>
#include <unordered_map>
#include <algorithm>
#define ll long long
using namespace std;
unordered_map<ll, ll> maps;

ll maks(ll n)
{
    if (maps.find(n) != maps.end())
        return maps[n];
    if (n == 0)
        return 0;

    ll res;
    res = max(n, maks(n / 2) + maks(n / 3) + maks(n / 4));
    maps[n] = res;
    return res;
}

int main()
{
    ll n;
    while (cin >> n)
    {
        cout << maks(n) << endl;
    }
    return 0;
}
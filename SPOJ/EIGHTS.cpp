#include <iostream>
using namespace std;
#define ll long long

int main()
{
    const ll wenak = 1e10;
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        ll x = 192 + (n - 1) * 250;
        cout << x << endl;
    }
    return 0;
}

#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll a;
        cin >> a;
        // ll res = (ll)(2ll * (ll)(a - 1ll) * a) + 1ll;
        ll res = (a * (a + 2) * (2 * a + 1)) / 8;
        // ll res = (2ll * (a * a)) - (2 * a) + 1;
        cout << res << endl;
    }
}
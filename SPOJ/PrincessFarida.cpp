#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    for (ll j = 1; j <= t; j++)
    {
        ll q;
        cin >> q;
        if (q == 0)
        {
            cout << "Case " << j << ": " << 0 << endl;
            continue;
        }
        vector<ll> arr(q + 5, 0), dp(q + 5, 0);
        ll maks = 0;
        for (ll i = 1; i <= q; i++)
        {
            cin >> arr[i];
        }

        for (ll i = q; i >= 1; i--)
        {
            dp[i] = max(dp[i + 1], arr[i] + dp[i + 2]);
        }
        cout << "Case " << j << ": " << dp[1] << endl;
    }
}
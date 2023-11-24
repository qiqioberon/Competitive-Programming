#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int q;
        cin >> q;
        vector<int> dp(q + 5, 0);
        int maks = 0;
        for (int i = 1; i <= q; i++)
        {
            cin >> dp[i];
            maks = max(maks, dp[i]);
        }

        for (int i = 1; i <= q; i += 2)
        {
            if (i + 3 > q)
            {
                dp[i + 2] += dp[i];
                maks = max(maks, dp[i + 2]);
            }
            else
            {
                dp[i + 2] += dp[i];
                dp[i + 3] += dp[i + 1];
                maks = max({maks, dp[i + 2], dp[i + 3]});
            }
            if (i + 2 == q || i + 3 == q)
                break;
        }
        cout << "Case " << j << ": " << maks << endl;
    }
}
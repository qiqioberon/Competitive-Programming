#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int cases = 1; cases <= tc; cases++)
    {
        int n, q;
        cin >> n >> q;

        int sq = sqrt(n) + 1;
        vector<long long> qry(n + 1, 0);
        vector<vector<long long>> dp(sq, vector<long long>(sq, 0));
        for (int qr = 0; qr < q; qr++)
        {
            int a, b;
            cin >> a >> b;

            if (sq <= b)
            {
                for (int idx = a % b; idx <= n; idx += b)
                {
                    qry[idx]++;
                }
            }
            else
            {
                dp[a % b][b]++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < sq; j++)
            {
                qry[i] += dp[i % j][j];
            }
        }

        cout << "Case " << cases << ": ";
        for (int i = 1; i <= n; i++)
        {
            cout << qry[i] << " \n"[i == n];
        }
    }
    return 0;
}
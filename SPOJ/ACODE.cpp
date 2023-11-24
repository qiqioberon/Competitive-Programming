#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string input;
    while (cin >> input)
    {
        if (input == "0")
            break;
        int batas = input.length();
        vector<int> dp(batas, 0);
        dp[0] = 1;
        for (int i = 1; i < batas; i++)
        {
            int x = input[i] - '0';
            if (x > 0)
                dp[i] = dp[i - 1];

            int kali = (input[i - 1] - '0') * 10 + x;
            if (kali >= 10 && kali <= 26 && i == 1)
            {
                dp[i] += 1;
                // cout << dp[i] << endl;
            }
            else if (kali >= 10 && kali <= 26)
            {
                dp[i] += dp[i - 2];
            }

            // cout << kali << endl;
        }
        cout << dp[batas - 1] << endl;
    }
}
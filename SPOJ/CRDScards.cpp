#include <iostream>
using namespace std;

const int MOD = 1000007;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        long long angka;
        cin >> angka;

        long long x = (3LL * ((angka * 1LL * (angka + 1LL)) / 2LL) - angka) % MOD;
        if (x < 0)
        {
            x += MOD;
        }

        cout << x << endl;
    }
    return 0;
}

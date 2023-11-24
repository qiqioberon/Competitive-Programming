#include <iostream>
using namespace std;
int main()
{
    int tc, a;
    cin >> tc;
    while (tc--)
    {
        cin >> a;
        int res = 0;
        while (a % 5 != 0)
        {
            a--;
        }
        while (a > 0)
        {
            res += a / 5;
            a /= 5;
            while (a % 5 != 0)
            {
                a--;
            }
        }
        cout << res << endl;
    }
}
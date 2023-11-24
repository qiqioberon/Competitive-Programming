#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        string s, result;
        cin >> n >> c >> s;
        int shift = 0;
        for (char kar : s)
        {
            if (kar == c)
                break;
            else
                shift++;
        }

        for (int i = shift; i < n; i++)
            result += s[i];

        for (int i = 0; i < shift; i++)
            result += s[i];

        if (c == 'x' && result[0] == 'x')
        {
            cout << 0 << endl;
            continue;
        }

        int st1 = -1, st2 = -1, fn1 = -1, fn2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (result[i] == c && st1 == -1)
                st1 = i;
            else if (result[i] == c && st1 != -1 && st2 == -1 && fn1 != -1)
                st2 = i;
            if (result[i] == 'x' && fn1 == -1)
                fn1 = i;
            else if (result[i] == 'x' && fn1 != -1 && fn2 == -1 && st1 != -1 && st2 != -1)
                fn2 = i;
        }

        if (fn2 == -1 && st2 == -1)
            cout << fn1 - st1 << endl;
        else if (fn2 == -1)
            cout << max(fn1 - st1, (fn1 + n) - st2) << endl;
        else
            cout << max(fn1 - st1, fn2 - st2) << endl;
    }

    return 0;
}

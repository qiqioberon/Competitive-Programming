#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        if (c == 'x')
        {
            cout << 0 << endl;
            continue;
        }

        queue<int> stX, urutanCque;
        queue<int> temp1;
        int min_wait = 0;
        int countX = 0, countC = 0;
        for (int i = 0; i < n; i++)
        {
            if (countC < 2 || countX < 2)
            {
                if (s[i] == 'x' && stX.back() != 'x')
                {
                    countX++;
                    temp1.push(i);
                    stX.push(i);
                }
                else if (s[i] == c && countC < 2)
                {
                    countC++;
                    temp1.push(i);
                    stX.push(i);
                }
            }
            else
                break;
        }

        if (countC < 2)
        {
            while (!temp1.empty() && (countC < 2 || countX < 2))
            {

                if (s[temp1.front()] == 'x')
                {
                    stX.push(temp1.front() + n);
                    temp1.pop();
                    countX++;
                }
                else
                {
                    countC++;
                    stX.push(temp1.front() + n);
                    temp1.pop();
                }
            }
        }

        cout << min_wait << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int> angka(n + 1, 0);
        vector<int> pembanding(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> angka[i];
            pembanding[angka[i]] = i;
        }
        bool ambigu = true;
        for (int i = 1; i <= n; i++)
        {
            if (pembanding[i] != angka[i])
            {
                ambigu = false;
            }
        }
        if (ambigu)
        {
            cout << "ambiguous" << endl;
        }
        else
            cout << "not ambiguous" << endl;
    }
}
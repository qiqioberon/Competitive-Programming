#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> sett;
    int tc, n;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        auto it = sett.find(n);
        if (it != sett.end())
        {
            cout << "Yes " << sett.size() << endl;
        }
        else
        {
            sett.insert(n);
            cout << "No " << sett.size() << endl;
        }
    }
}
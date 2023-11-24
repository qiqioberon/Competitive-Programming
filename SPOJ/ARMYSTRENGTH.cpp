#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, strength;
        cin >> a >> b;
        int maks1 = 0, maks2 = 0;
        while (a--)
        {
            cin >> strength;
            if (maks1 < strength)
                maks1 = strength;
        }
        while (b--)
        {
            cin >> strength;
            if (maks2 < strength)
                maks2 = strength;
        }
        // cout << maks1 << " " << maks2 << endl;
        if (maks1 >= maks2)
            cout << "Godzilla" << endl;
        else if (maks2 > maks1)
            cout << "MechaGodzilla" << endl;
    }
}
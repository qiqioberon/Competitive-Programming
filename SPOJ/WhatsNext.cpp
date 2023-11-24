#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        else if (a == b && b == c)
        {
            continue;
        }

        else if (c - b == b - a && (c - b > 0 || c - b < 0))
        {
            cout << "AP " << c + (c - b) << endl;
        }
        else if (b * b == a * c)
        {
            cout << "GP " << c * (c / b) << endl;
        }
        else
            continue;
    }
}
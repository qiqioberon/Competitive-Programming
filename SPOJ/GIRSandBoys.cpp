#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        if (a == 0 && b == 0)
        {
            cout << 0 << endl;
            continue;
        }
        double result = ceil((double)(max(a, b)) / (min(a, b) + 1.0));
        cout << (int)result << endl;
    }
}

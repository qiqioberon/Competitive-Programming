#include <iostream>
#include <cmath>
#include <iomanip>
#define pi acos(-1);
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        double res = 0.5 * (double)(n * n) / pi;
        cout << fixed << setprecision(2) << res << endl;
    }
}
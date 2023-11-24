#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double n;
    while (cin >> n)
    {
        if (n == 0.0)
            break;
        int i = 0;
        double x = 0.0;
        while (x < n)
        {
            i++;
            x += (double)(1.0 / ((double)i + 1.0));
        }
        cout << i << " card(s)" << endl;
    }
}
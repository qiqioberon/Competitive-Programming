#include <iostream>
using namespace std;
int binpow(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        cout << x << " " << y << " " << res << endl;
        if (y & 1)
            (res *= x);
        (x *= x);
        y >>= 1;
    }
    return res;
}

int main()
{
    cout << binpow(2, 5);
}

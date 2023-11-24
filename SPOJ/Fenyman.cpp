#include <iostream>
using namespace std;
int main()
{
    int angka;
    while (cin >> angka)
    {
        if (angka == 0)
            break;
        int i = 1, res = 0;
        while (i <= angka)
        {
            res += i * i;
            i++;
        }
        cout << res << endl;
    }
}

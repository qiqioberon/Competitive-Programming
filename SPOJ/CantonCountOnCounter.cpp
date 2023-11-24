#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int angka;
        cin >> angka;
        int i = 1, j = 1, k = 1;
        while (k < angka)
        {
            j++;
            k++;

            if (k == angka)
                break;
            while (j > 1 && k < angka)
            {
                j--;
                i++;
                k++;
            }

            if (k == angka)
                break;
            i++;
            k++;
            if (k == angka)
                break;
            while (i > 1 && k < angka)
            {
                j++;
                i--;
                k++;
            }
            if (k == angka)
                break;
        }
        cout << "TERM " << angka << " IS " << i << "/" << j << endl;
    }
}
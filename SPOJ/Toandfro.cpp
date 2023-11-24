#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
            return 0;
        }
        string s;
        cin >> s;
        int batasI = 0;
        int panjang = s.length();
        int batasAwal = (n * 2) - 1;
        int batasAkhir = 1;
        int genap = 1;
        int i = 0;
        string a = "";
        while (i < panjang)
        {
            if (i < panjang)
            {
                if (i == batasI)
                    if (s[i] >= 'a' && s[i] <= 'z')
                        a += s[i];
                // cout << s[i];

                i += batasAwal;
                if (s[i] >= 'a' && s[i] <= 'z')
                    a += s[i];
                // cout << s[i];
                i += batasAkhir;
                if (s[i] >= 'a' && s[i] <= 'z')
                    a += s[i];
                // cout << s[i];
            }

            if (i >= panjang)
            {
                // cout << endl;
                batasI++;
                i = batasI;
                batasAwal -= 2;
                batasAkhir += 2;
            }
            if (batasI == n || batasAwal <= 0 || batasAkhir >= n * 2)
            {
                break;
            }
        }
        cout << a;
        cout << endl;
    }
}
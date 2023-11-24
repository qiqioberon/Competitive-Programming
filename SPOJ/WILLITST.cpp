#include <stdio.h>
#include <unordered_map>
#define ll long long
#define gc getchar_unlocked
using namespace std;

// inline char getchar_unlocked()
// {
//     return getchar();
// }
template <typename T>
void getNum(T &val)
{
    char ch;
    bool bo = 0;
    val = 0;
    for (ch = gc(); ch < '0' || '9' < ch; ch = gc())
        if (ch == '-')
            bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - '0', ch = gc())
        ;
    if (bo)
        val = -val;
}

int main()
{
    unordered_map<ll, ll> cek;
    ll n;
    getNum<ll>(n);
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            // cout << "genap " << n << endl;
            if (cek[n] == 0)
                cek[n]++;

            else
                break;
        }
        else
        {
            n = 3 * n + 3;
            // cout << "ganjil " << n << endl;
            if (cek[n] == 0)
                cek[n]++;
            else
                break;
        }
    }
    // cout << cek[12] << endl;
    // cout << "akhir " << n << endl;
    if (n == 1)
    {
        printf("TAK");
    }
    else
        printf("NIE");
}

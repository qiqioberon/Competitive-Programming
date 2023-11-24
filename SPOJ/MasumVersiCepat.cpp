#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

inline char getchar_unlocked()
{
    return getchar();
}

template <typename T>
void getNum(T &val)
{
    char ch;
    bool bo = 0;
    val = 0;
    for (ch = getchar_unlocked(); ch < '0' || '9' < ch; ch = getchar_unlocked())
        if (ch == '-')
            bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - '0', ch = getchar_unlocked())
        ;
    if (bo)
        val = -val;
}

int main()
{
    ll t;
    getNum(t);
    ll angka, terkecil = 1e9;
    ll minus = 0, jumlah = 0;
    while (t--)
    {
        getNum(angka);
        if (angka < 0)
        {
            minus += angka;
            terkecil = min(terkecil, angka);
        }
        else
        {
            terkecil = min(terkecil, angka);
            jumlah += angka;
        }
    }

    if (minus == 0)
    {
        jumlah -= (2 * terkecil);
    }
    else if (jumlah == 0)
    {
        jumlah = (2 * terkecil) - minus;
    }
    else
    {
        jumlah -= minus;
    }
    printf("%lld\n", abs(jumlah));
}

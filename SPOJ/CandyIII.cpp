#include <stdio.h>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

inline char getchar_unlocked()
{
    return getchar();
}

#define gc getchar_unlocked

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
    ll jml, uang, tc;
    getNum<ll>(tc);
    while (tc--)
    {
        ll total = 0;
        getNum<ll>(jml);
        for (ll i = 0; i < jml; i++)
        {
            getNum<ll>(uang);
            total = ((total % jml) + (uang % jml)) % jml;
        }

        if (total % jml != 0)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}
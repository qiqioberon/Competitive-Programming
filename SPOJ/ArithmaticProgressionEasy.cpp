#include <cstdio>
#define ll long long

void getNum(ll &val)
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
    ll tc;
    getNum(tc);
    while (tc--)
    {
        ll x, y, z;
        getNum(x);
        getNum(y);
        getNum(z);
        ll jml = x + y;
        ll totalsuku, awal, beda;
        if (z % jml == 0)
        {
            totalsuku = z * 2 / jml;
        }
        else
        {
            totalsuku = ((ll)(z / jml) * 2) + 1;
        }
        beda = (y - x) / (totalsuku - 5);
        awal = x - (2 * beda);

        printf("%lld\n", totalsuku);
        for (ll i = 1; i <= totalsuku; i++)
        {
            printf("%lld", awal + (i - 1) * beda);
            if (i != totalsuku)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

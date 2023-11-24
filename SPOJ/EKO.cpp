#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define ll long long int
using namespace std;

bool sudahpas = false;
inline char getchar_unlocked()
{
    return getchar();
}

bool canCropTree(vector<ll> &Trees, ll n, ll c, ll minCrop)
{
    ll count = 0;
    for (ll i = 1; i < n; i++)
    {
        if (Trees[i] - minCrop > 0)
        {
            count += Trees[i] - minCrop;
        }
    }
    if (count == c)
        sudahpas = true;
    return count >= c;
}

ll MaxIntegerHeight(vector<ll> &Trees, ll n, ll c)
{
    sort(Trees.begin(), Trees.end());

    ll low = 0;
    ll high = Trees[n - 1];
    ll result = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (canCropTree(Trees, n, c, mid))
        {
            result = mid;
            low = mid + 1;
            if (sudahpas)
                break;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
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
    ll n, c;
    getNum(n);
    getNum(c);

    vector<ll> Trees(n);
    for (ll i = 0; i < n; i++)
    {
        getNum(Trees[i]);
    }

    ll result = MaxIntegerHeight(Trees, n, c);
    printf("%lld", result);

    return 0;
}

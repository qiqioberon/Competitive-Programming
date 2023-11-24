#include <stdio.h>
#define ll long long
#define gc getchar_unlocked

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
bool isPowerOfTwo(ll n)
{
    if (n <= 0)
    {
        return false;
    }
    return (n & (n - 1)) == 0;
}
int main()
{
    ll n;
    getNum<ll>(n);

    if (isPowerOfTwo(n))
    {
        printf("TAK");
    }
    else
        printf("NIE");
}
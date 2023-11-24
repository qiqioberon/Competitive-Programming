#include <stdio.h>
#include <algorithm>
using namespace std;
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
    int tc;
    getNum(tc);
    while (tc--)
    {
        int a, b, strength;
        getNum(a);
        getNum(b);
        int maks1 = 0, maks2 = 0;
        while (a--)
        {
            getNum(strength);
            maks1 = max(maks1, strength);
        }
        while (b--)
        {
            getNum(strength);
            maks2 = max(maks2, strength);
        }

        if (maks1 >= maks2)
            printf("Godzilla\n");
        else if (maks2 > maks1)
            printf("MechaGodzilla\n");
    }
    return 0;
}

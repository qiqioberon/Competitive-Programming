#include <cstdio>
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
    int n;
    getNum(n);
    int jml = 0;
    while (n--)
    {
        int angka;
        getNum(angka);
        jml ^= angka;
    }
    printf("%d\n", jml);
}

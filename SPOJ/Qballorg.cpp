#include <cstdio>
#include <map>
#define ll long long

#define gc getchar_unlocked

template <typename T>
void getNum(T &val)
{
    char ch;
    bool bo = false;
    val = 0;
    for (ch = gc(); ch < '0' || '9' < ch; ch = gc())
        if (ch == '-')
            bo = true;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - '0', ch = gc())
        ;
    if (bo)
        val = -val;
}

int main()
{
    int n, q;
    getNum<int>(n);
    getNum<int>(q);

    int val[n + 1];
    std::map<int, int> pos;

    ll sum = 0;

    for (int i = 1; i <= n; i++)
    {
        getNum<int>(val[i]);
        pos[val[i]]++;
        if (pos[val[i]] >= 2)
            sum += pos[val[i]] - 1;
    }

    while (q--)
    {
        int type;
        getNum<int>(type);

        if (type == 1)
        {
            int i, k;
            getNum<int>(i);
            getNum<int>(k);

            if (pos[val[i]] >= 2)
                sum -= pos[val[i]] - 1;
            pos[val[i]]--;
            val[i] = k;
            pos[val[i]]++;
            if (pos[val[i]] >= 2)
                sum += pos[val[i]] - 1;
        }
        else
        {
            int i;
            getNum<int>(i);
            if (pos[val[i]] >= 2)
                printf("%lld\n", sum - pos[val[i]] + 1);
            else
                printf("%lld\n", sum);
        }
    }

    return 0;
}

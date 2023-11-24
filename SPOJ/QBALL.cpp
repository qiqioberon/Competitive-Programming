#include <cstdio>
#include <map>
#include <vector>

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

    int angka;
    std::vector<int> ball(n + 1);
    std::map<int, int> total;
    long long res = 0, x;

    for (int i = 1; i <= n; i++)
    {
        getNum<int>(angka);
        ball[i] = angka;
        total[ball[i]]++;
    }

    while (q--)
    {
        int query;
        getNum<int>(query);
        if (query == 1)
        {
            int index, angka;
            getNum<int>(index);
            getNum<int>(angka);

            total[ball[index]]--;
            ball[index] = angka;
            total[ball[index]]++;
        }
        else
        {
            int index;
            getNum<int>(index);

            for (const auto &data : total)
            {
                if (data.second >= 2 && data.first > 0)
                {
                    long long x = data.second - 1;
                    res += (x * (x + 1)) / 2;
                }
            }

            if (total[ball[index]] >= 2)
                printf("%lld\n", res - total[ball[index]] + 1);
            else
                printf("%lld\n", res);

            res = 0;
        }
    }

    return 0;
}

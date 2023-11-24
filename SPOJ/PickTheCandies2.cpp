#include <stdio.h>
#include <deque>
#include <algorithm>
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
    int t;
    getNum<int>(t);
    while (t--)
    {
        int jml, k, manis;
        deque<int> dq;
        getNum<int>(jml);
        getNum<int>(k);
        int terbesar = 0;
        int first_index = 0;
        for (int i = 0; i < jml; i++)
        {
            getNum(manis);
            dq.push_back(manis);
            if (i >= k - 1)
            {
                if (i - first_index >= k)
                {
                    first_index++;
                }
                terbesar = *max_element(dq.begin() + first_index, dq.end());
                printf("%d ", terbesar);
            }
        }
        printf("\n");
    }
    return 0;
}

#include <cstdio>
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
        while (jml--)
        {
            getNum(manis);
            if (dq.size() != k)
            {
                dq.push_back(manis);
                if (dq.size() == k)
                {
                    printf("%d ", *max_element(dq.begin(), dq.end()));
                    dq.pop_front();
                }
            }
        }
        printf("\n");
    }
    return 0;
}
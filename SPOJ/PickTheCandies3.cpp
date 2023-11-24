#include <cstdio>
#include <deque>
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
    int t;
    getNum<int>(t);
    while (t--)
    {
        int jml, k, manis;
        deque<int> dq;
        deque<int> max_values;
        getNum<int>(jml);
        getNum<int>(k);
        for (int i = 0; i < jml; i++)
        {
            getNum(manis);
            dq.push_back(manis);
            while (!max_values.empty() && max_values.front() < i - k + 1)
            {
                max_values.pop_front();
            }
            while (!max_values.empty() && dq[max_values.back()] < manis)
            {
                max_values.pop_back();
            }
            max_values.push_back(i);
            if (i >= k - 1)
            {
                printf("%d ", dq[max_values.front()]);
            }
        }
        printf("\n");
    }
    return 0;
}

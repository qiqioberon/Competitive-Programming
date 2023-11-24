#include <cstdio> // Include cstdio for printf
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>
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

bool compareTuples(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    if (get<0>(a) < get<0>(b))
    {
        return true;
    }
    else if (get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b))
    {
        return true;
    }
    else if (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    getNum(n); // Use getNum for input
    vector<tuple<int, int, int>> myTuples;
    map<tuple<int, int, int>, int> index;
    int minA = 1e9, maxA = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        getNum(a); // Use getNum for input
        getNum(b);
        getNum(c);
        minA = min(minA, a);
        maxA = max(maxA, a);
        myTuples.push_back({a, b, c});
        index[{a, b, c}] = i;
    }
    tuple<int, int, int> hardest, easiest;
    sort(myTuples.begin(), myTuples.end(), compareTuples);
    hardest = myTuples[0];
    easiest = myTuples[n - 1];

    if (hardest == easiest)
    {
        printf("Easiest and Hardest is level %d\n", index[easiest]);
    }
    else
    {
        printf("Easiest is level %d\n", index[easiest]);
        printf("Hardest is level %d\n", index[hardest]);
    }

    return 0;
}

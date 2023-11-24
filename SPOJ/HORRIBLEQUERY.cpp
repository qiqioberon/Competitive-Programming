#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> t;
void init(int size)
{
    t.resize(size << 4);
}

ll sum(int pos, int left, int right, int batasKiri, int BatasKanan)
{
    if (batasKiri > BatasKanan)
        return 0;
    if (batasKiri == left && BatasKanan == right)
    {
        return t[pos];
    }
    int middle = (left + right) / 2;
    return sum(pos * 2, left, middle, batasKiri, min(BatasKanan, middle)) + sum(pos * 2 + 1, middle + 1, right, max(batasKiri, middle + 1), BatasKanan);
}

void updateRANGE(int v, int left, int right, int BatasKiri, int BatasKanan, int new_val)
{
    if (left > right || left > BatasKanan || right < BatasKiri)
        return;

    if (left == right)
    {
        t[v] += new_val;
        return;
    }
    else
    {
        int middle = (left + right) / 2;
        updateRANGE(v * 2, left, middle, BatasKiri, BatasKanan, new_val);
        updateRANGE(v * 2 + 1, middle + 1, right, BatasKiri, BatasKanan, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, C;
        cin >> N >> C;
        init(N);
        while (C--)
        {
            int cmd;
            cin >> cmd;
            if (cmd == 0)
            {
                int BatasKiri, BatasKanan, angkaBaru;
                cin >> BatasKiri >> BatasKanan >> angkaBaru;
                updateRANGE(1, 0, N - 1, BatasKiri - 1, BatasKanan - 1, angkaBaru);
            }
            else if (cmd == 1)
            {
                int batasKiri, batasKanan;
                cin >> batasKiri >> batasKanan;
                cout << sum(1, 0, N - 1, batasKiri - 1, batasKanan - 1) << endl;
            }
        }

        t.clear();
    }
}

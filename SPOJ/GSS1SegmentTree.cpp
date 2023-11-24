#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 67;
const int inf = (int)1e9 + 7;
int n, m, a[4 * N];

struct st
{
    int ans, preffix, suffix, sum;
} t[4 * N];

st Merge(st l, st r)
{
    int ans = max({l.ans, r.ans, l.suffix + r.preffix});
    int prefixSum = max(l.preffix, l.sum + r.preffix);
    int suffixSum = max(r.suffix, r.sum + l.suffix);
    int sum = l.sum + r.sum;
    return {ans, prefixSum, suffixSum, sum};
}

void build(int pos, int left, int right)
{
    if (left == right)
    {
        t[pos] = {a[left], a[left], a[left], a[left]};
        return;
    }

    int middle = (left + right) / 2;
    build(pos * 2, left, middle);
    build(pos * 2 + 1, middle + 1, right);
    t[pos] = Merge(t[pos * 2], t[pos * 2 + 1]);
}

st GET(int pos, int left, int right, int batasKiri, int batasKanan)
{
    if (left > batasKanan || right < batasKiri)
        return {-inf, -inf, -inf, 0};
    if (batasKiri <= left && right <= batasKanan)
        return t[pos];
    int middle = (left + right) / 2;
    return Merge(GET(pos * 2, left, middle, batasKiri, batasKanan), GET(pos * 2 + 1, middle + 1, right, batasKiri, batasKanan));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << GET(1, 1, n, x, y).ans << endl;
    }
}
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;

const ll MAXXX = 1e6 + 2;

vector<ll> tree;
vector<ll> lazy;

void updateRangeUtil(ll si, ll ss, ll se, ll us, ll ue, ll diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss > se || ss > ue || se < us)
        return;

    if (ss >= us && se <= ue)
    {
        tree[si] += (se - ss + 1) * diff;
        if (ss != se)
        {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }

    ll mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void updateRange(ll n, ll us, ll ue, ll diff)
{
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss > se || ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
        return tree[si];

    ll mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

ll getSum(ll n, ll qs, ll qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        return -1;
    }

    return getSumUtil(0, n - 1, qs, qe, 0);
}

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll N, C;
        cin >> N >> C;
        tree.assign(N << 4, 0);
        lazy.assign(N << 4, 0);
        while (C--)
        {
            ll cmd;
            cin >> cmd;
            if (cmd == 0)
            {
                ll BatasKiri, BatasKanan, angkaBaru;
                cin >> BatasKiri >> BatasKanan >> angkaBaru;
                updateRange(N, BatasKiri - 1, BatasKanan - 1, angkaBaru);
            }
            else if (cmd == 1)
            {
                ll batasKiri, batasKanan;
                cin >> batasKiri >> batasKanan;
                cout << getSum(N, batasKiri - 1, batasKanan - 1) << endl;
            }
        }
    }

    return 0;
}

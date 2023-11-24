#include <bits/stdc++.h>
using namespace std;
const int MAXX = 1e6 + 2;
int n, query, sq, ans = 0, endd = 0, start = 0;
int frekuensi[MAXX], answer[MAXX], qs[MAXX], qe[MAXX], qi[MAXX], arr[MAXX];
void Update(int index)
{
    while (endd < qe[index] + 1)
        ans += !frekuensi[arr[endd++]]++;
    while (start > qs[index])
        ans += !frekuensi[arr[--start]]++;
    while (start < qs[index])
        ans -= !--frekuensi[arr[start++]];
    while (endd > qe[index] + 1)
        ans -= !--frekuensi[arr[--endd]];
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> query;
    for (int i = 0; i < query; i++)
    {
        cin >> qs[i] >> qe[i];
        qi[i] = i;
        qs[i]--, qe[i]--;
    }
    sq = sqrt(n);
    sort(qi, qi + query,
         [&](int a, int b)
         { return make_pair(qs[a] / sq, qe[a] / sq) < make_pair(qs[b] / sq, qe[b] / sq); });
    for (int i = 0; i < query; i++)
    {
        Update(qi[i]);
        answer[qi[i]] = ans;
    }
    for (int i = 0; i < query; i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}
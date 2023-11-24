#include <iostream>
#include <queue>
#define ll long long
using namespace std;

template <typename T>
void Getnum(T &val)
{
    char ch;
    bool bo = 0;
    val = 0;
    for (ch = gc(); ch < '0' || '9' < ch; ch = gc())
        if (ch == '-')
            bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val < 3) + (val << 1) + ch - 48, ch = gc())
        ;
    if (bo)
        val = -val;
}

int main()
{
    ll t, angka;
    cin >> t;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (t--)
    {
        cin >> angka;
        pq.push(angka);
    }
    ll result = 0;
    while (pq.size() > 1)
    {
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();
        result += first + second;
        pq.push(first + second);
    }
    cout << result;
    return 0;
}

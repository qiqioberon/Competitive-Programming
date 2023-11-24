#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

ll getNumOfInversions(vector<ll> &A)
{
    ll N = A.size();
    if (N <= 1)
    {
        return 0;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> sortList;
    ll result = 0;
    // Heapsort, O(N*log(N))
    for (ll i = 0; i < N; i++)
    {
        sortList.push(make_pair(A[i], i));
    }
    // Create a sorted list of indexes
    vector<ll> x;
    while (!sortList.empty())
    {
        // O(log(N))
        ll v = sortList.top().first;
        ll i = sortList.top().second;
        sortList.pop();
        // Find the current minimum's index
        // the index y can represent how many minimums on the left
        ll y = upper_bound(x.begin(), x.end(), i) - x.begin();
        // i can represent how many elements on the left
        // i - y can find how many bigger nums on the left
        result += i - y;
        x.insert(upper_bound(x.begin(), x.end(), i), i);
    }
    return result;
}

// driver code

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll angka, jml;
        vector<ll> A;
        cin >> jml;
        while (jml--)
        {
            cin >> angka;
            A.push_back(angka);
        }
        ll result = getNumOfInversions(A);

        cout << result << endl;
    }

    // function call

    return 0;
}
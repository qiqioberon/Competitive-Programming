#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool compareTuples(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    // Anda dapat mengganti urutan elemen tuple di bawah ini sesuai dengan kriteria pengurutan yang Anda inginkan.
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
    cin >> n;
    vector<tuple<int, int, int>> myTuples;
    map<tuple<int, int, int>, int> index;
    int minA = 1e9, maxA = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        minA = min(minA, a);
        maxA = max(maxA, a);
        myTuples.push_back({a, b, c});
        index[{a, b, c}] = i;
    }
    tuple<int, int, int> hardest, easiest;
    sort(myTuples.begin(), myTuples.end(), compareTuples);
    hardest = myTuples[0];
    easiest = myTuples[n - 1];
    // for (const auto &tuple : myTuples)
    // {
    //     //cout << get<0>(tuple) << " " << get<1>(tuple) << " " << get<2>(tuple) << endl;
    //     // if (get<0>(tuple) == minA)
    //     // {
    //     //     if (get<1>(tuple) > get<1>(hardest))
    //     //         hardest = tuple;
    //     //     else if (get<1>(tuple) == get<1>(hardest))
    //     //     {
    //     //         if (get<2>(tuple) < get<2>(hardest))
    //     //             hardest = tuple;
    //     //     }
    //     // }
    //     // else if (get<0>(tuple) == maxA)
    //     // {
    //     //     if (get<1>(tuple) < get<1>(hardest))
    //     //         easiest = tuple;
    //     //     else if (get<1>(tuple) == get<1>(hardest))
    //     //     {
    //     //         if (get<2>(tuple) > get<2>(hardest))
    //     //             easiest = tuple;
    //     //     }
    //     // }
    // }

    // cout << get<0>(hardest) << " " << get<1>(hardest) << " " << get<2>(hardest);
    // cout << endl;
    // cout << get<0>(easiest) << " " << get<1>(easiest) << " " << get<2>(easiest);
    if (hardest == easiest)
    {
        cout << "Easiest and Hardest is level " << index[easiest] << endl;
    }
    else
    {
        cout << "Easiest is level " << index[easiest] << endl;
        cout << "Hardest is level " << index[hardest] << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int q = 4;                     // Jumlah query
    vector<int> qi = {0, 1, 2, 3}; // Array qi, indeks akan diurutkan berdasarkan pasangan

    vector<int> qs = {3, 0, 1, 2}; // Contoh array qs
    vector<int> qe = {4, 5, 3, 8}; // Contoh array qe
    int sq = 2;                    // Contoh nilai sq

    sort(qi.begin(), qi.begin() + q, [&](int a, int b)
         { cout<<a<<" "<<b<<endl;
         cout<<qs[a] / sq<<" "<<qe[a] / sq<<" "<<qs[b] / sq << " "<< qe[b] / sq<<endl;
            return make_pair(qs[a] / sq, qe[a] / sq) < make_pair(qs[b] / sq, qe[b] / sq); });

    cout << "Hasil setelah pengurutan:" << endl;
    for (int i = 0; i < q; i++)
    {
        cout << "qi[" << i << "] = " << qi[i] << endl;
    }

    return 0;
}
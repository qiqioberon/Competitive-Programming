#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N, M;
        cin >> N >> M;
        long long K = 0;
        while ((N ^ K) <= M)
        {
            K += 1;
        }
        cout << K << endl;
    }
    return 0;
}

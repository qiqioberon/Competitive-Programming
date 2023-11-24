#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long N, M;
        cin >> N >> M;

        // Temukan berapa banyak bit yang dibutuhkan untuk N
        int bits = log2(N) + 1;

        long long K = 0;

        // Geser bit 1 dari K untuk mencoba setiap bit
        for (int i = bits - 1; i >= 0; i--)
        {
            long long mask = 1LL << i;
            if ((N & mask) == 0)
            {
                // Jika bit di posisi i adalah 0, set bit tersebut di K
                K |= mask;
                if ((K ^ N) > M)
                {
                    // Jika K^N lebih besar dari M, maka bit i harus tetap 0
                    K ^= mask;
                }
            }
            else
            {
                // Jika bit di posisi i adalah 1, pastikan K^N lebih besar dari M
                if ((K ^ N) <= M)
                {
                    K |= mask;
                }
            }
        }

        cout << K << endl;
    }

    return 0;
}

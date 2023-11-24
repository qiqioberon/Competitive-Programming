#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, N, Q, a, b;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        cin >> N >> Q;
        vector<int> arr(N, 0);

        for (int i = 0; i < Q; i++)
        {
            cin >> a >> b;

            if (a - (2 * b) >= 0 && a - (2 * b) <= N)
                arr[a - (2 * b) - 1]++;
            if (a - b >= 0 && a - b <= N)
                arr[a - b - 1]++;
            if (a >= 0 && a <= N)
                arr[a - 1]++;
            if (a + b <= N && a + b >= 0)
                arr[a + b - 1]++;
            if (a + (2 * b) <= N && a + (2 * b) >= 0)
                arr[a + (2 * b) - 1]++;
        }

        cout << "Case " << case_num << ": ";
        for (int j = 1; j <= N; j++)
        {
            cout << arr[j - 1];
            if (j != N)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}

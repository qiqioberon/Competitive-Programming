#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N, Q;
        cin >> N >> Q;
        vector<int> arr(N + 1, 0);

        for (int i = 0; i < Q; i++)
        {
            int a, b;
            cin >> a >> b;

            for (int j = a - 2 * b; j <= N; j += b)
            {
                if (j >= 1 && j <= N)
                {
                    arr[j]++;
                }
            }
        }

        cout << "Case " << case_num << ": ";
        for (int j = 1; j <= N; j++)
        {
            cout << arr[j];
            if (j != N)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}

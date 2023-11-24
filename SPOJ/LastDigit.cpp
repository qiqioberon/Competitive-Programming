#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> Index = {{0}, {1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6}, {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}}; int tc; cin >> tc;while (tc--){ int a, b; cin >> a >> b; if (a == 0)  cout << 0 << endl;  else if (b == 0)
            cout << 1 << endl;
        else
        {
            int lastDigitA = a % 10;
            int sisa = b % Index[lastDigitA].size();
            if (sisa == 0)
                sisa = Index[lastDigitA].size() - 1;
            else
                sisa -= 1;
            cout << Index[lastDigitA][sisa] << endl;
        }
    }
    return 0;
}

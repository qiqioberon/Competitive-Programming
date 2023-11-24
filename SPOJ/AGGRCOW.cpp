#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(vector<int> &stalls, int n, int c, int minDist)
{
    int count = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPosition >= minDist)
        {
            count++;
            lastPosition = stalls[i];
        }
    }

    return count >= c;
}

int largestMinimumDistance(vector<int> &stalls, int n, int c)
{
    sort(stalls.begin(), stalls.end());

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, c, mid))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }

        int result = largestMinimumDistance(stalls, n, c);
        cout << result << endl;
    }

    return 0;
}

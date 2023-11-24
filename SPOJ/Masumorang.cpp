#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n, sum1 = 0, sum2 = 0;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
        {
            sum1 += arr[i];
        }
        else
        {
            sum2 += arr[i];
        }
    }
    sort(arr, arr + n);
    if (sum2 == 0)
    {
        sum1 -= arr[0] * 2;
        cout << sum1 << endl;
    }
    else if (sum1 == 0)
    {
        sum2 += -arr[0] * 2;
        cout << abs(sum2) << endl;
    }
    else
    {
        long long sum = sum1 - sum2;
        cout << abs(sum) << endl;
    }
    return 0;
}
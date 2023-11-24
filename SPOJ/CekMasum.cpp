#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(const vector<int> &array)
{
    int maxSum = 0; // Menggunakan INT_MIN sebagai nilai awal minimum
    const int n = array.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j + 1; k++)
            { // Perubahan di sini dari "< j + 1" menjadi "<= j"
                sum += array[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int main()
{
    vector<int> array;
    int t;
    cin >> t;
    while (t--)
    {
        int angka;
        cin >> angka;
        array.push_back(angka);
    }
    int result = maxSubArray(array);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}

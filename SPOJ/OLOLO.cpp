#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> arr;
    int jml = 0;
    while (n--)
    {
        int angka;
        cin >> angka;
        if (arr[angka] == 0)
        {
            arr[angka]++;
            jml += angka;
        }
        else
        {
            jml -= angka;
        }
    }
    cout << jml << endl;
}
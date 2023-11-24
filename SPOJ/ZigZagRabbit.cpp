#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ll baris, langkah;
    cin >> baris >> langkah;
    vector<vector<ll>> matrix(baris + 2, vector<ll>(baris + 2, 0));
    string input;
    cin >> input;
    ll i = 1, j = 1, k = 1;
    bool mentokbawah = false;

    while (k <= baris * baris)
    {
        if (i == 1)
        {
            matrix[i][j] = k;

            // cout << matrix[i][j] << endl;
            // Geser Kanan 1 buah
            j++;
            k++;
        }
        if (j == baris + 1)
        {
            i += 1;
            j -= 1;
        }

        // Geser Diagonal Kiri Bawah mentok
        while (j > 1)
        {
            matrix[i][j] = k;

            j--;
            i++;
            k++;
            if (i == baris + 1)
            {
                i -= 1;
                j += 2;
                mentokbawah = true;
                break;
            }
        }

        // Geser bawah 1 buah
        matrix[i][j] = k;
        if (!mentokbawah)
        {
            i++;
            k++;
            if (i == baris + 1)
            {
                i -= 1;
                j += 1;
            }
        }
        // if (k == 32)
        //     cout << i << j << endl;
        // Geser diagonal kanan atas mentok
        while (i > 1)
        {

            matrix[i][j] = k;
            j++;
            i--;
            k++;
            if (j == baris + 1)
            {
                i += 2;
                j -= 1;
                matrix[i][j] = k;
                break;
            }
            if (i != 1)
                matrix[i][j] = k;
        }
    }

    // for (ll i = 1; i <= 10; i++)
    // {
    //     for (ll j = 1; j <= 10; j++)
    //     {
    //         cout << matrix[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    ll res = 0;
    i = 1;
    j = 1;
    res = matrix[1][1];
    for (char a : input)
    {
        if (a == 'D')
        {
            i += 1;
            res += matrix[i][j];
        }
        else if (a == 'R')
        {
            j += 1;
            res += matrix[i][j];
        }
        else if (a == 'U')
        {
            i -= 1;
            res += matrix[i][j];
        }
        else if (a == 'L')
        {
            j -= 1;
            res += matrix[i][j];
        }
    }
    cout << res;
}
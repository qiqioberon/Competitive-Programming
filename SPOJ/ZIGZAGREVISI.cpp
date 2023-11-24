#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;
int main()
{
    ll baris, langkah;
    cin >> baris >> langkah;
    vector<pair<ll, ll>> Gerakan;
    ll x = 1, y = 1;
    ll JmlBaris = 0, JmlKolom = 0;
    for (ll i = 0; i < langkah; i++)
    {
        char a;
        cin >> a;
        if (a == 'D')
        {
            x += 1;
            JmlBaris++;
            Gerakan.push_back({x, y});
        }
        else if (a == 'R')
        {
            y += 1;
            JmlKolom++;
            Gerakan.push_back({x, y});
        }
        else if (a == 'U')
        {
            x -= 1;
            JmlBaris--;
            Gerakan.push_back({x, y});
        }
        else if (a == 'L')
        {
            y -= 1;
            JmlKolom--;
            Gerakan.push_back({x, y});
        }
    }
    baris = max(JmlBaris + 1, JmlKolom + 1);
    vector<vector<ll>> matrix(baris + 2, vector<ll>(baris + 2, 0));
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

    ll res = 1;
    for (auto data : Gerakan)
    {
        // cout << matrix[data.first][data.second] << endl;
        res += matrix[data.first][data.second];
    }

    // for (ll i = 1; i <= 10; i++)
    // {
    //     for (ll j = 1; j <= 10; j++)
    //     {
    //         cout << matrix[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    cout << res;
}
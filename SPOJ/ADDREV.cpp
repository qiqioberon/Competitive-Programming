#include <iostream>
#include <string>
using namespace std;

string Invers(string s)
{
    int j = s.length() - 1;
    for (int i = 0; i <= j; i++)
    {
        if (i != j)
        {
            int awal = s[i], akhir = s[j];
            s[i] = akhir;
            s[j] = awal;
            // cout << s << endl;
        }
        else
        {
            s[i] = s[j];
            break;
        }
        j--;
    }
    return s;
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string angka1, angka2;
        cin >> angka1 >> angka2;
        angka1 = Invers(angka1);
        angka2 = Invers(angka2);
        int jumlah = stoi(angka1) + stoi(angka2);
        string result = to_string(jumlah);
        cout << (int)stoi(Invers(result)) << endl;
    }
}
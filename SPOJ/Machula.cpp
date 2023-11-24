#include <iostream>
#include <string>
using namespace std;

bool containsLetter(const string &input)
{
    for (char c : input)
    {
        if (isalpha(c))
        {
            return true; // Ada huruf dalam string
        }
    }
    return false; // Tidak ada huruf dalam string
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        string a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        bool aContainsLetter = containsLetter(a);
        bool cContainsLetter = containsLetter(c);
        bool eContainsLetter = containsLetter(e);

        int angka1, angka2, hasil;
        if (aContainsLetter)
        {
            angka2 = stoi(c);
            hasil = stoi(e);
            angka1 = hasil - angka2;
        }
        else if (cContainsLetter)
        {
            angka1 = stoi(a);
            hasil = stoi(e);
            angka2 = hasil - angka1;
        }
        else if (eContainsLetter)
        {
            angka1 = stoi(a);
            angka2 = stoi(c);
            hasil = angka1 + angka2;
        }
        cout << angka1 << " + " << angka2 << " = " << hasil << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string needle, haystack;
    while (cin >> n >> needle >> haystack)
    {
        int ketemu = 0;
        const int panjang = needle.length();
        size_t found = haystack.find(needle);
        while (found != string::npos)
        {
            cout << found << endl;
            found = haystack.find(needle, found + 1);
            ketemu = 1;
        }
        if (ketemu == 1)
            continue;
        else
            cout << endl;
    }
}
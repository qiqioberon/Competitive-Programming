#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sum(string Jumlah, string Lebih)
{
    int carry = 0;
    string result = "";
    int i = Jumlah.length() - 1;
    int j = Lebih.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int x = (i >= 0) ? Jumlah[i] - '0' : 0;
        int y = (j >= 0) ? Lebih[j] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
        if (i >= 0)
            i--;
        if (j >= 0)
            j--;
    }
    return result;
}

string BagiDua(string number)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < 2)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx)
    {
        ans += (temp / 2) + '0';
        temp = (temp % 2) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}

string Pengurangan(string Jumlah, string Klaudia)
{
    int carry = 0;
    string result = "";
    int i = Jumlah.length() - 1;
    int j = Klaudia.length() - 1;
    bool subtract = false;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int x = (i >= 0) ? Jumlah[i] - '0' : 0;
        int y = (j >= 0) ? Klaudia[j] - '0' : 0;
        int diff = x - y - carry;

        // Periksa apakah digit nol di depan angka pada Jumlah

        if (diff < 0)
        {
            diff += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        // Tambahkan digit hasil pengurangan ke hasil jika bukan digit pertama atau jika digit pertama bukan nol
        if (subtract || diff != 0)
        {
            result = char(diff + '0') + result;
            // cout << "wenak" << endl;
        }
        else
            result += "0";

        // cout << result << endl;
        if (i >= 0)
            i--;
        if (j >= 0)
            j--;
        subtract = true;
    }
    if (!subtract)
    {
        result = "0";
    }
    int startIndex = 0;
    while (startIndex < result.length() && result[startIndex] == '0')
    {
        startIndex++;
    }
    result = (startIndex < result.length()) ? result.substr(startIndex) : "0";
    return result;
}

int main()
{
    string Jumlah, Lebih;
    for (int i = 0; i < 10; i++)
    {
        cin >> Jumlah >> Lebih;
        string total = sum(Jumlah, Lebih);
        string klaudia = BagiDua(total);
        string Natalie = Pengurangan(Jumlah, klaudia);
        cout << klaudia << endl;
        cout << Natalie << endl;
        //  Punya klaudia  = jumlah + lebih/2
        //  mengorbankan lebih
        //  Punya Natalie = Jumlah - Klaudia
    }
}
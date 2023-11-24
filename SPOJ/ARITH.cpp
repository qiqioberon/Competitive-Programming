#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string add(string num1, string num2, char op)
{
    int carry = 0;
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    if (op == '+')
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
            if (i >= 0)
                i--;
            if (j >= 0)
                j--;
        }

    else if (op == '-')
    {
        bool subtract = false;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int diff = x - y - carry;

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
            if (!subtract || diff != 0)
            {
                result = char(diff + '0') + result;
            }

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
    }

    else
    {
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
            if (i >= 0)
                i--;
            if (j >= 0)
                j--;
        }
    }

    return result;
}

vector<string> ElemenPerkalian;
string multiply(string num1, int digit)
{
    int carry = 0;
    string result = "";

    for (int i = num1.length() - 1; i >= 0; i--)
    {
        int x = num1[i] - '0';
        int product = x * digit + carry;
        carry = product / 10;
        if (digit == 0)
        {
            result = "0";
            break;
        }
        else
            result = char(product % 10 + '0') + result;
    }

    if (carry > 0)
    {
        result = char(carry + '0') + result;
    }
    // cout << result << endl;
    ElemenPerkalian.push_back(result);
    return result;
}

// Function to format and print the result
void printResult(string num1, char op, string num2, string result)
{
    int max_len = max(num1.length(), max(num2.length() + 1, result.length()));
    // cout << result.length() << endl;
    int pad1 = max_len - num1.length();
    int pad2 = max_len - num2.length() - 1;
    int pad3 = max_len - result.length();

    cout << string(pad1, ' ') << num1 << endl;
    cout << string(pad2, ' ') << op << num2 << endl;
    if (!ElemenPerkalian.empty() && ElemenPerkalian.size() > 1)
    {
        cout << string(max_len - max(num2.length() + 1, num1.length()), ' ');
        cout << string(max(num2.length() + 1, num1.length()), '-') << endl;
        int i = 0, pad5;
        for (string data : ElemenPerkalian)
        {

            pad5 = max_len - i - data.length();
            cout << string(pad5, ' ') << data;
            cout << string(i, ' ') << endl;

            i++;
        }
    }
    if (op == '*')
        cout << string(pad3, ' ') << string(result.length(), '-') << endl;
    else
        cout << string(max_len, '-') << endl;
    cout << string(pad3, ' ') << result << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        ElemenPerkalian.clear();
        int num1, num2;
        string result, input;
        char op;
        cin >> num1 >> op >> num2;

        if (op == '+')
        {
            result = add(to_string(num1), to_string(num2), op);
        }
        else if (op == '-')
        {

            result = add(to_string(num1), to_string(num2), op);
        }
        else if (op == '*')
        {
            vector<string> partial_results;
            string number2 = to_string(num2);
            for (int i = number2.length() - 1; i >= 0; i--)
            {
                int digit = number2[i] - '0';
                string partial_result = multiply(to_string(num1), digit);
                int shift = number2.length() - 1 - i;
                partial_result += string(shift, '0'); // Geser hasil perkalian sesuai dengan posisi digit
                partial_results.push_back(partial_result);
            }

            result = "0";

            for (int i = 0; i < partial_results.size(); i++)
            {
                result = add(result, partial_results[i], op);
            }
        }

        printResult(to_string(num1), op, to_string(num2), result);
        if (T > 0)
        {
            cout << endl;
        }
    }

    return 0;
}

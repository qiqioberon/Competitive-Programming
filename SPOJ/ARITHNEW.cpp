#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> outputt;
string add(string num1, string num2, char op)
{
    int carry = 0;
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    if (op == '+')
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
    else if (op == '-')
    {
        bool subtract = false;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int diff = x - y - carry;

            // Periksa apakah digit nol di depan angka pada num1

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

    ElemenPerkalian.push_back(result);
    return result;
}

void printResult(string num1, char op, string num2, string result, vector<string> &outputt, int t)
{

    int max_len = max(num1.length(), max(num2.length() + 1, result.length()));
    int pad1 = max_len - num1.length();
    int pad2 = max_len - num2.length() - 1;
    int pad3 = max_len - result.length();

    outputt.push_back(string(pad1, ' ') + num1);
    outputt.push_back(string(pad2, ' ') + op + num2);
    int maxx, maxx2;

    if (!ElemenPerkalian.empty() && ElemenPerkalian.size() > 1)
    {

        maxx2 = ElemenPerkalian[0].length();
        maxx = max(maxx2, (int)num2.length() + 1);
        maxx2 = maxx;
        outputt.push_back(string(max_len - maxx2, ' ') + string(maxx2, '-'));
        int i = 0, pad5;

        for (string data : ElemenPerkalian)
        {
            int datalen = data.length();
            pad5 = max_len - i - datalen;
            if (pad5 < 0)
                pad5 = 0;
            outputt.push_back(string(pad5, ' ') + data);
            i++;
        }
    }

    if (op == '*')
    {
        outputt.push_back(string(pad3, ' ') + string(result.length(), '-'));
    }
    else
    {
        outputt.push_back(string(max_len - max(num2.length() + 1, result.length()), ' ') + string(max(num2.length() + 1, result.length()), '-'));
    }

    outputt.push_back(string(pad3, ' ') + result);
    outputt.push_back("");
}

int main()
{
    ifstream input_file("inputArith.txt");
    if (!input_file)
    {
        cerr << "Gagal membuka file input" << endl;
        return 1;
    }

    ifstream expected_output_file("outputArith.txt");
    if (!expected_output_file)
    {
        cerr << "Gagal membuka file output yang diharapkan" << endl;
        return 1;
    }

    string line;
    while (getline(input_file, line))
    {

        int T = stoi(line);
        for (int t = 0; t < T; t++)
        {
            ElemenPerkalian.clear();

            string num1, num2;
            string result;
            char op;
            string input;
            getline(input_file, input);

            bool isOperatorFound = false;

            for (char c : input)
            {
                if (isdigit(c))
                {
                    if (!isOperatorFound)
                    {
                        num1 += c;
                    }
                    else
                    {
                        num2 += c;
                    }
                }
                else
                {
                    op = c;
                    isOperatorFound = true;
                }
            }

            if (op == '+')
            {
                result = add(num1, num2, op);
            }
            else if (op == '-')
            {
                result = add(num1, num2, op);
            }
            else if (op == '*')
            {
                vector<string> partial_results;
                string number2 = num2;

                for (int i = number2.length() - 1; i >= 0; i--)
                {
                    int digit = number2[i] - '0';
                    string partial_result = multiply(num1, digit);
                    int shift = number2.length() - 1 - i;
                    partial_result += string(shift, '0');
                    partial_results.push_back(partial_result);
                }

                result = "0";

                for (int i = 0; i < partial_results.size(); i++)
                {
                    result = add(result, partial_results[i], '+');
                }
            }

            // cout << num1 << " " << op << " " << num2 << " " << result << endl;
            printResult(num1, op, num2, result, outputt, t);
        }
        break;
    }

    vector<string> expected_outputs;

    string baris;

    while (getline(expected_output_file, baris))
    {
        expected_outputs.push_back(baris);
    }
    // cout << outputt[9] << "j" << expected_outputs[9] << endl;

    for (int j = 0; j < expected_outputs.size(); j++)
    {

        if (j < outputt.size())
        {
            if (expected_outputs[j] != outputt[j])
            {
                cout << " Salah pada baris " << j + 1 << endl;
                cout << "EXPECTED OUTPUT= " << expected_outputs[j] << endl;
                cout << "Program OUTPUT = " << outputt[j] << endl;
                continue;
            }
            else
            {
                if (j % 100 == 0)
                    cout << "Slide sampai " << j << " Masih Aman Lurr" << endl;
                continue;
            }
        }
        else
        {
            break;
        }
    }

    input_file.close();
    expected_output_file.close();

    return 0;
}

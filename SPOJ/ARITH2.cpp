#include <iostream>
#include <string>
using namespace std;

template <typename Int>
inline Int read()
{
    Int flag = 1;
    char c = getchar();
    while ((!isdigit(c)) && c != '-')
    {
        c = getchar();
    }
    if (c == '-')
    {
        flag = -1;
        c = getchar();
    }
    Int init = c & 15;
    while (isdigit(c = getchar()))
    {
        init = (init << 3) + (init << 1) + (c & 15);
    }
    return init * flag;
}

template <typename Int>
inline void write(Int x)
{
    if (x < 0)
    {
        putchar('-');
        x = ~x + 1;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar((x % 10) | 48);
}

template <typename Int>
inline void write(Int x, char nextch)
{
    write(x);
    putchar(nextch);
}

namespace SP6
{
    void plus(string a, string b);
    void minus(string a, string b);
    void times(string a, string b);
}

void getLen(string *strList, int n, int &len)
{
    len = 0;
    for (int i = 0; i < n; i++)
    {
        len = max(len, (int)strList[i].length());
    }
}

void outputString_With_Prefix(string toOutput, char prefixChar, int spaceCount)
{
    while (spaceCount--)
    {
        putchar(prefixChar);
    }
    cout << toOutput << endl;
}

string getSimpleChar(char toOutputChar, int charCount)
{
    string ret;
    while (charCount--)
    {
        ret += toOutputChar;
    }
    return ret;
}

string add_StringString(string a, string b)
{
    string ans;
    bool upDigit = false;
    int tmp;
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--)
    {
        tmp = 0;
        if (i >= 0)
        {
            tmp += a[i] & 15;
        }
        if (j >= 0)
        {
            tmp += b[j] & 15;
        }
        if (upDigit)
        {
            tmp++;
        }
        upDigit = tmp >= 10;
        ans = (char)((tmp % 10) | 48) + ans;
    }
    if (upDigit)
    {
        ans = '1' + ans;
    }
    return ans;
}

string mul_StringDigit(string a, int b)
{
    string ans;
    int upDigit = 0;
    int tmp;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        tmp = (a[i] & 15) * b + upDigit;
        upDigit = tmp / 10;
        ans = (char)((tmp % 10) | 48) + ans;
    }
    if (upDigit)
    {
        ans = (char)(upDigit | 48) + ans;
    }
    return ans;
}

void SP6::plus(string a, string b)
{
    string ans[3];
    ans[0] = a;
    ans[1] = '+' + b;
    ans[2] = add_StringString(a, b);
    int len;
    getLen(ans, 3, len);
    for (int i = 0; i <= 1; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len - ans[i].length());
    }
    cout << getSimpleChar(' ', len - max(ans[1].length(), ans[2].length())) << getSimpleChar('-', max(ans[1].length(), ans[2].length())) << endl;
    for (int i = 2; i <= 2; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len - ans[i].length());
        cout << endl;
    }
}

void SP6::minus(string a, string b)
{
    string ans[3];
    ans[0] = a;
    ans[1] = '-' + b;
    bool borrowDigit = false;
    int tmp;
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--)
    {
        tmp = 0;
        if (i >= 0)
        {
            tmp += a[i] & 15;
        }
        if (j >= 0)
        {
            tmp -= b[j] & 15;
        }
        if (borrowDigit)
        {
            tmp--;
        }
        borrowDigit = tmp < 0;
        ans[2] = (char)((tmp < 0 ? tmp + 10 : tmp) | 48) + ans[2];
    }
    while (ans[2][0] == '0' && ans[2].length() > 1)
    {
        ans[2] = ans[2].substr(1, ans[2].length() - 1);
    }
    int len;
    getLen(ans, 3, len);
    for (int i = 0; i <= 1; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len - ans[i].length());
    }
    cout << getSimpleChar(' ', len - max(ans[1].length(), ans[2].length())) << getSimpleChar('-', max(ans[1].length(), ans[2].length())) << endl;
    for (int i = 2; i <= 2; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len - ans[i].length());
    }
    cout << endl;
}

void SP6::times(string a, string b)
{
    string ans[505];
    ans[0] = a;
    ans[1] = '*' + b;
    ans[b.length() + 2] = '0';
    for (size_t i = 0; i < b.length(); i++)
    {
        if ((b[b.length() - i - 1] & 15) == 0)
        {
            ans[i + 2] = '0' + getSimpleChar(' ', i);
        }
        else
        {
            ans[i + 2] = mul_StringDigit(a, b[b.length() - i - 1] & 15);
            ans[b.length() + 2] = add_StringString(ans[b.length() + 2], ans[i + 2] + getSimpleChar('0', i));
            ans[i + 2] += getSimpleChar(' ', i);
        }
    }
    int len1, len2;
    getLen(ans, 3, len1);
    getLen(ans, b.length() + 3, len2);
    for (int i = 0; i <= 1; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len2 - ans[i].length());
    }
    cout << getSimpleChar(' ', len2 - max(ans[1].length(), ans[2].length())) << getSimpleChar('-', max(ans[1].length(), ans[2].length())) << endl;
    for (size_t i = 2; i <= b.length() + 1; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len2 - ans[i].length());
    }
    if (b.length() == 1)
    {
        cout << endl;
        return;
    }
    cout << getSimpleChar(' ', len2 - ans[b.length() + 2].length()) << getSimpleChar('-', ans[b.length() + 2].length()) << endl;
    for (size_t i = b.length() + 2; i <= b.length() + 2; i++)
    {
        outputString_With_Prefix(ans[i], ' ', len2 - ans[i].length());
    }
    cout << endl;
}

void solve()
{
    string expression;
    cin >> expression;
    string num[2];
    int pos = 0;
    char op;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (!isdigit(expression[i]))
        {
            pos++;
            op = expression[i];
        }
        else
        {
            num[pos] += expression[i];
        }
    }
    switch (op)
    {
    case '+':
        SP6::plus(num[0], num[1]);
        break;
    case '-':
        SP6::minus(num[0], num[1]);
        break;
    case '*':
        SP6::times(num[0], num[1]);
        break;
        // default: printf("error input!\n\n");
    }
}

int main()
{
    int casesCount = read<int>();
    while (casesCount--)
    {
        solve();
    }
    return 0;
}

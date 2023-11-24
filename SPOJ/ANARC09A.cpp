#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string input;
    int tc = 0;
    while (cin >> input)
    {
        tc++;
        stack<char> st;
        if (input[0] == '-')
            break;
        for (char a : input)
        {
            if (st.empty())
            {
                st.push(a);
            }
            else
            {
                if (a == '{')
                {
                    st.push(a);
                }
                else if (a == '}')
                {
                    if (st.top() == '}')
                    {
                        st.push(a);
                    }
                    else if (st.top() == '{')
                    {
                        st.pop();
                    }
                }
            }
        }
        int countbuka = 0, counttutup = 0;
        while (!st.empty())
        {
            if (st.top() == '{')
            {
                // cout << st.top() << " ";
                countbuka++;
                st.pop();
            }
            else
            {
                // cout << st.top() << " ";
                counttutup++;
                st.pop();
            }
        }

        if (countbuka == counttutup)
            cout << tc << ". " << countbuka << endl;
        else if (countbuka == 0)
        {
            cout << tc << ". " << counttutup / 2 << endl;
        }
        else if (counttutup == 0)
        {
            cout << tc << ". " << countbuka / 2 << endl;
        }
    }
}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        stack<int> st;
        vector<int> vec;
        int angka;
        for (int i = 0; i < n; i++)
        {
            cin >> angka;
            vec.push_back(angka);
        }
        int start = 0;
        bool ketemu = false, salah1 = false, salah2;
        for (int i = 0; i < vec.size(); i++)
        {
            // cout << vec[i] << " " << vec[i + 1] << endl;
            if (vec[i + 1] < vec[i] && i != vec.size() - 1)
            {
                st.push(vec[i]);
            }
            else if (!ketemu)
            {
                start = vec[i];
                ketemu = true;
                while (!st.empty())
                {
                    int a = st.top();
                    // cout << a << " ";
                    if (a == start + 1)
                    {
                        start = a;
                        st.pop();
                    }
                    else
                        break;
                }
            }
            else if (ketemu && vec[i] - 1 == start)
            {
                start = vec[i];
                while (!st.empty())
                {
                    int a = st.top();
                    // cout << a << " ";
                    if (a == start + 1)
                    {
                        start = a;
                        st.pop();
                    }
                    else
                        break;
                }
            }
        }
        // cout << start << endl;

        if (!st.empty())
        {
            cout << "no" << endl;
        }
        else
            cout << "yes" << endl;
    }
}
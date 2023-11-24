#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int q;
    vector<int> arr;
    scanf("%d", &q);
    while (q--)
    {
        int angka;
        scanf("%d", &angka);
        arr.push_back(angka);
    }
    int n = arr.size();
    stack<int> st;
    int Result = 0;
    for (int i = 0; i < n; i++)
    {
        while ((!st.empty()) && (arr[st.top()] < arr[i]))
        {
            int areaTengah = arr[st.top()];
            printf("%d %d %d", areaTengah, st.top(), i);
            puts("");
            st.pop();
            if (st.empty())
                break;
            int Jarak = i - st.top() - 1;
            // st.top sebagai batas kiri, dan arr[i] sebagai batas kanan
            int Volume = min(arr[st.top()], arr[i]) - areaTengah;
            Result += Jarak * Volume;
        }
        st.push(i);
    }
    printf("%d", Result);
}

#include <iostream>
using namespace std;
int main()
{
    int N = 1, M = 1;
    if (!N && M)
        cout << 1;
    else if (N && !M)
        cout << 0;
    else
        cout << 5;
}
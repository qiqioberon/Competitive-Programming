#include <cstdio>
#include <vector>
#include <stack>
#define gc getchar_unlocked
using namespace std;

void Get(int &ret)
{
    ret = 0;
    char inp = gc();
    int kl = 1;
    while (inp < '0' || inp > '9')
    {
        if (inp == '-')
            kl = -1;
        inp = gc();
    }
    while ('0' <= inp && inp <= '9')
        ret = (ret << 3) + (ret << 1) + (int)(inp - '0'),
        inp = gc();
    if (kl < 1)
        ret = -ret;
}

int main()
{
    int n;
    Get(n);

    vector<int> input(n);
    vector<int> result(n, 0);
    stack<int> index;

    for (int i = 0; i < n; i++)
    {
        Get(input[i]);
        while (!index.empty() && input[i] > input[index.top()])
        {
            result[index.top()] = input[i];
            index.pop();
        }
        index.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", result[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

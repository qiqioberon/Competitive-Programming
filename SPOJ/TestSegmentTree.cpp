#include <iostream>
#include <vector>
using namespace std;

vector<int> t;
void init(int size)
{
    t.resize(4 * size);
}

void build(int a[], int pos, int left, int right)
{
    if (left == right)
    {
        t[pos] = a[left];
    }
    else
    {
        int middle = (left + right) / 2;
        build(a, pos * 2, left, middle);
        build(a, pos * 2 + 1, middle + 1, right);
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
}

int sum(int pos, int left, int right, int batasKiri, int BatasKanan)
{
    if (batasKiri > BatasKanan)
        return 0;
    if (batasKiri == left && BatasKanan == right)
    {
        return t[pos];
    }
    int middle = (left + right) / 2;
    return sum(pos * 2, left, middle, batasKiri, min(BatasKanan, middle)) + sum(pos * 2 + 1, middle + 1, right, max(batasKiri, middle + 1), BatasKanan);
}

void update(int v, int left, int right, int pos, int new_val)
{
    if (left == right)
    {
        t[v] = new_val;
    }
    else
    {
        int middle = (left + right) / 2;
        if (pos <= middle)
            update(v * 2, left, middle, pos, new_val);
        else
            update(v * 2 + 1, middle + 1, right, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    build(a, 1, 0, 5);
    cout << sum(1, 0, 5, 0, 5) << endl;
}

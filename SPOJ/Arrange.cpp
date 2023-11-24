#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

long long fastPowIterative(long long base, long long exponent, long long modulo)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent /= 2;
    }
    return result;
}

long long findModularInverse(long long n, long long modulo)
{
    return fastPowIterative(n, modulo - 2, modulo);
}

vector<ll> factorial(1000009);

int main(int argc, char const *argv[])
{

    factorial[0] = 1;
    for (ll i = 1; i < 1000009; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    int t;
    scanf("%d", &t);

    ll m, n;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &m, &n);

        ll man = m - n;

        if (man + 1 < n)
        {
            printf("0\n");
            continue;
        }

        ll first = factorial[man];

        ll y2 = findModularInverse(factorial[man + 1 - n], MOD);
        y2 = (factorial[man + 1] * y2) % MOD;

        printf("%lld\n", (first * y2) % MOD);
    }
}

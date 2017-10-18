#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

long long multiply(LL a, LL b, LL MOD)
{
    if(a == 0 || b == 0)
        return 0;

    if(a < LONG_MAX/b)
        return (a*b)%MOD;

    LL product = 0;
    while(b)
    {
        if(b%2 == 1)
            product = (product + a)%MOD;

        a = (a + a)%MOD;
        b = b >> 1;
    }
    return product;
}

LL power_mod(int x, int power,LL MOD)
{
    LL result = 1, y = x;

    while(power)
    {
        if(power%2 == 1)
           result = multiply(result, y, MOD);

        y = multiply(y, y, MOD);
        power = power >> 1;
    }

    return result;
}

int main()
{
    int n;
    printf("Enter the value of n.\n");
    scanf("%d", &n);

    const LL MOD = 1e10;
    LL answer = 0;
    for(int i = 1; i <= n; i++)
    {
        answer = (answer + power_mod(i, i, MOD));
    }

    answer %= MOD;
    printf("Answer = %lld\n", answer);
    return 0;
}

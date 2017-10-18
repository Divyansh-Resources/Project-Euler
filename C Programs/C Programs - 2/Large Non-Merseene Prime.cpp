#include <cstdio>
#include <climits>

typedef long long LL;

LL multiply(LL a, LL b, LL MOD)
{
    if(a < LONG_MAX/b)
        return a*b;

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

LL power_mod(int x, int power, LL MOD)
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
    const LL MOD = 1e10;
    LL answer = 28433*power_mod(2, 7830457, MOD) + 1;
    answer %= MOD;

    printf("The last ten digits of this prime number is %I64d\n", answer);
    return 0;
}

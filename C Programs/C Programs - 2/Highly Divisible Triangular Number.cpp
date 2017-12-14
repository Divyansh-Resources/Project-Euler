#include <cstdio>

int divisors(int n)
{
    int no_of_divisors = 0;

    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            if(i*i == n)
                no_of_divisors++;
            else
                no_of_divisors += 2;
        }
    }

    return no_of_divisors;
}

long long triangular_number(long long n)
{
    return (n*(n + 1))/2;
}

int main()
{
    const int REQUIRED_DIVISORS = 500;

    for(int n = 1; ; n++)
    {
        int no_of_divisors = (n%2 == 0 ? divisors(n >> 1)*divisors(n + 1) : divisors(n)*divisors( (n + 1) >> 1));

        if(no_of_divisors > REQUIRED_DIVISORS)
        {
            printf("Triangular no %d = %I64d has %d divisors.\n", n, triangular_number(n), no_of_divisors);
            break;
        }
    }

    return 0;
}

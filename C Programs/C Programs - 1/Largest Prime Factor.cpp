#include <cstdio>

int main()
{
    long long n, reduced_n;
    printf("Enter the number\n");
    scanf("%I64d", &n);

    reduced_n = n;
    long long largest_prime_factor;

    for(long long i = 2; i*i <= n; i++)
    {
        if(reduced_n%i == 0)
        {
            largest_prime_factor = i;
            while(reduced_n%i == 0)
            {
                reduced_n /= i;
            }
        }
    }

    if(reduced_n > 1)
        largest_prime_factor = reduced_n;

    printf("Largest Prime Factor of %I64d is %I64d\n", n, largest_prime_factor);
}


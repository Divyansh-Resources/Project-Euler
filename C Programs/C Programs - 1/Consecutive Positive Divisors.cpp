#include <cstdio>

const int LIMIT = 1e7 + 1;
int largest_prime_factor[LIMIT] = {0};
long long no_of_divisors[LIMIT] = {0};

int main()
{
    int no_of_pairs = 0;

    no_of_divisors[1] = 1;
    for(int i = 2; i < LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            no_of_divisors[i] = 2;

            for(int multiple = 2*i; multiple < LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
        }
        else
        {
            int p = largest_prime_factor[i];
            int reduced_i = i;

            int exponent = 0;

            while(reduced_i%p == 0)
            {
                reduced_i /= p;
                exponent++;
            }

            no_of_divisors[i] = (exponent + 1)*no_of_divisors[reduced_i];
        }

        no_of_pairs += (no_of_divisors[i] == no_of_divisors[i - 1]);
    }

    printf("There are %d integers n, such that n and n+1 have the same number of divisors below 10 million.\n", no_of_pairs);
    return 0;
}

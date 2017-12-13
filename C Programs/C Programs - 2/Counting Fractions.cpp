#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int LIMIT = 1e6;
    vector <int> largest_prime_factor(LIMIT + 1, 0);

    for(int i = 2; i <= LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
            for(int multiple = i; multiple <= LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
    }

    vector <int> totient(LIMIT + 1, 0);
    totient[1] = 1;
    for(int i = 2; i <= LIMIT; i++)
    {
        int p = largest_prime_factor[i];
        int reduced_i = i;

        int p_power_alpha = 1;


        while(reduced_i%p == 0)
        {
            p_power_alpha *=p;
            reduced_i /= p;
        }

        totient[i] = (p_power_alpha - p_power_alpha/p)*totient[reduced_i];
    }

    vector <long long> totient_sum_till(LIMIT + 1, 0);
    for(int i = 2; i <= LIMIT; i++)
        totient_sum_till[i] = totient_sum_till[i - 1] + totient[i];

    printf("The number of fractions with d <= %d is %I64d.\n", LIMIT, totient_sum_till[LIMIT]);
    return 0;
}


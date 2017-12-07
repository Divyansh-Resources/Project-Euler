#include <cstdio>
#include <vector>

using namespace std;

long long amicable_number_sum_till(int LIMIT)
{
    vector <int> sum_of_divisors(LIMIT + 1, 0);

    for(int i = 1; i <= LIMIT; i++)
    {
        for(int multiple = 2*i; multiple <= LIMIT; multiple += i)
        {
            sum_of_divisors[multiple] += i;
        }
    }

    long long sum = 0;

    for(int i = 1; i <= LIMIT; i++)
    {
        int divisor_sum = sum_of_divisors[i];

        sum += i*(divisor_sum < LIMIT && divisor_sum != i && sum_of_divisors[divisor_sum] == i);
    }

    return sum;
}

int main()
{
    const int LIMIT = 1e4;

    long long sum;
    sum = amicable_number_sum_till(LIMIT);

    printf("The sum of all amicable numbers till %d is %I64d\n", LIMIT, sum);

    return 0;
}

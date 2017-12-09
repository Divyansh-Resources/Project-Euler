#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

void precompute(vector <int> &is_prime, vector <int> &prime, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
            prime.push_back(i);

        for(int j = 0; j < prime.size() && i*prime[j] < LIMIT; j++)
        {
            is_prime[i*prime[j]] = false;

            if(i%prime[j] == 0) break;
        }
    }
}

void get(int n, int frequency[])
{
    while(n)
    {
        frequency[n%10]++;
        n /= 10;
    }
}

int is_permutation(int a, int b, int c)
{
    const int NO_OF_DIGITS = 10;
    int digit_frequency_a[NO_OF_DIGITS] = {0}, digit_frequency_b[NO_OF_DIGITS] = {0}, digit_frequency_c[NO_OF_DIGITS] = {0};

    get(a, digit_frequency_a);
    get(b, digit_frequency_b);
    get(c, digit_frequency_c);

    for(int i = 0; i < NO_OF_DIGITS; i++)
        if(!(digit_frequency_a[i] == digit_frequency_b[i] && digit_frequency_b[i] == digit_frequency_c[i]))
            return false;

    return true;
}

long long concatenation(int a, int b, int c)
{
    return (1e8*a + 1e4*b + 1LL*c);
}

int main()
{
    const int LIMIT = 1e4;
    vector <int> is_prime(LIMIT + 1, true);
    vector <int> primes;
    precompute(is_prime, primes, LIMIT);

    int start = upper_bound(all(primes), 1000) - primes.begin();

    vector <long long> solution;

    for(int i = start; i < primes.size(); i++)
    {
        for(int j = i + 1; j < primes.size() - 1; j++)
        {

            int difference = primes[j] - primes[i];
            int next_term = primes[j] + difference;

            if(next_term < LIMIT && is_prime[next_term] && is_permutation(primes[i], primes[j], next_term))
                printf("%d, %d, %d\n", primes[i], primes[j], next_term), solution.push_back(concatenation(primes[i], primes[j], next_term));
        }
    }

    for(int i = 0; i < solution.size(); i++)
        printf("%I64d\n", solution[i]);

    return 0;
}

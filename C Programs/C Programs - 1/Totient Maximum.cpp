#include <cstdio>
#include <vector>

using namespace std;

#define all(v) (v).begin(), (v).end()

void precompute(vector <int> &primes, int LIMIT)
{
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] <= LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

int main()
{
    const int LIMIT = 100;
    vector <int> primes;
    precompute(primes, LIMIT);

    vector <long long> prime_product;
    prime_product.push_back(2);

    const long long MAX_VALUE = 1e18;
    for(int i = 1; prime_product.back() <= MAX_VALUE/primes[i]; i++)
    {
        prime_product.push_back(prime_product.back()*primes[i]);
    }

    long long n;

    printf("Enter the n for which n/phi(n) has to be maximised. n > 2 and n < 1e18. \n");
    scanf("%I64d", &n);

    int answer_index = lower_bound(all(prime_product), n) - prime_product.begin() - 1;
    long long answer = prime_product[answer_index];

    printf("n/phi(n) is maximum at %I64d\n", answer);
    return 0;
}

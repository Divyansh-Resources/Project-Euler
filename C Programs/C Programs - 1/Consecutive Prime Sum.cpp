#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &prime, vector <int> &is_prime, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
            prime.push_back(i);

        for(int j = 0; j < prime.size() && i*prime[j] <= LIMIT; j++)
        {
            is_prime[i*prime[j]] = false;

            if(i%prime[j] == 0) break;
        }
    }
}

int main()
{
    const int LIMIT = 1e6;
    vector <int> is_prime(LIMIT + 1, true);
    vector <int> prime;
    precompute(prime, is_prime, LIMIT);

    int maximum_summands = 0, answer_prime = 0;

    for(int left = 0; left + maximum_summands < prime.size(); left++)
    {
        int right = left;
        int sum = 0;

        for(; right <= prime.size() && sum <= LIMIT; right++)
        {
            sum += prime[right];

            int no_of_summands = right - (left - 1);

            if(sum <= LIMIT && is_prime[sum] && no_of_summands > maximum_summands)
            {
                answer_prime = sum;
                maximum_summands = no_of_summands;
            }
        }
    }

    printf("%d can be written as the sum of %d consecutive primes.\n", answer_prime, maximum_summands);
    return 0;
}

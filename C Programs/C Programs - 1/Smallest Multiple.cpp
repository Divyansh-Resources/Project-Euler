#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime;

void precompute_primes()
{
    vector <int> is_prime(40 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 40; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 40; multiple +=i)
            {
                is_prime[multiple] = false;
            }

            prime.push_back(i);
        }
    }

}

int main()
{
    int n;
    long long multiple = 1LL;
    precompute_primes();

    printf("Enter a number\n");
    scanf("%d", &n);

    for(unsigned int i = 0; prime[i] <= n && i != prime.size(); i++)
    {
        int max_power = prime[i];

        while(max_power*prime[i] <= n)
        	max_power *= prime[i];

        multiple *=max_power;
    }

    printf("Smallest number divisible by every number from 1 to %d is %I64d\n",n, multiple);

    return 0;
}




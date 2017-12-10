#include <cstdio>
#include <vector>

using namespace std;

void get(vector <int> &is_prime, vector <int> &squares, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i < LIMIT; i++)
    {
        if(is_prime[i])
            for(int multiple = i*i; multiple < LIMIT; multiple += i)
                is_prime[multiple] = false;
    }

    for(int i = 1; i*i < LIMIT; i++)
        squares.push_back(i*i);
}

int main()
{
    const int LIMIT = 1e5;
    vector <int> is_prime(LIMIT, true);
    vector <int> squares;
    get(is_prime, squares, LIMIT);

    for(int i = 3; i < LIMIT; i+=2)
    {
        int no_of_ways = 0;

        if(!is_prime[i])
        {
            for(int j = 0; j < squares.size() && 2*squares[j] <= i; j++)
                no_of_ways += (is_prime[i - 2*squares[j]]);
        }

        if(!is_prime[i] && no_of_ways == 0)
        {
            printf("The smallest counterexample is %d. It can't be written as prime + 2*square.\n", i); break;
        }
    }

    return 0;
}

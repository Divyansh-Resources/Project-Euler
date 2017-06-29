#include <cstdio>
#include <vector>

using namespace std;

vector <int> no_of_ways(200 + 1, 0);

void precompute_coin_sums()
{
    int coin_value[8 + 1] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

    no_of_ways[0] = 1;
    for(int coin_no = 1; coin_no <= 8; coin_no++)
    {
        for(int sum_reached = coin_value[coin_no]; sum_reached <= 200; sum_reached++)
        {
            /*f(i, j) = f(i, j - 1) + f(i - value[j], j) ...
            Now, it already holds the number of ways to reach sum without using j-th coin.
            So, at each point we use one j-coin.*/

            no_of_ways[sum_reached] = ( no_of_ways[sum_reached] + no_of_ways[sum_reached - coin_value[coin_no] ] );
        }
    }
}

int main()
{
    precompute_coin_sums();

    printf("No of ways to make 200 is %d.\n", no_of_ways[200]);
    return 0;
}

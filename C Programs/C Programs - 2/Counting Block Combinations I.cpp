#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int N = 50;
    vector <long long> no_of_ways(50 + 1, 1);

    no_of_ways[3] = 2;

    for(int n = 4; n <= N; n++)
    {
        no_of_ways[n] = 2*no_of_ways[n - 1] - no_of_ways[n - 2] + no_of_ways[n - 4];
    }

    printf("There are %I64d ways to tile %d blocks.\n", no_of_ways[N], N);
    return 0;
}

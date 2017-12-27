#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int N = 200, M = 50, THRESHOLD = 1e6;
    vector <int> no_of_ways(N, 1);

    no_of_ways[M] = 2;

    for(int n = M + 1; n < N; n++)
    {
        no_of_ways[n] = 2*no_of_ways[n - 1] - no_of_ways[n - 2] + no_of_ways[n - M - 1];

        if(no_of_ways[n] > THRESHOLD)
        {
            printf("The minimum value of the plane for the number of tilings > %d with minimum size of red = %d is = %d.\n", THRESHOLD, M, n);
            break;
        }
    }

    return 0;
}

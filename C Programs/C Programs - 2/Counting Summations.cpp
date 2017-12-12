#include <cstdio>
#include <cstring>

const int MAX_N = 101;
long long no_of_ways[MAX_N][MAX_N] = {{0}};

int get(int n, int largest_part)
{
    if(no_of_ways[n][largest_part] == -1)
    {
        if(n == 0)
        {
            no_of_ways[n][largest_part] = 1;
        }
        else if(largest_part == 1)
        {
            no_of_ways[n][largest_part] = 1;
        }
        else
        {
            no_of_ways[n][largest_part] = get(n, largest_part - 1);

            if(largest_part <= n)
                no_of_ways[n][largest_part] += get(n - largest_part, largest_part);
        }
    }

    return no_of_ways[n][largest_part];
}

int main()
{
    const int N = 100;
    memset(no_of_ways, -1, sizeof(no_of_ways));

    printf("The number of ways to write 100 as a sum of atleast 2 integers is %d.\n", get(N, N - 1));

    return 0;
}

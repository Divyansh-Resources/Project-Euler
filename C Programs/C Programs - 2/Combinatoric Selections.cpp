#include <cstdio>

int main()
{
    const int LIMIT = 100;
    int combinations[LIMIT + 1][LIMIT + 1] = {{false}};
    int greater_than_million[LIMIT + 1][LIMIT + 1] = {{false}};

    for(int n = 0; n <= LIMIT; n++)
    {
        for(int r = 0; r <= n; r++)
        {
            if(r == 0 || r == n)
            {
                combinations[n][r] = 1;
            }
            else if(greater_than_million[n - 1][r] || greater_than_million[n - 1][r - 1])
            {
                greater_than_million[n][r] = true;
            }
            else
            {
                combinations[n][r] = combinations[n - 1][r] + combinations[n - 1][r - 1];

                greater_than_million[n][r] = (combinations[n][r] > 1e6);
            }
        }
    }

    int no_of_values_greater_than_million = 0;
    for(int n = 0; n <= LIMIT; n++)
        for(int r = 0; r <= n; r++)
            no_of_values_greater_than_million += greater_than_million[n][r];

    printf("Upto n = 100, the number of C(n, r) that exceeds a million is %d.\n", no_of_values_greater_than_million);
    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> to_vector(int n)
{
    vector <int> number;
    while(n)
    {
        number.push_back(n%10);
        n /= 10;
    }

    reverse(number.begin(), number.end());
    return number;
}

int main()
{
    vector <int> number;
    number.push_back(0);

    const int LIMIT = 1e6;
    for(int i = 1; i < LIMIT; i++)
    {
        vector <int> n = to_vector(i);

        for(int j = 0; j < n.size(); j++)
            number.push_back(n[j]);
    }

    long long product = 1;
    for(int digit = 1; digit <= LIMIT; digit *= 10)
    {
        printf("Digit(%d) = %d\n", digit, number[digit]);
        product *= number[digit];
    }

    printf("%I64d\n", product);
    return 0;
}

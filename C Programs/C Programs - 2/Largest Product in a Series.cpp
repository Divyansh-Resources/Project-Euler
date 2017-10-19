#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int NO_OF_DIGITS = 1000;
    vector <int> number(NO_OF_DIGITS + 3, 0);
    for(int i = 1; i <= NO_OF_DIGITS; i++)
        scanf("%1d", &number[i]);

    long long answer = 0;
    for(int i = 13; i <= NO_OF_DIGITS; i++)
    {
        long long product = 1;
        for(int j = i - 12; j <= i; j++)
        {
            product *= number[j];
        }
        answer = max(answer, product);
    }

    printf("%I64d\n", answer);
    return 0;
}

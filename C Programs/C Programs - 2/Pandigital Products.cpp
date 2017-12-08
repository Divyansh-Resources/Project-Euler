#include <cstdio>

void get(int frequency[], int n)
{
    while(n)
    {
        frequency[n%10]++;
        n /= 10;
    }
}

int is_pandigital(int a, int b, int c)
{
    const int NO_OF_DIGITS = 10;
    int digit_frequency[NO_OF_DIGITS] = {0};

    get(digit_frequency, a);
    get(digit_frequency, b);
    get(digit_frequency, c);

    if(digit_frequency[0] > 0) return false;

    for(int i = 1; i <= 9; i++)
        if(digit_frequency[i] != 1)
            return false;

    return true;
}

int main()
{
    const int SMALLEST_4_DIGIT = 1000, LARGEST_4_DIGIT = 10000 - 1;
    int pandigital_sum = 0;

    for(int i = SMALLEST_4_DIGIT; i <= LARGEST_4_DIGIT; i++)
    {
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j == 0 && is_pandigital(j, i/j, i))
            {
                printf("%d x %d = %d\n", j, i/j, i);
                pandigital_sum += i;
                break;
            }
        }
    }

    printf("The sum of all such numbers is %d.\n", pandigital_sum);
    return 0;
}

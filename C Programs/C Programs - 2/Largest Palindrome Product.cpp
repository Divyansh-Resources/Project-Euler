#include <cstdio>

#define max(a, b) (a > b ? a : b)

int reverse(int n)
{
    int rev = 0;

    while(n)
    {
        rev = rev*10 + n%10;
        n = n/10;
    }

    return rev;
}

int is_palindrome(int n)
{
    return (n == reverse(n));
}

int main()
{
    const int SMALLEST_3_DIGIT = 100, LARGEST_3_DIGIT = 999;
    int largest_product = 0;

    for(int i = SMALLEST_3_DIGIT; i <= LARGEST_3_DIGIT; i++)
    {
        for(int j = i + 1; j <= LARGEST_3_DIGIT; j++)
        {
            if(is_palindrome(i*j)) printf("%d\n", i*j), largest_product = max(largest_product, i*j);
        }
    }

    printf("Largest = %d\n", largest_product);
    return 0;
}

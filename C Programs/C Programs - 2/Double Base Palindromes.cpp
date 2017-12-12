#include <cstdio>

int reverse(int n, int base)
{
    int rev = 0;

    while(n)
    {
        rev = rev*base + n%base;
        n /= base;
    }

    return rev;
}

int is_palindrome(int n, int base)
{
    return (n == reverse(n, base));
}

int main()
{
    const int N = 1e6;

    int double_palindrome_sum = 0;
    for(int i = 1; i < N; i++)
    {
        if(is_palindrome(i, 10) && is_palindrome(i, 2))
            printf("%d\n", i), double_palindrome_sum += i;
    }

    printf("The sum of double base palindromes is %d.\n", double_palindrome_sum);
    return 0;
}


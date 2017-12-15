#include <cstdio>
#include <vector>
#include <set>

using namespace std;

void precompute(vector <int> &square, int MAX_N)
{
    for(int i = 1; i <= MAX_N; i++)
        square.push_back(i*i);
}

int reverse(int n)
{
    int rev = 0;

    while(n)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }

    return rev;
}

int is_palindrome(int n)
{
    return (n == reverse(n));
}

int main()
{
    const int MAX_N = 1e4;
    vector <int> squares;
    precompute(squares, MAX_N);

    const int MAX_SUM = 1e8;

    set <int> palindromes;

    for(int left = 0; left < squares.size(); left++)
    {
        int square_sum = squares[left];

        for(int right = left + 1; right < squares.size() && square_sum + squares[right] < MAX_SUM ; right++)
        {
            square_sum += squares[right];

            if(is_palindrome(square_sum))
                palindromes.insert(square_sum);
        }
    }

    long long palindrome_sums = 0;
    for(set <int> :: iterator i = palindromes.begin(); i != palindromes.end(); i++)
        palindrome_sums += *i;

    printf("The sum of all palindromes that can be written as sums of consecutive squares below %d is %I64d.\n", MAX_SUM, palindrome_sums);
    return 0;
}

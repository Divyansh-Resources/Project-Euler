#include <cstdio>

int main()
{
    const int N = 1000;

    for(int a = 1; a <= N; a++)
    {
        for(int b = a + 1; b < N - a; b++)
        {
            int c = N - (a + b);

            if( (c*c == a*a + b*b) || (b*b == a*a + c*c))
                printf("The triplet(%d, %d, %d) sums up to 1000. Product = %d.\n", a, b, c, a*b*c);
        }
    }

    return 0;
}

#include <cstdio>
#define max(a, b) (a > b ? a : b)

int main()
{
    const int N = 1000;

    int max_triangles = 0, answer;
    for(int n = 1; n <= N; n++)
    {
        int no_of_triangles = 0;

        for(int a = 1; a < n; a++)
        {
            for(int b = a + 1; b < n - a; b++)
            {
                int c = n - (a + b);

                no_of_triangles += (c*c == a*a + b*b || b*b == a*a + c*c);
            }
        }

        if(no_of_triangles > max_triangles) answer = n;
        max_triangles = max(max_triangles, no_of_triangles);
    }


    printf("There are %d right triangles with perimeter = %d.\n", max_triangles, answer);

    return 0;
}

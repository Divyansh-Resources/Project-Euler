#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define limit 1001
int main()
{
    clock_t start, end;
    double time_taken;
    int i;
    long sum = 1;

    start = clock();

    //The top most corners are given by n^2, then n^2 - n + 1, then n^2 - 2n + 2 and n^2 - 3n + 3
    //It repeats for all odd n
    for(i = 3; i <= limit; i+=2)
    {
        sum = sum + 4*i*i-6*i + 6 ;
    }

    printf("The sum of the diagonal elements is %ld.\n",sum);

    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("It took %f seconds to execute.\n",time_taken);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define limit 4000000

int main()
{
    int fibo[35]; //The 34th term exceeds four million
    int i, last_index = 2;
    long long sum = 0;

    //Building an array of Fibonacci numbers until a term exceeds four million
    fibo[0] = 0;
    fibo[1] = 1;
    for(last_index = 2; ;last_index++)
    {
        fibo[last_index] = fibo[last_index - 1] + fibo[last_index - 2];

        //For some reason, this break condition works when it is inside the loop
        //but not in the for loop definition
        if(fibo[last_index] > limit)
        {
        	break;
        }
    }

    //Every third term in the Fibonacci series is even. So, we sum over it.
    for(i = 3; i < last_index;i = i+3)
    {
        sum = sum + fibo[i];
    }

    //Printing the result
    printf("The sum of even Fibonacci numbers below four million is %lld.\n",sum);

    return 0;
}

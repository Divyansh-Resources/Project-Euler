#include <stdio.h>
#include <time.h>

#define base 10
#define bound 354294//This is 9^5 x 6. 9^5 x 7 is smaller than the smallest seven digit number. So, 9^5x6 is the upper bound.

//Function Prototypes
void make_hash_table(int[]);
void search_for_numbers(int[], long[]);
void display(long[]);

int main()
{
    int fifth_power_table[base];
    long solution[10];
    clock_t start, end;
    double elapse;

    start = clock();

    make_hash_table(fifth_power_table);
    search_for_numbers(fifth_power_table, solution);
    display(solution);

    end = clock();
    elapse = (double)(end - start)/CLOCKS_PER_SEC;

    printf("\nIt took %f seconds to execute.\n", elapse);
    return 0;
}

//Making a hash table where T(n) = n^5
//Warning - Highly specialised code. Doesn't work in general for n^m.
//It uses the idea n^5 = n^2 * n^2 n. Uses three multiplications rather than four.
void make_hash_table(int fifth_power_table[])
{
    int i;

    for(i = 0; i < base; i++)
    {
        fifth_power_table[i] = i*i; //T(n) = n^2
        fifth_power_table[i] = fifth_power_table[i]*fifth_power_table[i];//T(n) = n^2 x n^2 = n^4
        fifth_power_table[i] = fifth_power_table[i]*i; //T(n) = n^4x n = n^5
    }
}

//Searching for numbers and adding them to the solution vector
void search_for_numbers(int fifth_power_table[], long solution[])
{
    int solution_count = 0;
    long i = 1, sum, temp;

    //Going through all numbers from 1 till the upper bound.
    for(i = 1; i < bound; i++)
    {
        //Getting the sum of the fifth digit powers
        sum = 0;
        for(temp = i; temp > 0; temp = temp/base)
        {
                sum = sum + fifth_power_table[ (temp%base) ];
        }

        //Checking if the sum is equal to the number
        if(sum == i)
        {
            solution[solution_count++] = i;
        }
    }

    //Putting a zero to mark the end of the array.
    solution[solution_count] = 0;
}

//Displaying the solution
void display(long solution[])
{
    int i;
    long sum = 0;

    printf("The numbers which are the sum of their fifth power digits in base %d are -\n",base);
    for(i = 0; solution[i] != 0; i++)
    {
        printf("%d\t",solution[i]);
        sum = sum + solution[i];
    }
    printf("\n\nThe sum of these numbers is %d.\n",sum);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define spiral_order 1001//It has to be an odd number
#define middle ( (spiral_order-1 )/2)

//Function Prototypes
void make_spiral();
void display_spiral();
long long calculate_sum();

//Global declarations
long spiral[spiral_order][spiral_order]; //It is a matrix

int main()
{
    clock_t start, end;
    double time_taken;
    long long sum = 0;

    start = clock();
    //Making the spiral
    make_spiral();

    /*This function displays the spiral. Only use it to check if the function is working for small values.
    display_spiral();*/
    sum = calculate_sum();

    printf("The sum of the diagonal elements is %lld.\n",sum);

    end = clock();
    time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("It took %f seconds to execute.\n",time_taken);
    return 0;
}

void make_spiral()
{
    long current_number = 1;
    int i = middle , j = middle; //Process starts in the middle
    int top_row, right_column;
    int bottom_row, left_column;

    //We put the midde elements in ourselves and loop the rest of the spiral
    spiral[i][j] = current_number++;

    //Loop ends when the last element of the first row is filled up
    while( (i != 0) && (j != spiral_order) )
    {
        //If a cycle ends at (i,j), the next cycle ends at ( (i - 1), (j + 1) )
        //Visually, it's the top right corner of the next biggest square.
        top_row = i - 1;
        right_column = j + 1;


        //We have reached the ending column, then we walk down the rows of the same column till we reach the bottom row of the outer square
        //For the current outer square which will be drawn, bottom_row - middle = middle - ending_i
        bottom_row = 2*middle - top_row;
        j = j+1;
        for( ; i < bottom_row ; i++)
        {
            spiral[i][j] = current_number;
            current_number++;
        }

        //Now, we walk backwards through the columns of the outer row
        //The same invariant holds. ending_j - middle = middle - first_column
        left_column = 2*middle - right_column;
        //j = j-1;
        for( ; j > left_column ; j--)
        {
            spiral[i][j] = current_number;
            current_number++;
        }

        //i = i - 1;
        for( ;i > top_row ; i-- )
        {
            spiral[i][j] = current_number;
            current_number++;
        }

        //j++;
        for(;j < right_column ; j++)
        {
            spiral[i][j] = current_number;
            current_number++;
        }

        //Putting the last number of the square into the spiral
        spiral[i][j] = current_number;
        current_number++;

    }
}

void display_spiral()
{
    int i, j;

    for(i = 0; i < spiral_order; i++)
    {
        for(j = 0; j < spiral_order; j++)
        {
            printf("%d\t",spiral[i][j]);
        }
        printf("\n");
    }
}

long long calculate_sum()
{
    long long sum = 0;
    int i;

    //Calculating the sum of the principal diagonal
    for(i = 0; i < spiral_order; i++)
    {
        sum = sum + spiral[i][i];
    }

    //Sum of antidiagonal
    for(i = 0; i < spiral_order; i++)
    {
        sum = sum + spiral[i][spiral_order - i -1];
    }

    //The middle element is counted twice
    sum = sum - spiral[middle][middle]; //Integer division so the answer will be (order-1)/2. No need to write (order -1)/2

    return sum; //Returning the sum so that it can be displayed
}

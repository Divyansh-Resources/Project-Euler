#include <stdio.h>

#define limit 1000001 //Array index goes until limit - 1
//Global Declarations
long long collatz_sequence_length[limit];

//Function Prototypes
void initialise_sequence_length();
void get_maximum_length_source();
void get_collatz_sequence_length();

int main()
{
        initialise_sequence_length();
        get_collatz_sequence_length(); //Getting the sequence length of all numbers
        get_maximum_length_source(); //Displays the maximum;

        return 0;
}

//Setting the initial length to zero for all elements
void initialise_sequence_length()
{
    long i;

    for(i = 1; i < limit; i++)
    {
        collatz_sequence_length[i] = 0;
    }
}

void get_collatz_sequence_length()
{
    long long i = 2,current_term;

    for(i = 2; i < limit; i++)
    {
        //Finding collatz sequence length of i
        current_term = i;
        while(current_term != 1)
        {
            collatz_sequence_length[i]++;

            if(current_term %2 == 0)
            {
                current_term = current_term/2;
            }
            else
            {
                current_term = 3*current_term + 1;
            }
           //printf("%ld->",current_term);
            //If it's already visited. The first condition is there to ensure we only check for
            //collatz_sequence_length[current_term] when it is within bounds to prevent junk  values
            if( (current_term < limit) && (collatz_sequence_length[current_term] != 0) )
            {
                collatz_sequence_length[i] = collatz_sequence_length[i] + collatz_sequence_length[current_term];
                current_term = 1;
            }
        }
    }
}
//Finding the minimum
void get_maximum_length_source()
{
    long long maximum, maximum_source, i;

    //Initially, first element is maximum
    maximum = collatz_sequence_length[1];

    //Running through all the numbers and updating the maximum
    for(i = 2; (i < limit) ; i++)
    {
        if(collatz_sequence_length[i] > maximum)
        {
            maximum = collatz_sequence_length[i];
            maximum_source = i;
        }
    }

    //If these two values were printed together, then the second term gets displayed as zero for some reason.
    printf("The number with the maximum length sequence is %ld.",maximum_source);
    printf("It has %ld terms in it's Collatz sequence.\n",maximum);

}

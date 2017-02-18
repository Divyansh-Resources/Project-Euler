#include <stdio.h>
#include <stdlib.h>

#define no_of_tuple_elements 10
#define question 1000000

//Function Prototypes
void create_hash_table(int[]);
void get_factorial_base(long, int[], int[]);
//void display_factorial_base(long, int[]);
void convert_factorial_base_to_tuple(int[], int[]);
void display_tuple(int, int[]);

int main()
{
    int hash_table_fact[no_of_tuple_elements], factorial_base[no_of_tuple_elements], tuple[no_of_tuple_elements];
    long number = question - 1;//There is a zeroeth permutation. Permutation #n corresponds with #(n-1) in the new factorial_base

    create_hash_table(hash_table_fact); //Where T[n] = n!

    get_factorial_base(number, factorial_base, hash_table_fact);
    //display_factorial_base(number, factorial_base);
    convert_factorial_base_to_tuple(factorial_base, tuple);
    display_tuple(number, tuple);

    return 0;
}

//Creating a table where T[n] = n!. I need as many digits as the number of tuple elements.
void create_hash_table(int hash_table_fact[])
{
    short i = 1;
    hash_table_fact[0] = 1; //0! = 1

    for(i = 1; i <= no_of_tuple_elements - 1; i++)
    {
        hash_table_fact[i] = hash_table_fact[i-1]*i;
        //printf("T[%d] = \t%d\n",i,hash_table_fact[i]);
    }
}

/*We write number as a string of digits a_{n} a_{n-1} a_{n-2}... a_0
where number = \sum_{i=0}^n a_i \times i!
The same string in the decimal system would mean \sum_{i=0}^n a_i \times 10^i
The new factorial_base is more convenient in visiting a tuple we want.
The procedure is simple. We start with the highest 'place value' and find the highest multiplier for the place value which is smaller than num.
Then, we repeat the process with process with (num-chosen_multiplier*place_value) for the remaining places.
Everyone number has such a factorial_base. An obvious upper bound an a_i is it should be less than or equal to i.
If it is (i+1), then (i+1)*i = (i+1)! - the value of the next more significant place. That would mean that a better multiplier can be chosen for (i+1)th place.
In the following function, that limit is enforced for every digit other than the most significant digits.
A rigorous proof can be given that any number less than n! can be written in (n-1) digits in this factorial_base using induction.
So, if number is greater \sum_{i=0}^n (i) a_i, where n is the size of the factorial_base array, then
a_n will be greater than n.
After that n will be reduced to a number that can be represented in (n-1) digits so there will be no further anamolies.
The most significant digit doesn't have a more significant digit to delegate work to so it is possible for a_n to be greater than n.
That and the trailing zeroes are two drawbacks of this procedure.
It is somewhat analogous to overflow and underflow. */
void get_factorial_base(long number, int factorial_base[], int hash_table_fact[])
{
    int i = no_of_tuple_elements - 1;//Counting starts from 0
    long current_digit = 0, current_place_value;

    //Finds the ith digit of the number in a new factorial_base
    for(i = no_of_tuple_elements - 1; i >= 0; i--)
    {
        current_digit = 0;
        current_place_value = hash_table_fact[i]; //Place value in this new factorial_base is i!

        //Finding the lowest value of current digit for which i*place value is greater than number
        while(current_digit*current_place_value <= number)
        {
            current_digit ++;
        }

        //Current Digit is one higher than required
        current_digit--;


        //Updating the value of current digit in factorial_base
        factorial_base[i] = current_digit;
        number = number - current_digit*current_place_value; //Updating the value of number for the next iteration
    }
}

/*//Displaying the number's new factorial_base - Only for testing. Not required
void display_factorial_base(long number, int factorial_base[])
{
    int i;

    //Note - The digits have to be displayed from left to right just as we write decimal numbers. So, we start i from Most Significant and decrement to 0
    printf("In the new base, %ld is written as ",number);
    for(i = no_of_tuple_elements - 1; i >= 0;i--)
    {
        printf("%d",factorial_base[i]);
    }
    printf("\n");
}*/

/*If num = a_n a_{n-1} ... a_1 a_0, then the num-th permutation is given as follows -
The i-th element of the permutation is the a_i-th largest digit that has not already been written.
In other words, the a_i - th largest available digit. There is a clear bijection.*/
void convert_factorial_base_to_tuple(int factorial_base[], int tuple[])
{
    short available[no_of_tuple_elements]; //It is a vector which keeps track of which element is available.
    int current_digit, available_count, i, j;
    //Initially everything is marked available
    for(i = 0; i <= no_of_tuple_elements - 1; i++)
    {
        available[i] = 1;
    }

    //Making each element of the tuple starting with the most significant
    for(i = no_of_tuple_elements - 1; i >= 0; i--)
    {
        current_digit = factorial_base[i];

        //Finding the a_i th smallest digit which is available
        for(j = 0, available_count = 0; available_count <= current_digit; j++)
        {
            //Checking if j-th element is available
            if(available[j] == 1)
            {
                available_count++;
            }
        }

        tuple[i] = --j; //j is put into the i-th position
        available[j] = 0;//Marking j unavailable
    }
}

void display_tuple(int position, int tuple[])
{
    int i;

    printf("The tuple at position # %d is ", (position+1) );//Permutation #(position + 1) corresponds with position since counting starts from 0.

    //This needs to be written from left to right too. Most Significant to Least Significant
    for(i = no_of_tuple_elements - 1; i >= 0; i--)
    {
        printf("%d",tuple[i]);
    }
    printf("\n");
}

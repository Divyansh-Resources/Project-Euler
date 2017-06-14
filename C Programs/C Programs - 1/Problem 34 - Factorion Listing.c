#include <stdio.h>
#include <stdlib.h>
#define base 10 //We are working in base 10
#define upper_bound 2540160 //This is 7 x 9! because a factorion can have at most seven digits.
//If it has d digits, it must satisfy the inequality 10^{d-1} < n <= 9!d, which isn't satisfied above d = 8
#define expected_no_of_answers 5 //I chose 5 somewhat arbitrarily. I knew beforehand there are only four answers in base 10

//Function prototype
void create_hash_table(int[]);
void get_fact_digit_sum(int[],int[]);
void display_answers(int[]);

int main()
{
    int hash_table_fact[base], answers[expected_no_of_answers]; //Creating a hash table where t[n] -> n!

    create_hash_table(hash_table_fact);

    get_fact_digit_sum(answers,hash_table_fact);

    display_answers(answers);

    return 0;
}

void create_hash_table(int hash_table_fact[])
{
    int i = 1, fact = 1;
    hash_table_fact[0] = 1; //0! = 1

    for(i = 1; i < base; i++)
    {
        fact = fact*i;
        hash_table_fact[i] = fact;
    }
}

void get_fact_digit_sum(int answers[], int hash_table_fact[])
{
    int answerCount = 0, last_digit = 0, i = 1, temp, sum;

    //Combing through the search space to search for factorions
    for(i = 1; i <= upper_bound; i++)
    {
        temp = i;
        sum = 0;
        //Getting the sum of the factorials of the digits
        while(temp != 0)
        {
            last_digit = temp%base;
            sum = sum + hash_table_fact[last_digit];
            temp = temp/base;
        }
        if(sum == i)
        {
            answers[answerCount++] = i;
        }
    }

    //Placing a 0 at the end to mark the end of the array
    answers[answerCount] = 0;
}

void display_answers(int answers[])
{
    int i;
    printf("The factorions are -\n");
    //0 marks the end of the solution vector.
    for(i = 0; answers[i] != 0; i++)
    {
        printf("%d\t",answers[i]);
    }
}

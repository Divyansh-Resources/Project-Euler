#include <stdio.h>
#include <stdlib.h>

#define base 10

int main()
{
    unsigned int  numerator_product = 1, denominator_product = 1, d,b,a, gcd_fraction;

    for(d = 3; d < base; d++)
    {
        for(b = 2; b < d; b++)
        {
            for(a = 1; a < b; a++)
            {
                if(9*a*(d-b) == d*(b - a))
                {
                    //Multiplying the fractions to get a bigger fraction.
                    numerator_product = numerator_product*(10*a + d);
                    denominator_product = denominator_product*(10*d + b);

                    //Displaying the fractions
                    printf("%u/%u\t",(10*a + d), (10*d + b));

                }
            }
        }
    }

    //Reducing the fraction to it's lowest terms
    printf("\nThe fraction obtained by multiplying these fractions is %u/\t%d\n",numerator_product, denominator_product);

    gcd_fraction = gcd(numerator_product, denominator_product);
    numerator_product = numerator_product/gcd_fraction;
    denominator_product = denominator_product/gcd_fraction;

    printf("\nThe fraction in it's lowest terms is %d/%d.\n",numerator_product,denominator_product);
    return 0;
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    long p;
    long q;
    int counter = 0;
    int sum_of_odd_digit = 0;
    int sum_of_odd_digit_a = 0;
    int sum_of_odd_digit_b = 0;
    int sum_of_even_digit = 0;
    int total_sum;

    n = get_long("Enter Number:- ");
    long r = n;

    while (r > 0)
    {

        p = r % 10;
        if (counter % 2 != 0)
        {
            if (p * 2 > 9)
            {
                q = ((p * 2) % 10) + (((p * 2) - ((p * 2) % 10)) / 10);
                sum_of_odd_digit_a += q;
            }
            else
            {
                sum_of_odd_digit_b += (p * 2);
            }
        }
        else
        {
            sum_of_even_digit += p;
        }

        r = r / 10;
        counter++;
    }

    total_sum = sum_of_even_digit + sum_of_odd_digit_b + sum_of_odd_digit_a;

    if (total_sum % 10 == 0)
    {
        if ((n > 339999999999999 && n < 350000000000000) || (n > 369999999999999 && n < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if ((n > 3999999999999 && n < 5000000000000) || (n > 3999999999999999 && n < 5000000000000000))
        {
            printf("VISA\n");
        }
        else if ((n >= 5100000000000000 && n <= 5199999999999999) || (n >= 5200000000000000 && n <= 5299999999999999) || (n >= 5300000000000000 && n <= 5399999999999999) || (n >= 5400000000000000 && n <= 5499999999999999) || (n >= 5500000000000000 && n <= 5599999999999999))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf(" INVALID\n");
    }
}


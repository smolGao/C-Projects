// Check validity of a credit card number
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get credit card number from user
    long card_number = 0;
    do
    {
        card_number = get_long("Enter a credit card number: ");
    }
    while (card_number == 0);

    // Checksum
    long temp = card_number;

    // Find sum of every other number multiplied by two, sum of numbers that weren't multiplied, and length of the number.
    int odd = 0;
    // Multiplied sum
    long sum1 = 0;
    // Sum of number that aren't multiplied
    long sum2 = 0;
    // Length of the number
    int length = 0;

    // Find two sums and length until there are only two digits
    while (temp >= 100)
    {
        if (odd == 1)
        {
            long product = (temp % 10) * 2;
            odd = 0;
            // Add digits separately (not product as a whole)
            while (product != 0)
            {
                sum1 += product % 10;
                product /= 10;
            }
        }
        else
        {
            sum2 += temp % 10;
            odd = 1;
        }
        length++;
        temp /= 10;
    }

    // Record first two digits
    int two_digits = temp;

    // Add first two digits to two sum, respectively
    while (temp != 0)
    {
        if (odd == 1)
        {
            long product = (temp % 10) * 2;
            odd = 0;
            // Add digits separately (not product as a whole)
            while (product != 0)
            {
                sum1 += product % 10;
                product /= 10;
            }
        }
        else
        {
            sum2 += temp % 10;
            odd = 1;
        }
        length++;
        temp /= 10;
    }

    // Debug
    printf("sum1 = %li, sum2 = %li, sum = %li, length = %d", sum1, sum2, sum1+sum2, length);
    // Checksum is success
    if ((sum1 + sum2) % 10 == 0)
    {
        // Print corresponding credit card type
        if ((two_digits == 34 || two_digits == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (two_digits >= 51 && two_digits <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (two_digits / 10 == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Checksum failed
    else
    {
        printf("INVALID\n");
    }
}
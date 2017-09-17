#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

// Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
// Luhn's algorithm can determine if a credit card number is valid by checking these:
// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
// Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

// TODO:
// prompt user for number
// multiply every other digit
// sum those digits
// add to remaining digits
// validate checksum
// validate company's identifier
// validate number's length


int main(void)
{
    // Get the credit card number and store it in ccNumber
    long long ccNumber, originalNumber;
    int totalSum = 0, digits = 0, lastDigit = 0, oddDigit = 0, evenDigit = 0, evenNumber = 0;
    bool isEven = false;
    string companyName;

    do
    {
        ccNumber = get_long_long("Enter your credit card number: ");
        if (ccNumber < 0)
        {
            printf("You must enter a positive number!\n");
        }
    }
    while (ccNumber < 0);

    // ccNumber will get modified to find out the number of digits so store in original
    originalNumber = ccNumber;

    // Get the number of digits in the ccNumber
    while (ccNumber != 0)
    {
        // Get last digit
        lastDigit = (ccNumber / 10) % 10;

        // Increment digits so we know how many digits exist in ccNumber
        digits++;

        // Now have last digit, check if even or odd digit
        // Initially, isEven is set to false
        // so when we check the first time with the lastDigit, it'll execute the else block
        if (isEven == true)
        {
            evenNumber = lastDigit * 2;

            // Add each digit separately together
            while (evenNumber != 0)
            {
                evenDigit = evenDigit + evenNumber % 10;
                evenNumber = evenNumber / 10;
            }

            // Next iteration, digit will be odd
            isEven = false;
        }
        else
        {
            // Increment oddDigit with lastDigit
            oddDigit += lastDigit;

            // Next iteration, digit will be even
            isEven = true;
        }

        // Remove last digit and keep interating until ccNumber = 0
        ccNumber = ccNumber / 10;
    }

    // Sum the evenDigit and oddDigit and store in variable

    totalSum = evenDigit + oddDigit;

    // If totalSum mod 10 is 0, it is a valid card

    if (totalSum / 10 == 0)
    {
        // Check for AMEX : needs to be 15 digits
        if (digits == 15)
        {
            if ((originalNumber / (long long) 10E12) == 34 ||
                (originalNumber / (long long) 10E12) == 37)
            {
                companyName = "AMEX";
            }
            else
            {
                companyName = "INVALID";
            }
        }
        else if (digits == 16)
        {
            // Check for MasterCard : needs to be 16 digits
            if ((originalNumber / (long long) 10E13) >= 51 &&
                (originalNumber / (long long) 10E13) <= 55)
            {
                companyName = "MASTERCARD";
            }
            // Check for Visa : needs to be 13 or 16 digits
            else if ((originalNumber / (long long) 10E14) == 4)
            {
                companyName = "VISA";
            }
            else
            {
                companyName = "INVALID";
            }
        }
        // Check Visa
        else if (digits == 13)
        {
            if ((originalNumber / (long long) 10E11) == 4)
            {
                companyName = "VISA";
            }
            else
            {
                companyName = "INVALID";
            }
        }
        else
        {
            companyName = "INVALID";
        }
    }
    else
    {
        companyName = "INVALID";
    }

    // Print result
    printf("%s\n", companyName);

    return 0;
}
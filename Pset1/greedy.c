#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Define the value for each coin in cents

#define QUARTER 25;
#define DIME 10;
#define NICKEL 5;

int main(void)
{
    // Properties
    // You will be given a float number that is in dollars, need to convert later to cents
    float amountGiven;
    // Given amount in dollars by user, convert it to cents
    int centsAmount, leftoverAmount, quarterCount, dimeCount, nickelCount, coinsCount;
    // prompt user for an amount of change they owe
    do
    {
        amountGiven = get_float("How much did you give me? ");
        if (amountGiven < 0)
        printf("You need to enter a number greater than 0. eg. 1.50, 0.65, 2.12\n");
    }
    while (amountGiven < 0);
    // Convert the amount given by user from dollars to ONLY cents
    centsAmount = (int)round(amountGiven * 100);
    // Quarter count
    quarterCount = centsAmount / QUARTER;
    leftoverAmount = centsAmount % QUARTER;
    // Dime count
    dimeCount = leftoverAmount / DIME;
    leftoverAmount = leftoverAmount % DIME;
    // Nickel count
    nickelCount = leftoverAmount / NICKEL;
    leftoverAmount = leftoverAmount % NICKEL;
    // leftoverAmount = pennies right now after using up all quarters, dimes, nickels
    coinsCount = quarterCount + dimeCount + nickelCount + leftoverAmount;
    printf("I will give you back %i coins.\n", coinsCount);
}
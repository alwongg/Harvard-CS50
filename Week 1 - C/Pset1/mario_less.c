#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt user for the half-pyramid's height
    // declare a variable "height" to store get_int so it can be used outside of the do while block
    int height;
    // pester the user for an input that follows the conditions!
    // get the user to input a number that is bigger than 0, otherwise program will keep asking for +int
    do
    {
        //eprintf("about to prompt user for a number \n");
        height = get_int("Height for mario:");
    }
    while (height < 0 || height > 23);
    // draw the half pyramid
    // use a for loop -> with initialization, condition, and incrementation
    for (int row = 0; row < height; row++)
    {
        // print spaces for each column
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        // print hashes for each column
        for (int hash = 0; hash < row + 2; hash++)
        {
            printf("#");
        }
        // print new line
        printf("\n");
    }
}

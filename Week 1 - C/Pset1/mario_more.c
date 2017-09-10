#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("How high do you want mario to climb?: ");
    }
    while (height < 0 || height > 23);
    for (int row = 0; row < height; row++)
    {
        // print left spaces
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        // print left hashes starting with 1 at top
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        // print gap of 2 spaces
        for (int gap = 0; gap < 2; gap++)
        {
            printf(" ");
        }
        // print right hashes starting with 1 at top
        for (int hash2 = 0; hash2 < row + 1; hash2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
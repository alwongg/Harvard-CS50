#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for only 2 argc (the ./caesar and the number)
    if (argc < 2)
    {
        printf("You need at least 1 command-line argument\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("You can only have 1 command-line argument\n");
        return 1;
    }
    else
    {
        // convert string to integer using the function atoi to move "k" position
        int key = atoi(argv[1]);
        printf("Your key is: %d\n", key);
        if (key < 0)
        {
            printf("Your command-line argument must be non-negative.\n");
            return 1;
        }
        else
        {
            // prompt user for a plaintext
            string plainText = get_string("plaintext: ");
            // print ciphertext with characters from the for loop
            printf("ciphertext: ");
            // for each character in the plaintext string:
            for (int i = 0, n = strlen(plainText); i < n; i++)
            {
                // check if the character is uppercase
                if (isupper(plainText[i]))
                {
                    printf("%c", (((plainText[i] + key) - 65) % 26) + 65);
                }
                // if the character is lowercase
                else if (islower(plainText[i]))
                {
                    printf("%c", (((plainText[i] + key) - 97) % 26) + 97);
                }
                else
                {
                    printf("%c", plainText[i]);
                }
            }
        }
    }
    printf("\n");
    return 0;
}
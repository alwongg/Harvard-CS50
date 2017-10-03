#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for only 2 argument counts (the ./vigenere and the keyword)
    // if argc does not equal 2, then remind user that they can only give one keyword for the command-line argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    // argc is 2, let's keep going!
    {
        // store argv[1] (the keyword) into the keyword variable string
        string keyword = argv[1];
        int n = strlen(keyword);
        // iterate through the keyword and check if a non-alphabetical character exists
        // if it does, remind user the keyword must only contain letters
        for (int i = 0; i < n; i++)
        {
            if (isalpha(keyword[i]) == false)
            {
                printf("Keyword must only contain letters!\n");
                // returning 1 signifies an error
                // 0 signifies success!
                return 1;
            }
        }
        // If program has not exited, it means you can proceed here
        // prompt user for a plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        int l = strlen(plaintext);
        // iterate through the plaintext to shift each character
        for (int i = 0, j = 0, cipher = 0; i < l; i++)
        {
            char letter = plaintext[i];
            char key = keyword[j % n];

            if (isupper(key))
            {
                key -= 65;
            }
            else if (islower(key))
            {
                key -= 97;
            }

            if (isupper(letter))
            {
                cipher = (letter + key - 65) % 26 + 65;
                j++;
            }
            else if (islower(letter))
            {
                cipher = (letter + key - 97) % 26 + 97;
                j++;
            }
            else
            {
                cipher = letter;
            }
            printf("%c", cipher);
        }


    }
    printf("\n");
    return 0;
}
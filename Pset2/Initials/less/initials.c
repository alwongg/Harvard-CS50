#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// ctype.h is needed for the toupper function - to capitalize a character in a string
// string.h is needed for strlen - to find out the length of a string
// cs50.h is needed for get_stirng() - to get a string from the user
// stdio.h is needed for printf - to print to the console

int main(void)
{
    // Get a string from the user
    string name = get_string();
    // Don't need to worry about spaces so just capitalize and print the first character in string
    printf("%c", toupper(name[0]));
    // Iterate through the given string
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // If the character in name is a space
        if (name[i] == ' ')
        {
            // The next character after the space will be capitalized
            printf("%c", toupper(name[i + 1]));
        }
    }
    // Print new line
    printf("\n");
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("Name: ");
    printf("%c", toupper(name[0]));
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ' && name[i+1] != '\0')
        {
            printf("%c", toupper(name[i+1]));
            i++;
        }
    }
    printf("\n");
}
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    string hashPassword = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    else //proceed to crack the given password
    {
        printf("Success! Hello, %s\n", hashPassword);
    }
    //printf("\n");
    return 0;
}
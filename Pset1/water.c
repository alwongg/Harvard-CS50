#include <stdio.h>
#include <cs50.h>

int main(void){

    // prompt and validate user input

    int n = get_int("Minutes: ");

    // calculate equivalent bottles

    int total = n * 12;

    // print equivalent bottles

    printf("Bottles: %i \n", total);

}


//Janeth Meraz
//lab 2
//part 1

#include<stdio.h>

int main (void)
{
    int total_cents, remainder, dollars, quarters, dimes, nickels, pennies;
    char name [20];
    int id;

    //Prompty and read in user's name and id number
    printf("Enter your name: \n");
    scanf("%s", name);
    printf("Enter your id number: \n");
    scanf("%d", &id);

    //Greet the user
    printf("Hi, %s!\n", name);

    printf( "Enter the total number of cents: \n");
    scanf("%d", &total_cents);
    //test for negative/positive number b/c you cant have negative money(one part in if and one part in the else)

    while (total_cents <= 0) {
        printf ("Error, an invalid amount was entered. Only positive and greater than zero values allowed. \n");
        printf("Enter the total number of cents: \n");
        scanf("%d", &total_cents);
    }

    dollars = total_cents / 100;
    remainder = total_cents % 100;

    quarters = remainder / 25;
    remainder = remainder % 25;

    dimes = remainder / 10;
    remainder = remainder % 10;

    nickels = remainder / 5;
    remainder = remainder % 5;

    pennies = remainder;

    //Display results
    printf("For the money you have, %d, the breakdown is: \n", total_cents);
    printf("Dollars: %d\n", dollars);
    printf("Quarters: %d\n", quarters);
    printf("Dimes : %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", pennies);


    return 0;
}

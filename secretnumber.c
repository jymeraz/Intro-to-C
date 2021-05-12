

#include <stdio.h>

int main ()
{
    int secret_number = 61;
    int guess;

    printf("Guess what number I'm thinking of!\n");

    scanf("%d", &guess);

    while (guess != secret_number)
    {
    if (guess < secret_number)
        {
        printf("Too low!\n");
        }
    else
        {
        printf("Too high!\n");
        }

    printf("Sorry, try again!\n");
    scanf("%d", &guess);

    }

    printf("You got it!");



    return 0;
}

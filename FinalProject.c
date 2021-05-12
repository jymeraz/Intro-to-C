/*

This program facilitates the experience of looking for a movie to rent for the user.
It reads from a file in my computer filled with 50 movies.
Each movie has respective information such as a string title, a floating cost, an integer release date, a string genre, and an integer rating.
The progrma then begins by asking the user whether they want to rent a movie or not, if the answer is in confirmation, then the program continues and if not, it presents a goodbye and closes.
The user then has the option to view the movies in respect to their information, so a question is asked whether they would like to see all the movies, the movies based on cost, release date, genre,and rating.
If the user responds yes to one of the questions, then the program begins that branch, which is unique to each respective information.
If the user responnds no, then the program will ask the following question until the user types a yes or it will close and display a goodbye message if all responses were no.
For the first question, all movies will be displayed.
For the second question, more questions will be asked (some of which use functions) whether the user wants to see the movie that costs the most, the least, movies above and below the average price, along with a user inputted range.
For the third question, more questions will be asked (some of which use functions) whether the user wants to see the oldest movie, the most recent movie, along with a date range inputted by the user.
For the fourth question, the user can pick which genre of movies they want to watch and the program will display the movies of that genre.
For the fifth question, more questions will be asked whether the user wants to see the lowest rated movies and the highest rated movies along with a rating range inputted by the user.
Once a user inputs a movie number, a while loop woll execute and ask them whether the movie inputted is the correct movie and if it not, they will have the opportunity to input another movie number.
Once the user confirms that the inputted movie is correct, they will be given their total cost for the movie and the program will close.


*/

#include <stdio.h>
#include <string.h>
#define MAXMOVIES 50
//#include <stdbool.h>


int findRecent (int relDates [ ], int n)  //used to find the youngest movie
{
    int indexRecent = 0;
    int i;
    for (i = 0; i < n; i ++)
    {
        if (relDates [i] > relDates [indexRecent])
        {
            indexRecent = i;
        }
    }

    return indexRecent;  //return index to print out relevant info in main
}

int findOldest (int relDates [ ], int n)   //used to found the oldest movie
{
    int indexOldest = 0;
    int i;
    for (i = 0; i < n; i ++)
    {
        if (relDates [i] < relDates [indexOldest])
        {
            indexOldest = i;
        }
    }

    return indexOldest;   //return index to print out relevant info in main
}

int findCheap (float cos [ ], int n)  //used to find the cheapest movie
{
    int indexCheap = 0;
    int i;
    for (i = 0; i < n; i ++)
    {
        if (cos [i] < cos [indexCheap])
        {
            indexCheap = i;
        }
    }

    return indexCheap;   //return index to print out relevant info in main
}

int findExpensive (float cos [ ], int n)  //used to find the most expensive movie
{
    int indexExpensive = 0;
    int i;
    for (i = 0; i < n; i ++)
    {
        if (cos [i] > cos [indexExpensive])
        {
            indexExpensive = i;
        }
    }

    return indexExpensive;   //return index to print out relevant info in main
}

float avgCost (float cos [ ], int n)  //used to find the average cost of the movies
{
    float avCo;
    float sum = 0;  //initialize to zero
    float avg;
    int i;

    for (i = 0; i < n; i++)
    {
        sum = sum + cos [i];
    }

    avCo = sum / n;

    return avCo;  //return float value of average
}


int main( )
{
    //int movieNmbr;

    int userAnsr = 0;
    FILE* inFile = NULL;
    int i;

    char titles [MAXMOVIES][30];
    float costs [MAXMOVIES];
    int releaseDates [MAXMOVIES];
    char genres [MAXMOVIES][30];
    int ratings [MAXMOVIES];

    printf("Opening file \n\n" );
    inFile = fopen("/Users/boo/Documents/movies.txt", "r");

    if (inFile == NULL)
    {
        printf("Could not open file myfile.txt.\n");   //error message
        return -1;
    }

    int mainUserAnsr;
    int movieNmbr;
    int userInput;

    while (!feof(inFile))          //initializes the data into the arrays
    {
        fgets(titles[i], 30, inFile);
        //printf("%s", titles[i]);       //printed them to make sure that they are saved correctly

        fscanf(inFile, "%f ", &costs[i]);
        //printf("$%.2f\n", costs[i]);

        fscanf(inFile, "%d ", &releaseDates[i]);
        //printf("%d\n", releaseDates[i]);

        fgets(genres[i], 30, inFile);
        //printf("%s", genres[i]);

        fscanf(inFile, "%d ", &ratings[i]);
        //printf("%d\n", ratings[i]);

        //printf("\n");

        //printf("%d\n", i);

        i = i + 1;
    }

    printf("Hello! Would you like to rent out a movie today? Type 1 for yes and 0 for no\n");  //Greeting message and prompts the user to input a value
    scanf("%d", &mainUserAnsr);

    if (mainUserAnsr)    //tests answer of user
    {
        printf("Remember, you may rent out only one movie per visit!\n");
        printf("There are many ways to browse the movies\n You can see them all at once, \n by genre, \n by cost, \n by release date,\n or by a rating out of five stars!\n");

        printf("Would you like to see all the movies at once?\n Type 1 for yes and 0 for no\n");   //prompts the user to input a value
        scanf("%d", &userAnsr);
        if (userAnsr)
        {
            for (i = 0; i < MAXMOVIES; i ++)
            {

                printf("Movie Number: %d\n", i);
                //fgets(titles[i], 30, inFile);
                printf("Title: %s", titles[i]);

                //fscanf(inFile, "%f ", &costs[i]);
                printf("Cost: $%.2f\n", costs[i]);

                //fscanf(inFile, "%d ", &releaseDates[i]);
                printf("Release Date: %d\n", releaseDates[i]);

                //fgets(genres[i], 30, inFile);
                printf("Genre: %s", genres[i]);

                //fscanf(inFile, "%d ", &ratings[i]);
                printf("Rating: %d/5 \n", ratings[i]);

                printf("\n");
            }

            printf("Please type the movie number that you wish to rent out. \n");
            scanf("%d", &movieNmbr);

            printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
            scanf("%d", &userAnsr);

            while (!userAnsr)   //loop allows user to input movie again
            {
                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);
            }

            printf("Your total is $%.2f \n", costs[movieNmbr]);  //prints total and program closes

        }

        else //SEPARATING
        {

        printf("Would you like to see all the movies of a certain genre?\n Type 1 for yes and 0 for no\n");   //prompts the user to input a value
        scanf("%d", &userAnsr);
        if (userAnsr)
        {
            printf("The genres are Animation, Horror, Romance, Comedy, and Action.\n If you want to see Animation, type 1 \n If you want to see Horror, type 2\n If you want to see Romance, type 3\n If you want to see Comedy, type 4\n If you want to see Action, type 5\n");
            scanf("%d", &userInput);

            int c;
            if (userInput == 1)   //tests for animation
            {
                for(c = 0; c < 10; c++)
                    {
                        printf("Movie Number: %d\n", c);
                        printf("Title: %s", titles[c]);
                        printf("Cost: $%.2f\n", costs[c]);
                        printf("Release Date: %d\n", releaseDates[c]);
                        printf("Genre: %s", genres[c]);
                        printf("Rating: %d/5 \n", ratings[c]);
                        printf("\n");
                    }


                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr)  //while loop to allow for user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
                fclose(inFile);
            }

            else if (userInput == 2)   //tests for horror
            {
                int c;
                for(c = 10; c < 20; c++)
                {
                    printf("Movie Number: %d\n", c);
                    printf("Title: %s", titles[c]);
                    printf("Cost: $%.2f\n", costs[c]);
                    printf("Release Date: %d\n", releaseDates[c]);
                    printf("Genre: %s", genres[c]);
                    printf("Rating: %d/5 \n", ratings[c]);
                    printf("\n");
                }

                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr)   //while loop to allow for user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
                fclose(inFile);
            }

            else if (userInput == 3) //tests for romance
            {
                int c;
                for(c = 20; c < 30; c++)
                {
                    printf("Movie Number: %d\n", c);
                    printf("Title: %s", titles[c]);
                    printf("Cost: $%.2f\n", costs[c]);
                    printf("Release Date: %d\n", releaseDates[c]);
                    printf("Genre: %s", genres[c]);
                    printf("Rating: %d/5 \n", ratings[c]);
                    printf("\n");
                }

                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr)   //while loop to allow for user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
                fclose(inFile);
            }

            else if (userInput == 4)  //tests for comedy
            {
                int c;
                for(c = 30; c < 40; c++)
                {
                    printf("Movie Number: %d\n", c);
                    printf("Title: %s", titles[c]);
                    printf("Cost: $%.2f\n", costs[c]);
                    printf("Release Date: %d\n", releaseDates[c]);
                    printf("Genre: %s", genres[c]);
                    printf("Rating: %d/5 \n", ratings[c]);
                    printf("\n");
                }

                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr)   //while loop to allow for user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
                fclose(inFile);
            }

            else if (userInput == 5)    //tests for action
            {
                int c;
                for(c = 40; c < 50; c++)
                {
                    printf("Movie Number: %d\n", c);
                    printf("Title: %s", titles[c]);
                    printf("Cost: $%.2f\n", costs[c]);
                    printf("Release Date: %d\n", releaseDates[c]);
                    printf("Genre: %s", genres[c]);
                    printf("Rating: %d/5 \n", ratings[c]);
                    printf("\n");
                }

                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr) //while loop to allow for user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
            }

            else if (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5)
                {
                    printf("Invalid Input, must be a number 1-5\n");
                }

        }

        else //SEPARATING
        {

        printf("Would you like to see movies based on price range?\n Type 1 for yes and 0 for No\n"); //next question based on price
        scanf("%d", &userAnsr);

        if (userAnsr)
        {
            printf("Would you like to see movies below the average price?\n Type 1 for yes and 0 for No\n");
            scanf("%d", &userAnsr);

            if (userAnsr)
            {
                int q = sizeof(costs) / sizeof(costs[0]); //computes variable size
                float averageCost = avgCost (costs, q);  //calls to the funtion

                printf("The average cost of the books is $%.2f\n", averageCost);
                printf("The movies that cost less than the average cost are: \n");

                for (i = 0; i < MAXMOVIES; i ++)  //iteration to find movies below average cost
                {
                    if (costs [i] < averageCost)
                    {
                        printf("Movie Number: %d \n %s with a cost of $%.2f \n \n", i, titles[i], costs[i]);
                    }
                }
            }


            printf("Would you like to see movies above the average price?\n Type 1 for yes and 0 for No\n");
            scanf("%d", &userAnsr);

            if (userAnsr)
            {
                int q = sizeof(costs) / sizeof(costs[0]);  //computes variable size
                float averageCost = avgCost (costs, q); //calls to the funtion

                printf("The average cost of the books is $%.2f\n", averageCost);
                printf("The movies that cost more than the average cost are: \n");

                for (i = 0; i < MAXMOVIES; i ++)  //iteration to find movies above average cost
                {
                    if (costs [i] > averageCost)
                    {
                        printf("Movie number: %d\n %s with a cost of $%.2f \n\n", i, titles[i], costs[i]);
                    }
                }
            }

            printf("Would you like to see the most expensive movie?\n Type 1 for yes and 0 for No\n");
            scanf("%d", &userAnsr);

            if (userAnsr)
            {
                int k = sizeof(costs) / sizeof(costs[0]);  //computes variable size
                int indexOfExpensive = findExpensive (costs, k);  //calls to the funtion

                printf("Movie number: %d \n The most expensive movie is %s with cost $%.2f\n", indexOfExpensive, titles[indexOfExpensive], costs[indexOfExpensive]);
                printf("\n");
            }

            else
            {
                printf("\n");
            }

            printf("Would you like to see the least expensive movie?\n Type 1 for yes and 0 for No\n");
            scanf("%d", &userAnsr);

            if (userAnsr)
            {
                int l = sizeof(costs) / sizeof(costs[0]);  //computes variable size
                int indexOfCheap = findCheap (costs, l);  //calls to the funtion

                printf("Movie number: %d \n The least expensive movie is %s with cost $%.2f\n", indexOfCheap, titles[indexOfCheap], costs[indexOfCheap]);
                printf("\n");
            }

            int userAnsr2;
            printf("Would you like to input parameters to show movies within a certain cost range?\n Type 1 for yes and 0 for No\n");
            scanf("%d", &userAnsr2);

            if (userAnsr2)
            {
                float userLowCost;
                float userHighCost;

                printf("Input a lower boundary cost in decimal form with two decimal places to view all books that cost more\n");  //lower boundary input
                scanf("%f", &userLowCost);

                printf("Input an upper boundary cost in decimal form with two decimal places to view all books that cost less\n");  //upper boundary input
                scanf("%f", &userHighCost);

                printf("The movies between your cost boundaries are:\n");

                for (i = 0; i < MAXMOVIES; i ++)  //iteration to find movies within boundary
                {
                    if (costs [i] > userLowCost && costs [i] < userHighCost)
                    {
                        printf("Movie number: %d \n %s with a cost of $%.2f \n\n", i, titles[i], costs[i]);
                    }
                }

                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr)  //while loop to allow user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
                fclose(inFile);
            }
        }

        else  //SEPARATING
        {
            printf("Would you like to see movies by a certain release date?\n Type 1 for yes and 0 for No\n");  //next question
            scanf("%d", &userAnsr);

            if (userAnsr)
            {
                printf("Would you like to see the oldest movie?\n Type 1 for yes and 0 for No\n");
                scanf("%d", &userAnsr);

                if (userAnsr)
                {
                    int k = sizeof(releaseDates) / sizeof(releaseDates[0]);  //computes variable size
                    int indexOfOldest = findOldest (releaseDates, k);  //calls to the funtion

                    printf("Movie number: %d \n The oldest movie is %s with a release date of %d and cost $%.2f\n", indexOfOldest, titles[indexOfOldest], releaseDates[indexOfOldest], costs[indexOfOldest]);
                    printf("\n");
                }

                else
                {
                    printf("\n");
                }

                printf("Would you like to see the most recent movie?\n Type 1 for yes and 0 for No\n");
                scanf("%d", &userAnsr);

                if (userAnsr)
                {
                    int l = sizeof(releaseDates) / sizeof(releaseDates[0]);  //computes variable size
                    int indexOfRecent = findRecent (releaseDates, l);  //calls to the funtion

                    printf("Movie number: %d \n The most recent movie is %s with a release date of %d and cost $%.2f\n", indexOfRecent, titles[indexOfRecent], releaseDates[indexOfRecent], costs[indexOfRecent]);
                    printf("\n");
                }

                else
                {
                    printf("\n");
                }

                printf("Would you like to input parameters to show movies within a certain  release date range?\n Type 1 for yes and 0 for No\n");
                scanf("%d", &userAnsr);

                if (userAnsr)
                {
                    int userLowDate;
                    int userHighDate;

                    printf("Input a lower boundary date to view all books that are older\n"); //lower boundary
                    scanf("%d", &userLowDate);

                    printf("Input an upper boundary date to view all books that are more recent\n"); //upper boundary
                    scanf("%d", &userHighDate);

                    printf("The movies between your release date boundaries are:\n");

                    for (i = 0; i < 50; i ++)  //iteration to find movies within boundary
                    {
                        if (releaseDates [i] > userLowDate && releaseDates [i] < userHighDate)
                        {
                            printf("Movie number: %d \n %s with a release date of %d and cost of $%.2f \n\n", i, titles[i], releaseDates[i], costs[i]);
                        }
                    }

                }
                else
                {
                    printf("\n");
                }

                printf("Please type the movie number that you wish to rent out. \n");
                scanf("%d", &movieNmbr);

                printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                scanf("%d", &userAnsr);

                while (!userAnsr)  //while loop to allow user error
                {
                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);
                }

                printf("Your total is $%.2f \n", costs[movieNmbr]);
                fclose(inFile);
            }

            else
            {
                printf("Would you like to see movies by a certain rating out of five stars?\n Type 1 for yes and 0 for No\n");  //next question
                scanf("%d", &userAnsr);

                if (userAnsr)
                {
                    printf("Would you like to see the lowest rated movies?\n Type 1 for yes and 0 for No\n");
                    scanf("%d", &userAnsr);

                    if(userAnsr)
                    {
                        printf("The lowest rated movies are: \n");
                        for (i = 0; i < MAXMOVIES; i++)   //iteration to find lowest rated movies
                        {
                            if (ratings[i] < 2)
                            {
                                printf("Movie number: %d \n %s with a rating of %d and a cost of $%.2f\n\n", i, titles[i], ratings [i], costs[i]);
                            }
                        }

                    }

                    printf("Would you like to see the highest rated movies?\n Type 1 for yes and 0 for No\n");
                    scanf("%d", &userAnsr);

                    if(userAnsr)
                    {
                        printf("The highest rated movies are: \n");
                        for (i=0; i<MAXMOVIES; i++)       //iteration to find highest rated movies
                        {
                            if (ratings[i] > 4)
                            {
                                printf("Movie number: %d \n %s with a rating of %d and a cost of $%.2f\n\n", i, titles[i], ratings [i], costs[i]);
                            }
                        }
                    }

                    printf("Would you like to input parameters to show movies within a certain rating?\n Type 1 for yes and 0 for No\n");
                    scanf("%d", &userAnsr);

                    if (userAnsr)
                    {
                        int userLowRate;
                        int userHighRate;

                        printf("Input a lower boundary rating to view all books that are rated higher\n");  //lower ratings
                        scanf("%d", &userLowRate);

                        printf("Input an upper boundary rating to view all books that are rated lower\n");  //higher ratings
                        scanf("%d", &userHighRate);

                        printf("The movies between your release date boundaries are:\n");

                        for (i = 0; i < MAXMOVIES; i ++)
                        {
                            if (ratings [i] > userLowRate && ratings [i] < userHighRate)   //iteration to show movies within certainn ratings
                            {
                                printf("Movie number: %d \n %s with a rating of %d and cost of $%.2f \n\n", i, titles[i], ratings[i], costs[i]);
                            }
                        }
                    }

                    printf("Please type the movie number that you wish to rent out. \n");
                    scanf("%d", &movieNmbr);

                    printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                    scanf("%d", &userAnsr);

                    while (!userAnsr)  //while loop to allow user error
                    {
                        printf("Please type the movie number that you wish to rent out. \n");
                        scanf("%d", &movieNmbr);

                        printf("Is %s the movie you wish to rent out?\n Type 1 for Yes and 0 for No\n ", titles[movieNmbr]);
                        scanf("%d", &userAnsr);
                    }

                    printf("Your total is $%.2f \n", costs[movieNmbr]);
                    fclose(inFile);
                }
            }
        }

        }

        }

    }

    printf("\nThank you for renting with us! \n\n");  //goodbye message to user

    fclose(inFile);

    return 0;
}

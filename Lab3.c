

#include <stdio.h>
#include <string.h>


int findOldest (int pd [ ], int n)
{
    int indexOld = 0;
    int i;
    for (i = 0; i < n; i ++)
    {
        if (pd [i] < pd [indexOld])
        {
            indexOld = i;
        }
    }

    return indexOld;
}

float avgCost (float cos [ ], int n)
{
    float avCo;
    float sum = 0;
    float avg;
    int i;

    for (i = 0; i < n; i++)
    {   sum = sum + cos [i];

    }

    avCo = sum / n;

    return avCo;
}

#define MAX 30
void sortTitles (char ti [ ] [MAX], int n)
{
    char temp[MAX];
    for (int j = 0; j < n - 1; j++)
    {
       for (int i = j + 1; i < n; i++)
       {
           if (strcmp(ti[j], ti[i]) > 0)
           {
               strcpy(temp, ti[j]);
               strcpy(ti[j], ti[i]);
               strcpy(ti[i], temp);
           }
       }
    }
}

int main (void)
{
    FILE* inFile = NULL;
    int singleNum;
    int numItemsRead;

    char titles [5][30];
    char authors [5][30];
    int pubDates [5];
    char isbns [5][30];
    float costs [5];
    int i;              //loop control variable
    int indexOfOldest;
    float averageCost;

    printf("Opening file \n\n" );
    inFile = fopen("/Users/boo/Documents/lab2/books.txt", "r");

    if (inFile == NULL) {
        printf("Could not open file myfile.txt.\n");
        return -1;
    }

    while (!feof(inFile))
    {
        fgets(titles[i], 30, inFile);
        printf("%s", titles[i]);

        fgets(authors[i], 30, inFile);
        printf("%s", authors[i]);

        fscanf(inFile, "%d ", &pubDates[i]);
        printf("%d\n", pubDates[i]);

        fgets(isbns[i], 30, inFile);
        printf("%s", isbns[i]);

        fscanf(inFile, "%f ", &costs[i]);
        printf("$%.2f\n", costs[i]);

        printf("\n");

        i = i + 1;
    }

    int k = sizeof(pubDates) / sizeof(pubDates[0]);

    indexOfOldest = findOldest (pubDates, k);
    printf("The oldest book is %s with date %d\n", titles[indexOfOldest], pubDates[indexOfOldest]);

    printf("\n");

    int q = sizeof(costs) / sizeof(costs[0]);

    averageCost = avgCost (costs, q);
    printf("The average cost of the books is $%.2f\n", averageCost);


    printf("The books that cost more that the average are written by: \n");
    for (i = 0; i < 5; i ++)
    {   if (costs [i] > averageCost)
        {
            printf("%s with a cost of $%.2f \n", authors[i], costs[i]);
        }
    }

    printf("\n");

    int l = sizeof(titles) / sizeof(titles[0]);

    printf("Given Title order is:\n");
    for (int i = 0; i < l; i++)
    {
        printf("Title %d is: %s", i + 1, titles[i]);
    }
    printf("\n");

    sortTitles (titles, l);
    printf("Titles in alphabetical order are: \n");
    for (int i = 0; i < l; i++)
    {
        printf("Title %d is: %s", i + 1, titles[i]);
    }
    printf("\n");


    return 0;
}

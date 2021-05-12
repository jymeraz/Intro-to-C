

#include <stdio.h>
#include <string.h>
#define MAXSIZE 50

typedef struct exoplanet  //5 planets
{
    char name [MAXSIZE];
    int distance;
    float esi;
} exop;

int findClosest (exop arr[ ], int size)
{
    int i;
    int indexOfClosest = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i].distance < arr[indexOfClosest].distance)
        {
           indexOfClosest = i;
        }

    }
    return indexOfClosest;
}

void sortDistances (exop arr[ ], int size)
{
    int i;
    int j;
    exop temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i].distance > arr[j].distance)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main( )
{
    FILE* inFile = NULL;
    exop arr[5];

    printf("Opening file \n\n" );
    inFile = fopen("/Users/boo/Documents/exoplanets.txt", "r");

    if (inFile == NULL)
    {
        printf("Could not open file exoplanets.txt.\n");
        return -1;
    }
/*
    //create an exoplanet structure
    exo ep1;
    strcpy(ep1.name, "KRyan4");
    ep1.distance = 27;
    ep1.esi = 0.5;

    printf("The name is: %s and distance is: %d\n\n", ep1.name, ep1.distance);
*/

    int i = 0;
    while (!feof(inFile))
    {   //These are for books
        fgets(arr[i].name, MAXSIZE, inFile);
        fscanf(inFile, "%d ", &arr[i].distance);
        fscanf(inFile, "%f ", &arr[i].esi);

        i++;
    }

    int arrSz = 5;   //to print everything out and make sure the info is in the right place

    printf("The exoplanets in the order they are in the text file is: \n\n");

    for (i = 0; i < arrSz; i++)
    {
        printf("%s", arr[i].name);
        printf("%d light years\n", arr[i].distance);
        printf("ESI: %.2f\n", arr[i].esi);
        printf("\n");
    }


int indexOfClosest = findClosest(arr, arrSz);

printf("The closest exoplanet is: %s", arr[indexOfClosest].name);
printf("It is %d light years away and has an ESI of %.2f\n\n", arr[indexOfClosest].distance, arr[indexOfClosest].esi);

sortDistances (arr, arrSz);

printf("The exoplanets and their respective information in order of closest to farthest distance away from earth are as follows: \n\n");

for (i = 0; i < arrSz; i++)
    {
        printf("%s", arr[i].name);
        printf("%d light years\n", arr[i].distance);
        printf("ESI: %.2f\n", arr[i].esi);
        printf("\n");
    }

    return 0;
}

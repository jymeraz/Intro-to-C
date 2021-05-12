
//lab 2
//part 2
//version 3



#include <stdio.h>
#include <string.h>

int main(void) {
    FILE * inFile = NULL;   // File pointer
    char title [30];
    char author [20];
    char ISBNnumber[15];
    char userISBN[37];
    int date;
    float cost;

   // Open file
   printf("Opening file books.txt.\n\n");
   inFile = fopen("/Users/boo/Documents/lab2/books.txt", "r");

  if (inFile == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1; // -1 indicates error
   }


    printf("Type in the ISBN of the book you wat to see the information for. \n");


    fgets(userISBN, 37, stdin);

    while (!feof(inFile)) {
        fgets(title, 30, inFile);
        fgets(author, 20, inFile);
        fscanf(inFile, "%d", &date);
        fgets(ISBNnum, 15, inFile);
        fscanf(inFile, "%f", &cost);
    }
    if (strcmp(ISBNnumber, userISBN) == 0) {  //==0 means a true expressionn
        printf("\nThe title is: %s \n", title);
        printf("The author is: %s\n", author);
        printf("The date of publishing is: %d\n", date);
        printf("The ISBN number is: %s\n", ISBNnumber);
        printf("The cost is: %.2f\n", cost);
        }

    printf("invalid input, no such book in the inventory");
    printf("\nClosing file books.txt.\n");

    // Done with file, so close it
    fclose(inFile);

    return 0;
}

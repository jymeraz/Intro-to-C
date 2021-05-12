
//lab 2
//part 2
//version 1



#include <stdio.h>

int main(void) {
    FILE * inFile = NULL;   // File pointer
    char title[40];         // Data value from file
    char author[20];
    int ISBN[12];
    int date[12];
    float price[6];
    int numBooks;
    int printBooks;

   // Open file
   printf("Opening file books.txt.\n\n");
   inFile = fopen("/Users/boo/Documents/lab2/books.txt", "r");

  if (inFile == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1; // -1 indicates error
   }

    printf("How many books do you want to see?\n");
    scanf("%d", &numBooks);


    while (numBooks > 5 || numBooks < 1) {
        printf("Invalid amout, must be between 1 and 5. \nHow many books do you want to see?\n");
        scanf("%d", &numBooks);
    }

    int i = 0;
    printBooks = numBooks * 6;

   for(i = 0; i < printBooks; i++) {
        fgets(title, 37, inFile);
        printf("%s", title);
   }

   /* for (i = 0; i < numBooks; i++) {
        fgets(title, 40, inFile);
        printf("Title: %s", title);
        fgets(author, 20, inFile);
        printf("Author: %s", author);
        fgets(date, 12, inFile);
        printf("Date of Publication: %s", date);
        fgets(ISBN, 12, inFile);
        printf("ISBN: %s", ISBN);
        fgets(price, 6, inFile);
        printf("Price: $%s", price);
        printf("\n");
    } */


   printf("\nClosing file books.txt.\n");

   // Done with file, so close it
   fclose(inFile);

   return 0;
}

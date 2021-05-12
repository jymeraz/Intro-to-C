
//Janeth Meraz
//lab 2
//part 2
//version 2


#include <stdio.h>

int main(void) {
    FILE * inFile = NULL;   // File pointer
    char title[37];         // Data value from file
    int numBooks = 0;
    int printBooks = 0;

   // Open file
   printf("Opening file books.txt.\n\n");
   inFile = fopen("/Users/boo/Documents/lab2/books.txt", "r");

  if (inFile == NULL) {
      printf("Could not open file books.txt.\n");
      return -1; // -1 indicates error
   }

    printf("Here are all the books: \n\n");


   while(!feof(inFile)) {
        fgets(title, 37, inFile);
        printf("%s", title);
   }


   printf("\nClosing file books.txt.\n");

   // Done with file, so close it
   fclose(inFile);

   return 0;
}

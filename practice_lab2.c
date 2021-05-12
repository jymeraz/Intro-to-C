#include <stdio.h>

int main(void) {
   FILE* inFile = NULL;   // File pointer
   int singleNum;         // Data value from file
   int numItemsRead;      // Number of data values read in by fscanf

   // Open file
   printf("Opening file myfile.txt.\n");
   inFile = fopen("/Users/boo/Documents/CSmyfile/myfile.txt", "r");

   if (inFile == NULL) {
      printf("Could not open file myfile.txt.\n");
      return -1; // -1 indicates error
   }

   // Print out numbers read in
   printf("Reading and printing numbers.\n");

   while (!feof(inFile)) {
      numItemsRead = fscanf(inFile, "%d", &singleNum);
      if ( numItemsRead == 1 ) {
         printf("num: %d\n", singleNum);
      }
   }

   printf("Closing file myfile.txt.\n");

   // Done with file, so close it
   fclose(inFile);

   return 0;
}

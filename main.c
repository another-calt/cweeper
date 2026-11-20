#include "calt.h"
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

program {
   FILE *fileptr = fopen(".gitignore", "r");
   char gitignoreBuffer[BUFFER_SIZE] = {0};
   var killcount = 0;

   if (fileptr == NULL) {
      println("No .gitignore found in directory");
      return 1;
   }

   while (fgets(gitignoreBuffer, BUFFER_SIZE, fileptr) != NULL) {
      killcount++;
   }

   char hitlist[BUFFER_SIZE][killcount];
   memset(hitlist, 0, BUFFER_SIZE * killcount * sizeof(char));

   i32 l = 0;
   while (fgets(gitignoreBuffer, sizeof(gitignoreBuffer), fileptr) != NULL) {
      for (var i = 0; i < 50; i++) {
         hitlist[l][i] = gitignoreBuffer[i];
      }
      l++;
   }

   fclose(fileptr);
   free(fileptr);

   return 0;



}
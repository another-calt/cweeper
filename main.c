#include "calt.h"
#include <string.h>

#define BUFFER_SIZE 30

app {

   // variables
   FILE *fileptr = {0};
   char buffer[BUFFER_SIZE] = {0};
   char cmd[BUFFER_SIZE+9];

   // read top level .gitignore (if there is one)
   if ((fileptr = fopen(".gitignore", "r")) == NULL) {
      printf("EXIT: No '.gitignore' found in folder.");
      return -1;
   }
   while (fgets(buffer, BUFFER_SIZE, fileptr) != NULL) { // buffer = row in .gitignore
      if (strcmp(buffer, ".\n") != 0
         && strcmp(buffer, "..\n") != 0 
         && strcmp(buffer, ".gitignore\n") != 0
         && strcmp(buffer, ".git/\n") != 0
      ) {
         strstr(buffer, "/") != NULL ? strcat(cmd, "rm -r ") : strcat(cmd, "rm ");
         strcat(cmd, buffer);
         system(cmd);
         strcpy(cmd, "");
      }
   }
   fclose(fileptr);
   println("Clean");
   return 0;
}
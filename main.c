#include "calt.h"
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

$Vector(str)

app {

   // variables
   FILE *fileptr = {0};
   char buffer[BUFFER_SIZE] = {0};
   vector_str rules_global = {0};
   vector_str allows_global = {0};
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
         strcat(cmd, "find ");
         strcat(cmd, buffer);
         system(cmd);
         strcpy(cmd, "");
         
      }
   }
   fclose(fileptr);

   println("Clean");
   
   return 0;
}
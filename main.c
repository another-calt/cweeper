#include "calt.h"


#include <string.h>
#include <stdlib.h>


#define BUFFER_SIZE 50

program {
   
   var *fileptr = fopen(".gitignore", "r");
   if (fileptr == NULL) {
      println("No '.gitignore' file found in directory.");
      return 1;
   }

   char target[BUFFER_SIZE];
   while (fgets(target, BUFFER_SIZE, fileptr) != NULL) {

      if (target[0] == "!") {
         continue;
      }
      println(target);
      char rm[100] = "rm ";
      strcat(rm, target);
      println(rm);

      system(rm);

   }
   fclose(fileptr);
   println("Clean");




















   return 0;
}
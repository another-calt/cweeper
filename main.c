#include "calt.h"


#include <stddef.h>
#include <string.h>
#include <stdlib.h>


#define BUFFER_SIZE 50




$Vector(i32);

program {

   vector_T a = {0};
   
   str rules = "";
   str allows = "";


   var *fileptr = fopen(".gitignore", "r");
   if (fileptr == NULL) {
      println("No '.gitignore' file found in directory.");
      return 1;
   }

   char target[BUFFER_SIZE];
   
   fclose(fileptr);
   println("Clean");




















   return 0;
}
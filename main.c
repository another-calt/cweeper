#include "calt.h"
#include <string.h>

#define BUFFER_SIZE 30

typedef struct {                                                                                                         \
   size_t size;                                                                                                         \
   size_t max;                                                                                                          \
   str *list;                                                                                                                      \
} vector_str; 

/// ill test this later
static inline void vappend_str
      (vector_str *vec, str value)
{                        
   if (vec->size >= vec->max) {                                                                
      if (vec->max == 0) vec->max = 4;                                                                                             \
      else vec->max *= 2;                                                                                  
      vec->list = realloc(vec->list, vec->max * sizeof(str));                                      
   }                                                                                                                                 
   strcpy(vec->list[vec->size], value);
   vec->size++;
}

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

/*
enter directory
search for rules
   if applicable, create new rules applying to current scope*
for each file
   if in hitlist & !in allowlist
      kill
add to tree

this all irks me as a very object - oriented problem*
sunk cost says i can bs through it with functions and macros
but logic says to just use c++
*/
#include "calt.h"
#include <stdlib.h>
#include <string.h>



#define BUFFER_SIZE 50



$Vector(str)

typedef struct {
   str scope;
   vector_str focus;
} rule;

$Vector(rule)


app {

   // variables
   FILE *fileptr = {0};
   FILE *shptr = {0};
   char buffer[BUFFER_SIZE] = {0};
   char buffer2[BUFFER_SIZE] = {0};
   vector_str rules_global = {0};
   vector_str allows_global = {0};
   char killlist[20];



   // read top level .gitignore (if there is one)
   if ((fileptr = fopen(".gitignore", "r")) == NULL) {
      printf("EXIT: No '.gitignore' found in folder.");
      return -1;
   }
   while (fgets(buffer, BUFFER_SIZE, fileptr) != NULL) {
      if (buffer[0] == '!') vappend_str(&allows_global, buffer);
      else vappend_str(&rules_global, buffer);
   }
   fclose(fileptr);

   // assign project root
   /*
            | ditched recursion |
   */
   // fileptr = popen("pwd", "r");
   // if (fileptr == NULL) {
   //    printf("ERROR: printed unemployed directory");
   //    return -1;
   // }
   // projectRoot = fgets(buffer, BUFFER_SIZE, fileptr);
   // pclose(fileptr);

   fileptr = popen("ls -a", "r");
   if (fileptr == NULL) {
      println("oh no");
      return -1;
   }
   while (fgets(buffer, BUFFER_SIZE, fileptr) != NULL) { // buffer contains file target
      if(strcmp(buffer, ".\n") != 0
         && strcmp(buffer, "..\n") != 0
         && strcmp(buffer, ".gitignore\n") != 0
         && strcmp(buffer, ".git\n") != 0
      ) {
         strcpy(killlist ,strcat("rm", buffer));
         system(killlist);
      }
   }
   pclose(fileptr);



   

   

   // delete process
   /*
   - scan everything in ./
   - is on hitlist & !allowed : rm
   - if folder, rm -r
   */
   println("Clean");
   
   return 0;
}
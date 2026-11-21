#include "calt.h"

#define BUFFER_SIZE 50

$Vector(str)

app {

   // variables
   FILE *fileptr = {0};
   char buffer[BUFFER_SIZE] = {0};
   vector_str rules_global = {0};
   vector_str allows_global = {0};
   str projectRoot;

   // read top level .gitignore (if there is one)
   if ((fileptr = fopen(".gitignore", "r")) == NULL) {
      println("EXIT: No '.gitignore' found in folder.");
      return -1;
   }
   while (fgets(buffer, BUFFER_SIZE, fileptr) != NULL) {
      if (buffer[0] == '!') vappend_str(&allows_global, buffer);
      else vappend_str(&rules_global, buffer);
   }
   fclose(fileptr);

   // assign project root
   if ((fileptr = popen("pwd", "r")) == NULL) {
      println("ERROR: printed unemployed directory");
      return -1;
   }
   pclose(fileptr);
   // delete process
   /*
   - scan everything in ./
   - i on hitlist & !allowed : rm
   - if folder, rm -rf
   */
   println("Clean");
   
   return 0;
}
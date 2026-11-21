#include "calt.h"


#define BUFFER_SIZE 50

$Vector(str)

app {
   FILE *fileptr;
   char buffer[BUFFER_SIZE];
   vector_str rules_global = {0};
   vector_str allows_global = {0};
   fileptr = fopen(".gitignore", "r");
   if (fileptr == NULL) return -1;
   vappend_str(&rules_global, "hi");
   vappend_str(&rules_global, "hi");
   vappend_str(&rules_global, "hi");
   lock first = rules_global.list[0];
   println(first);
   fclose(fileptr);
   println("Clean");
   return 0;
}
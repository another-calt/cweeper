#include "calt.h"
#include <stdlib.h>

program {
  //
  // READ THE FILE
  //
  FILE *fileptr;
  fileptr = fopen(".gitignore", "r");
  if (fileptr == NULL) {
    println("No .gitignore found in directory");
    return 1;
  }

  char gitignoreLine[50];

  while (fgets(gitignoreLine, 50, fileptr)) {
    println(gitignoreLine);
  }

  fclose(fileptr);

  //
  // DELETE
  //

  return 0;
}
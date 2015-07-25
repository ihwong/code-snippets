#include <stdio.h>
#include "stringTokenizer.h"

int main() {
  
  int i;
  char inputString[256];
  int count;
  char* delimiter = " ";
  char** tokenString = NULL;
  
  do { 
    printf("%% ");
    gets(inputString);
  } while (stInvalidString(inputString, delimiter) == 1);

  count = stCountTokens(inputString, delimiter);
  
  stTokenize(inputString, delimiter, &tokenString);
  
  for (i = 0; i < count; i++) {
    printf ("tokenString[%d]: %s\n", i, tokenString[i]);
  }
  
  stFreeTokens(inputString, delimiter, &tokenString);
  
  return 0;
  
}

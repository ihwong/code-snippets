#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringTokenizer.h"

/*
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
*/

// 동적 할당된 메모리를 free해 주는 부분
void stFreeTokens(char* inputString, char* delimiter, char*** tokenString) {

  int i;

  for (i = 0; i < stCountTokens(inputString, delimiter); i++)
    free((*tokenString)[i]);

  free(*tokenString);
  
}

// 공백 문자로만 된 문자열은 strtok 할 때 오류가 발생하기 때문에 예외처리
int stInvalidString(char* inputString, char* delimiter) {

  int i, j = 0;
  
  for (i = 0; i < strlen(inputString); i++)
    if (strchr(delimiter, inputString[i]) == NULL)
      j++;

  if (j == 0)
    return 1;
  else
    return 0;
  
}

int stCountTokens(char* inputString, char* delimiter) {
  
  char tempString[strlen(inputString)];
  char* tempPointer;
  int count = 0;
  
  strcpy(tempString, inputString); // 원본 string이 변경되는 것을 막기 위해 복사본으로 작업 진행
  
  tempPointer = strtok(tempString, delimiter);
  
  while (tempPointer != NULL) {
    tempPointer = strtok(NULL, delimiter);
    count++;
  }
  
  return count;
  
}

void stTokenize(char* inputString, char* delimiter, char*** tokenString) {
  
  int i;
  char tempString[strlen(inputString)];
  int count = stCountTokens(inputString, delimiter);
  char* tempPointer = NULL; // 각 토큰을 저장하는 데 임시로 사용되는 포인터 변수
  
  *tokenString = (char**) malloc(sizeof(char*) * (count + 1));
  
  strcpy(tempString, inputString); // strtok가 원본 string을 변화시키므로, 복사본으로 작업 진행
  
  tempPointer = strtok (tempString, delimiter);
  
  (*tokenString)[0] = (char*) malloc(sizeof(char) * (strlen(tempPointer) + 1));
  
  strcpy((*tokenString)[0], tempPointer);
  
  for (i = 1; i < count; i++) {
    
    tempPointer = strtok(NULL, delimiter);
    
    (*tokenString)[i] = (char*) malloc(sizeof(char) * (strlen(tempPointer) + 1));
    
    strcpy ((*tokenString)[i], tempPointer);
    
  }
}

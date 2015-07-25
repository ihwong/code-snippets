#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringTokenizer.h"

/* 공백 문자로만 된 문자열은 strtok 할 때 오류가 발생하기 때문에 예외처리
   inputString이 delimiter로만 이루어져 있으면 1, 그렇지 않으면 0을 반환 */
int stInvalidString(char* inputString, char* delimiter) {
  
  int i;
  
  for (i = 0; i < strlen(inputString); i++)
    /* inputString[i]가 delimiter들의 조합에 있는지 검색.
       만약 발견되지 않았다면(반환 값이 NULL이라면),
       inputString[i]는 delimiter 중 하나가 아님. */
    if (strchr(delimiter, inputString[i]) == NULL)
      return 0;
  
  return 1;
  
}

int stCountTokens(char* inputString, char* delimiter) {
  
  char tempString[strlen(inputString)];
  char* tempPointer;
  int count = 0;

  // 원본 string이 변경되는 것을 막기 위해 복사본으로 작업 진행
  strcpy(tempString, inputString);
  
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
  tempPointer = strtok(tempString, delimiter);
  
  (*tokenString)[0] = (char*) malloc(sizeof(char) * (strlen(tempPointer) + 1));
  strcpy((*tokenString)[0], tempPointer);
  
  for (i = 1; i < count; i++) {
    tempPointer = strtok(NULL, delimiter);
    (*tokenString)[i] = (char*) malloc(sizeof(char) * (strlen(tempPointer) + 1));
    strcpy ((*tokenString)[i], tempPointer);
  }
  
}

// 동적 할당된 메모리를 free해 주는 부분
void stFreeTokens(char* inputString, char* delimiter, char*** tokenString) {

  int i;
  int count = stCountTokens(inputString, delimiter);

  for (i = 0; i < count; i++)
    free((*tokenString)[i]);

  free(*tokenString);
  
}

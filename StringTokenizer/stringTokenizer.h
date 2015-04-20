#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

int stInvalidString(char* inputString, char* delimiter);
int stCountTokens(char* inputString, char* delimiter);
void stTokenize(char* inputString, char* delimiter, char*** tokenString);
void stFreeTokens(char* inputString, char* delimiter, char*** tokenString);

#endif

#include <stdio.h>
#include <stdlib.h>

int count (char* str);

int main () {

  char str[256];
  int total = 0;
  int temp;
  FILE* fp = fopen ("FileList.txt", "rt");

  while (fscanf (fp, "%s", str) != EOF) {
    temp = count (str);
    printf ("%s: %d\n", str, temp);
    total += temp;
  }

  printf ("total: %d\n", total);

  getchar ();

  fclose (fp);

  return 0;

}

int count (char* str) {
  
  char ch;
  int cnt = 0;
  FILE* fp = fopen (str, "rt");
  
  if (fp == NULL) {
    printf ("Error!\n");
    exit (1);
  }

  while (fscanf (fp, "%c", &ch) != EOF) {
    if (ch == '\n')
      cnt++;
  }

  cnt++; // 마지막 빈 줄까지 세기

  fclose (fp);

  return cnt;

}

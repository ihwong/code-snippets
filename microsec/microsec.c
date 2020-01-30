/*
  C programming - current time in microseconds
  $ ./microsec
  20:19:47.030744
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

// printt() requires <time.h>, <sys/time.h> and <stdio.h>
void printt(void);

int main(int argc, char *argv[]) {
  printt();
  return 0;
}

void printt(void) {
  
  struct timeval tv;
  struct tm *lt;
  time_t t = gettimeofday(&tv, NULL);
  lt = localtime(&tv.tv_sec);
  
  if (t == -1 || lt == NULL) {
    printf("CURRENT TIME UNKNOWN ");
    return;
  }
  
  printf("%02d:%02d:%02d.%06ld", lt->tm_hour, lt->tm_min, lt->tm_sec, tv.tv_usec);
  return;
  
}

#include <stdio.h> // for printf()
#include <unistd.h> // for sleep()
#include <sys/time.h> // for timeval and gettimeofday()

int main(int argc, char *argv[]) {

  struct timeval bef, aft;

  gettimeofday(&bef, NULL);
  sleep(1);
  gettimeofday(&aft, NULL);

  printf("ElapsedTime = %ld us\n", (aft.tv_sec * 1000000 + aft.tv_usec) - (bef.tv_sec * 1000000 + bef.tv_usec));

  return 0;
  
}

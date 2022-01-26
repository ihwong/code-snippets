#include <stdio.h> // for printf()
#include <unistd.h> // for sleep()
#include <time.h> // for struct timespec, clock_gettime() and CLOCK_MONOTONIC

int main(int argc, char *argv[]) {

    struct timespec bef, aft;

    clock_gettime(CLOCK_MONOTONIC, &bef);
    sleep(1);
    clock_gettime(CLOCK_MONOTONIC, &aft);

    printf("ElapsedTime = %ld ns\n", (aft.tv_sec * 1000000000 + aft.tv_nsec) - (bef.tv_sec * 1000000000 + bef.tv_nsec));
 
    return 0;

}

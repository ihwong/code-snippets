#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  
  char ans[5];
  char guess[5];

  /* counting the number of tries */
  int n = 1;
  
  /* variables for 'for' loops */
  int i, j;

  int k;
  int strike, ball;
 
  srand(time(NULL));
 
  // generating 4-digit answer (each digit should be different with the others)
  for (i = 0; i < 4; i++) {
    do {
      ans[i] = 48 + (i == 0) + rand() % (10 - (i == 0)); // first digit: 1~9, other digits: 0~9
      k = 0;
      for (j = 0; j < i; j++)
        k += (ans[i] == ans[j]);
    } while (k);
  }
 
  // 이 부분은 입력받은 추측이 '각 자리 수가 서로 다른 네 자리 자연수'인지 확인한다.
  // 첫 자리 수가 0이 아니도록 확인해야 한다.
  // 네 자리 수
  // 각 자리는 모두 달라야
  for (n = 1;; n++) {
    
    printf("%d-th guess: ", n);
    scanf("%s", guess);
    
    k = 0;

    k += (strchr("123456789", guess[0]) == NULL);
    
    for (i = 1; i < 4; i++) {
      k += (strchr("0123456789", guess[i]) == NULL);
      for (j = 0; j < i; j++)
        k += (guess[i] == guess[j]);
    }
 
    if (k != 0) {
      printf("Invalid input\n");
      n -= 1;
      continue;
    }
 
    // 이 부분은 입력된 추측을 답과 비교하여 볼과 스트라이크를 출력한다.
    strike = 0;
    ball = 0;
 
    for (i = 0; i < 4; i++) {
      strike += (ans[i] == guess[i]);
      for (j = 0; j < 4; j++)
        if (i != j)
          ball += (ans[i] == guess[j]);
    }
 
    printf("%d-strike %d-ball\n\n", strike, ball);
 
    // 추측과 답안이 일치하는 경우 답을 출력하고 프로그램을 종료한다.
    if (strcmp(ans, guess) == 0) {
      printf("%d번의 시도 끝에 정답을 찾아냈습니다: %s\n", n, ans);
      
      return 0;
    }
  }
}

#include <stdio.h>
#include <stdlib.h> // rand() 함수를 위해
#include <time.h>
#include <string.h> // strcmp 함수를 위해
 
int main() {
  char ans[5] = "0000", guess[5]; // ans 를 초기화시켜 ans[4]='\0' 이 되도록 한다.
  int n = 1, i, j, k, strike, ball;
 
  srand(time(NULL));
 
  // 이 부분은 답으로 쓰일 '각 자리 수가 서로 다른 네 자리 자연수'를 생성한다.
  for (i = 0; i < 4; i++) {
    do {
      ans[i] = 48 + (i == 0) + rand() % (10 - (i == 0)); // 맨 첫 자리인 경우 1~9 이고 그 이외의 경우 0~9 가 되도록 수식을 구성함.
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
    printf("%d번째 시도: ", n);
    fflush(stdout);
    scanf("%s", guess);
    // 여기에서부터
    k = 0;
    if (((guess[0] == '1') || (guess[0] == '2') || (guess[0] == '3')
         || (guess[0] == '4') || (guess[0] == '5') || (guess[0] == '6')
         || (guess[0] == '7') || (guess[0] == '8') || (guess[0] == '9'))
        == 0)
      k += 1;
    for (i = 1; i < 4; i++) {
      if (((guess[i] == '0') || (guess[i] == '1') || (guess[i] == '2')
           || (guess[i] == '3') || (guess[i] == '4')
           || (guess[i] == '5') || (guess[i] == '6')
           || (guess[i] == '7') || (guess[i] == '8')
           || (guess[i] == '9')) == 0)
        k += 1;
      for (j = 0; j < i; j++)
        k += (guess[i] == guess[j]);
    }
 
    if (k != 0) {
      printf("잘못된 입력입니다.\n");
      fflush(stdout);
      n -= 1;
      continue;
    }
    // 여기까지 코드 정리해야 함
 
    // 이 부분은 입력된 추측을 답과 비교하여 볼과 스트라이크를 출력한다.
    strike = 0;
    ball = 0;
 
    for (i = 0; i < 4; i++) {
      strike += (ans[i] == guess[i]);
      for (j = 0; j < 4; j++)
        if (i != j)
          ball += (ans[i] == guess[j]);
    }
 
    printf("%d스트라이크 %d볼\n\n", strike, ball);
    fflush(stdout);
 
    // 추측과 답안이 일치하는 경우 답을 출력하고 프로그램을 종료한다.
    if (strcmp(ans, guess) == 0) {
      printf("%d번의 시도 끝에 정답을 찾아냈습니다: %s\n", n, ans);
      fflush(stdout);
      return 0;
    }
  }
}

// Usage : ./server (server's port to use)
// Example : ./server 9999

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "fcntl.h"
#include <unistd.h>

#define MSG_SIZE 4

int main(int argc, char *argv[]) {
  
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  int server_port;
  socklen_t sizeof_client_addr = sizeof(client_addr);
  char message[MSG_SIZE + 1];

  // init
  srand(time(NULL));
  server_port = atoi(argv[1]);
  printf("server port: %d\n", server_port);

  // bind
  printf("binding port: %d...\n", server_port);
  if ((server_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    printf("socket() error.\n");
    exit(1);
  }
  memset(&server_addr, 0x00, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(server_port);
  if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("bind() error.\n");
    exit(1);
  }

  // listen
  printf("listening port: %d...\n", server_port);
  if (listen(server_fd, 5) < 0) {
    printf("listen() error.\n");
    exit(1);
  }
  fcntl(server_fd, F_SETFL, fcntl(server_fd, F_GETFL, 0) | O_NONBLOCK);

  // accept
  printf("accepting...\n");
  do {
    sizeof_client_addr = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &sizeof_client_addr);
  } while (client_fd < 0);
  printf("accept port: %d!\n", server_port);

  // send
  message[MSG_SIZE] = '\n';
  for ( ; ; ) {
    for (int i = 0; i < MSG_SIZE; i++) {
      message[i] = rand() % 26 + 'A';
    }
    send(client_fd, message, sizeof(char) * (MSG_SIZE + 1), 0);
    printf("send : %s", message);
    sleep(1);
  }

  // close
  close(client_fd);
  close(server_fd);
  
  return 0;
  
}

// Usage : ./client (server's ip addr) (server's port)
// Example : ./client 192.168.56.101 9999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// size of buffer for receiving data packets
#define MSG_SIZE 4 // shuld be equal with MSG_SIZE at server.c

void printt(void);

// server connection information
struct sockaddr_in server_addr;

// file descriptor of client's socket
int client_fd;

// total bytes of each received packet
int recv_bytes;

// buffer for receiving data
char buffer[MSG_SIZE + 1];

int main(int argc, char *argv[]) {

  // Phase 1 : Connection Establishment ------

  // 1.1 Socket creation
  if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Client : Can't open stream socket\n");
    exit(1);
  }
  
  // 1.2 Connection with server
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(atoi(argv[2]));
  
  if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Connection failed\n");
    exit(1);
  }

  // Phase 2 : Data receiving ------
  for ( ; ; ) {

    // 2.1 Actual receiving process
    recv_bytes = recv(client_fd, buffer, MSG_SIZE + 1, 0);

    if (recv_bytes == 0) { // when server's gone
      printf("connection terminated by server.\n");
      close(client_fd);
      exit(0);
    }
    
    if (recv_bytes == -1) {
      printf("recv failed\n");
      exit(1);
    }
    
    printf("recv : %s", buffer);
    
  }
  
  return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 28790

int main(int argc, char *argv[]) {
  struct sockaddr_in server_addr;

  int server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr));

  char client_message[1000];
  struct sockaddr_in client_addr;

  socklen_t client_addr_len = sizeof(client_addr);
  recvfrom(server, client_message, sizeof(client_message), 0, (struct sockaddr*)&client_addr, &client_addr_len);

  while (true) {
    time_t now;
    time(&now);

    struct tm *time_info = localtime(&now);

    char resp_message[50];
    sprintf(resp_message, "Current time is %s\n", asctime(time_info));
    printf("%s", resp_message);
    sendto(server, resp_message, strlen(resp_message), 0, (struct sockaddr*)&client_addr, client_addr_len);
    sleep(1);
  }

  close(server);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 28790

int main(int argc, char *argv[]) {
  struct sockaddr_in server_addr, client_addr;

  int server = socket(AF_INET, SOCK_STREAM, 0);

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr));
  listen(server, 3);
  printf("Listening for connections on port %i\n", PORT);

  while (true) {
    int client = accept(server, NULL, NULL);

    char *resp = "HTTP/1.1 200 OK\nServer: LightestServer\nContent-Type: text/html;\nContent-Length: 12\n\nHello world!";
    send(client, resp, strlen(resp), 0);

    close(client);
  }

  return 0;
}

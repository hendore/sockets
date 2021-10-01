#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 5
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

  size_t msg_buffer_size = 50;
  char *msg_buffer = malloc(msg_buffer_size * sizeof(char));

  int client = accept(server, NULL, NULL);
  printf("Client connection was accepted\n");

  while (true) {
    printf("Message to broadcast: ");
    int len = getline((char **)&msg_buffer, &msg_buffer_size, stdin);
    send(client, msg_buffer, len, 0);
  }

  free(msg_buffer);
  close(client);

  return 0;
}

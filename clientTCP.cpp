#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

int main()
{
// Création du socket.    
SOCKET sock;
sock = socket(AF_INET, SOCK_STREAM, 0);
fprintf(stderr, "socket() message: %s\n", strerror(errno));

SOCKADDR_IN sin;
// Parametrer la structure et verifier si c'est la bonne qui est envoyée.
sin.sin_addr.s_addr = inet_addr("192.168.64.102");
sin.sin_family = AF_INET;
sin.sin_port = htons(9012);

connect(sock, (SOCKADDR*)&sin, sizeof(sin));

char buffer[11];
 buffer[0] = 'G';
 buffer[1] = 'r';
 buffer[2] = 'e';
 buffer[3] = 'g';
 buffer[4] = 'C';
 buffer[5] = 'l';
 buffer[6] = 'i';
 buffer[7] = 'e';
 buffer[8] = 'n';
 buffer[9] = 't';
 buffer[10] = '\0';

int error_message;
error_message = send(sock,buffer,sizeof(buffer),0);
if(error_message == 0){
fprintf(stderr, "sendto message erreur : %s\n", strerror(errno));
}

close(sock);

}



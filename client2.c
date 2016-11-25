#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

int main()
{
    int sd, n, len;
    struct sockaddr_in ser, cli;
    char text[50];

    if ((sd = socket(AF_INET,SOCK_STREAM, 0)) < 0)
        printf("\nSocket creation error\n");

    bzero(&ser, sizeof(ser));
    ser.sin_family = cli.sin_family = PF_INET;
    ser.sin_port = htons(10000);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
    len = sizeof(ser);

    if ((connect(sd, (struct sockaddr*)&ser, len)) < 0) {
        printf("\nError connection");
        exit(0);
    }
    while(1) {
        strcpy(text, " ");
        printf("\nEnter data which is to be sent:");
        scanf("%s", text);
        write(sd, text, strlen(text));
        read(sd, text, 50);
        printf("\nEcho msg from server:%s", text);
        if (strcmp(text, "exit") == 0)
            break;
    }
    close(sd);
}

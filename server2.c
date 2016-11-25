#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

int main()
{
    int sd, sd1, len, confd, n;
    struct sockaddr_in ser, cli;
    char msg[50];

    if((sd = socket(AF_INET,SOCK_STREAM, 0)) < 0)
        printf("\nSocket creation error\n");

    bzero(&ser, sizeof(ser));
    ser.sin_family = cli.sin_family = PF_INET;
    ser.sin_port = htons(10000);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
    len = sizeof(ser);

    if ((bind(sd, (struct sockaddr*)&ser, len)) < 0) {
        printf("\nBind Error");
        exit(0);
    }
    if (listen(sd, 2) == 0) {
        if ((sd1 = accept(sd, (struct sockaddr*)&ser, &len)) > 0) {
            do {
                bzero(&msg, 50);
                read(sd1, msg, 50);
                //int m=(int)msg;
                printf("\nMessage from client:%s\n", msg);
                write(sd1, msg, strlen(msg));
                if(strcmp(msg, "exit") == 0)
                    break;
            } while(strcmp(msg, "exit") != 0);
        }
    }
return 0;
}

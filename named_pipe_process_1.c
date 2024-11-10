#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


void main(){    
    char *myfifoPath = "./myfifo";
    mkfifo(myfifoPath, 0666);

    int fd = open(myfifoPath, O_WRONLY);
    char *message = "Hi, how are you";
    int val = write(fd, message, strlen(message));
    sleep(15);
    close(fd);
    exit(EXIT_SUCCESS);
}
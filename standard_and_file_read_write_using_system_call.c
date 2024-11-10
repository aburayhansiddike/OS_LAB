#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BUFFER_SIZE 200

void main(){
    int fd = open("test.txt", O_RDWR | O_CREAT, 0777);
    char *writeMessage = "OS Lab, khub voye aci";
    int n = write(fd, writeMessage, strlen(writeMessage));

    char buffer[BUFFER_SIZE];
    lseek(fd, 0, SEEK_SET);
    int numberOfChar = read(fd, buffer, BUFFER_SIZE - 1);
    buffer[numberOfChar] = '\n';
    write(STDOUT_FILENO, buffer, strlen(buffer));

    exit(EXIT_SUCCESS);
}
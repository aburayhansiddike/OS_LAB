#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(){
    char *myfifoPath = "./myfifo";
    int fd = open(myfifoPath, O_RDONLY);
    char buffer[200];
    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    printf("%s\n", buffer);
    exit(EXIT_SUCCESS);
}
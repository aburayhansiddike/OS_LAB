//incomplete

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>

void main(){

    char *myfifoPath1 = "./myfifo1";
    char *myfifoPath2 = "./myfifo2";

    if(access(myfifoPath1, F_OK) != 0){
        mkfifo(myfifoPath1, 0666);
    }

    int pid = fork();
    if(pid == 0){
        char buffer[200];
        while(1){
            int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
            int fd = open(myfifoPath1, O_WRONLY);
            write(fd, buffer, strlen(buffer));
        }
    }else{
       
    }
    exit(EXIT_SUCCESS);
}
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

    if(access(myfifoPath1, F_OK) != 0){
        mkfifo(myfifoPath1, 0666);
    }

    int pid = fork();
    if(pid == 0){

    }else{
        int fd = open(myfifoPath1, O_RDONLY);
        char buffer[100];
        while(1){
            read(fd, buffer, sizeof(buffer));
            printf("%s\n", buffer);
        }
        kill(pid, SIGKILL);
    }

    exit(EXIT_SUCCESS);
}
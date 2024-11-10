#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 100
void main(){

    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if(pid == 0){
        char *childMessage = "hi, how are you boy?";
        write(fd[1], childMessage, strlen(childMessage));
    }else{
        sleep(1);
        char buffer[BUFFER_SIZE];
        int numberOfCharacter = read(fd[0], buffer, sizeof(buffer) - 1);
        // printf("%d\n", (int) strlen(buffer));
        buffer[numberOfCharacter] = '\0';
        write(STDOUT_FILENO, buffer, strlen(buffer));
    }

    wait(NULL);
    exit(EXIT_SUCCESS);
}
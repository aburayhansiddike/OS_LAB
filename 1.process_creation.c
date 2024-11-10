#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

void main(){

    char *errorMessage = "Process creation is failed\n";
    pid_t pid = fork();
    if(pid == -1){
        write(STDOUT_FILENO, errorMessage, strlen(errorMessage));
    }

    if(pid == 0){
        char *childMessage = "From child process\n";
        write(STDOUT_FILENO, childMessage, strlen(childMessage));
    }else{
        char *parentMessage = "From parent process\n";
        write(STDOUT_FILENO, parentMessage, strlen(parentMessage));
    }

    exit(EXIT_SUCCESS);
}
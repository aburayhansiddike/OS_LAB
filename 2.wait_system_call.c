// Here wait() function wait for child process termination. After termination child process wait() return the terminated child process PID

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
        printf("Chile PID from parent : %d\n", getpid());

    }else{
        int childPid = wait(NULL);
        printf("child PID from parent is : %d\n", childPid);
    }

    exit(EXIT_SUCCESS);
}
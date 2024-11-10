#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void main(){
    pid_t pid = fork();
    if(pid == -1){
        printf("Process creation is failed\n");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        printf("Parent PID before sleep : %d\n", getppid());
        sleep(3);
        printf("Parent PID after sleep : %d\n", getppid());
    }else{

    }

    exit(EXIT_SUCCESS);
}
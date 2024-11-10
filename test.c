#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

void main(){

    pid_t pid = fork();
    if(pid == 0){
        printf("Child1 : %d\n", getpid());
    }else{
        pid = fork();
        if(pid == 0){
            printf("Child2 : %d\n", getpid());
        }else{
            printf("Done : %d\n", wait(NULL));
        }
    }
    exit(EXIT_SUCCESS);
}
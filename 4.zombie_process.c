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
       printf("Hi, from child\n");
    }else{
        sleep(10);
        wait(NULL);
        printf("Hi, from parent\n");
    }

    exit(EXIT_SUCCESS);
}
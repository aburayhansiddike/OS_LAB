#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    execlp("/home/rayhan/Desktop/os_lab/test", "", NULL);
    exit(EXIT_SUCCESS);
}
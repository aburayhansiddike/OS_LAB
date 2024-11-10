#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/shm.h>
#include<sys/wait.h>


sem_t mutex;
void main(){
    sem_init(&mutex, 1, 1);

    int shmid = shmget(121, 1024, 0777 | IPC_CREAT);
    int *taka = shmat(shmid, 0, 0);
    *taka = 100;

    pid_t pid = fork();
    if(pid == 0){
        for(int i = 1; i <= 100; i += 1){
            sleep(1);
            sem_wait(&mutex);
            int currTaka = *taka;
            currTaka = currTaka + 5;
            *taka = currTaka;
            sem_post(&mutex);
            printf("%d. Deposit : %d\n", i, currTaka);
        }
    }else{
        for(int i = 1; i <= 100; i += 1){
            sem_wait(&mutex);
            int currTaka = *taka;
            currTaka = currTaka - 5;
            *taka = currTaka;
            sem_post(&mutex);
            printf("%d. Withdraw : %d\n", i, currTaka);
            usleep(49999);
        }
        wait(NULL);
    }
    exit(EXIT_SUCCESS);
}

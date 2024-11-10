#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

int balance = 200;

pthread_mutex_t lock;
void *deposite(void *amount){
    for(int i = 0; i < 100; i++){
        pthread_mutex_lock(&lock);
        int tempBlance = balance;
        usleep(50000);
        tempBlance +=  *((int *) amount);
        balance = tempBlance;
        usleep(50000);
        printf("%d . deposit: %d\n", i, balance);
        pthread_mutex_unlock(&lock);
    }
}

void *withdraw(void *amount){
    for(int i = 0; i < 100; i++){
        pthread_mutex_lock(&lock);
        usleep(70000);
        int tempBlance = balance;
        tempBlance -= *((int *) amount);
        usleep(50000);
        balance = tempBlance;
        printf("%d. withdraw: %d\n", i + 1, balance);
        pthread_mutex_unlock(&lock);
    }
}
void main(){

    pthread_t tid1, tid2;
    int amount = 5;
    pthread_create(&tid1, NULL, deposite, (void *) &amount);
    pthread_create(&tid1, NULL, withdraw, (void *) &amount);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    //printf("Last Balance : %d\n", balance);
    exit(EXIT_SUCCESS);
}
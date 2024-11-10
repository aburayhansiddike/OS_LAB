#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include<unistd.h>

int set_cpu(pid_t pid, int cpu) {
    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set);           
    CPU_SET(cpu, &cpu_set);    

    if (sched_setaffinity(pid, sizeof(cpu_set_t), &cpu_set) == -1) {
        perror("sched_setaffinity failed");
        return -1;
    }
    return 0;
}

int main() {
    int cpu = sched_getcpu(); 

    if (cpu == -1) {
        perror("sched_getcpu failed");
    } else {
        printf("Before running on CPU %d\n", cpu);
    }

    set_cpu(getpid(), 2);
    cpu = sched_getcpu(); 

    if (cpu == -1) {
        perror("sched_getcpu failed");
    } else {
        printf("Before running on CPU %d\n", cpu);
    }
    return 0;
}

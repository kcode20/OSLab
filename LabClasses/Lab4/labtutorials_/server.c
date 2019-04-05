//
// Created by prajwal on 9/18/18.
//

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>

#define SHMSIZE     27

int main(){
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key=5678;

    /*creating a segment*/

    if((shmid=shmget(key,SHMSIZE,IPC_CREAT|0666))<0){
        perror("shmget");
        exit(1);
    }

    if((shm=shmat(shmid,NULL,0))==(char *)-1){
        perror("shmat");
    }

    s=shm;

    for(c='a';c<='z';c++)
        *s++=c;
    *s=0;

    while(*shm!='*')
        sleep(1);
    exit(0);
}

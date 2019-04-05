//
// Created by prajwal on 11/1/18.
//
#include <pthread.h>
#include <stdio.h>

unsigned long sum[4];

void * thread_fn(void * arg){
    long id = (long) arg;
    int start = id * 25;
    int i =1;

    while (i <= 25){
        sum[id] += (i+start);
        i++;
    }
    pthread_t tid = pthread_self();
    printf("My thread id id %lu and my id is  : %ld and sum is : %ld\n",tid, id,sum[id]);
    return NULL;
}

int main(){
    pthread_t t1, t2,t3,t4;
    pthread_create(&t1, NULL, thread_fn,(void *)0);
    pthread_create(&t2, NULL, thread_fn,(void *)1);
    pthread_create(&t3, NULL, thread_fn,(void *)2);
    pthread_create(&t4, NULL, thread_fn,(void *)3);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);

    printf("%lu\n",sum[0]+sum[1]+sum[2]+sum[3]);
    return 0;
}

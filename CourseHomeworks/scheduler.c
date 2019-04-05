#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h> 

struct PCB {
    char process_name[10];
    int PID;
    char state[10];
    int priority;
    int interruptable;
    int est_total_run_time;
    int est_remaining_run_time;
    struct PCB *prev;
  };

/* the HEAD of the Queue, hold the amount of struct PCB's that are in the queue*/
typedef struct Queue {
    struct PCB *head;
    struct PCB *tail;
    int size;
    int limit;
} Queue;

Queue *constructQueue(int limit);
void destructQueue(Queue *queue);
int enqueue(Queue *pQueue, struct PCB *item);
struct PCB *dequeue(Queue *pQueue);
int isEmpty(Queue* pQueue);

Queue *constructQueue(int limit) {
    Queue *queue = (Queue*) malloc(sizeof (Queue));
    if (queue == NULL) {
        return NULL;
    }
    if (limit <= 0) {
        limit = 65535;
    }
    queue->limit = limit;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void destructQueue(Queue *queue) {
    struct PCB *pN;
    while (!isEmpty(queue)) {
        pN = dequeue(queue);
        free(pN);
    }
    free(queue);
}

int enqueue(Queue *pQueue, struct PCB *item) {
    /* Bad parameter */
    if ((pQueue == NULL) || (item == NULL)) {
        return 0;
    }
    // if(pQueue->limit != 0)
    if (pQueue->size >= pQueue->limit) {
        return 0;
    }
    /*the queue is empty*/
    item->prev = NULL;
    if (pQueue->size == 0) {
        pQueue->head = item;
        pQueue->tail = item;

    } else {
        /*adding item to the end of the queue*/
        pQueue->tail->prev = item;
        pQueue->tail = item;
    }
    pQueue->size++;
    return 1;
}

struct PCB * dequeue(Queue *pQueue) {
    /*the queue is empty or bad param*/
    struct PCB *item;
    if (isEmpty(pQueue))
        return NULL;
    item = pQueue->head;
    pQueue->head = (pQueue->head)->prev;
    pQueue->size--;
    return item;
}

int isEmpty(Queue* pQueue) {
    if (pQueue == NULL) {
        return 0;
    }
    if (pQueue->size == 0) {
        return 1;
    } else {
        return 0;
    }
}


int main(int argc, char *argv[])  {

  struct Queue* readyqueue = constructQueue(10); 

  FILE *fp;
  char str[60];
  fp = fopen("processes.txt" , "r");
  if(fp == NULL) {
    perror("Error opening file");
    return(-1);
  }

  while(!feof(fp)){
    if( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
      char* tok;
      const char s[6] = ",";

      int counter = 0;
      char* temp[7];
      tok = strtok(str, s); 
      
      while( tok != NULL ) {
        temp[counter] = tok;
        counter++;
        tok = strtok(NULL, s);
      }
      struct PCB t;

      strcpy(t.process_name, temp[0]);
      t.PID = atoi(temp[1]);
      strcpy(t.state, temp[2]);
      t.priority = atoi(temp[3]);
      t.interruptable = atoi(temp[4]);
      t.est_total_run_time = atoi(temp[5]);
      t.est_remaining_run_time = atoi(temp[6]);
      enqueue(readyqueue, &t); 
      printf("%s\n", t.process_name);
      
    }
  }

  // char* myfifo = "/tmp/myfifo";
  // /* create the FIFO (named pipe) */
  // ret = mkfifo(myfifo, 0666);
  // if(ret == -1){
  //   printf("Failed to create the pipe!");
  // }

  struct PCB mine = *dequeue(readyqueue);

  printf("%s\t%d\t%s\t%d\t%d\t%d\t%d\n",
  mine.process_name, mine.PID, mine.state, mine.priority, mine.interruptable, mine.est_total_run_time, mine.est_total_run_time);

  struct PCB next = *dequeue(readyqueue);
  printf("%s\t%d\t%s\t%d\t%d\t%d\t%d\n",
  next.process_name, next.PID, next.state, next.priority, next.interruptable, next.est_total_run_time, next.est_total_run_time);


  fclose(fp);


  return(0);
}

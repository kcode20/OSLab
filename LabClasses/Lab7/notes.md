#### Bounded Buffer Producer and Consumers

- Producer produces and stores in the buffer, consumers consume from the buffer.
- When producer is quick and consumer is slow producer has to be blocked.
- When the consumer is quick and the producer is slow the consumer has to be blocked.

```c
vsize buffer
void producer(){
  while(true){
    item = produce.item();
    if(count==N) sleep(empty)
    lock(mutex)
    insert_item(item)
    count++
    unlock(mutex)
    if(count == 1) wakeup(full)
  }
}

void consumer(){
  while(true){2
    if(count==0) sleep(full)
    lock(mutex)
    item= remove_item();
    count --
    unlcok(mutex)
    if(count == N-1) wakeup(empty)
    consume_item(item);
  }
}
```

#### Semaphores

- Introduced by Dijkstra
- Two function down as P and up as V
- Has different variants
  - Blocking semaphores similar to mutex
  - Non-blocking semaphore similar to spinlock
- Usualy initialized to 1

```c
void down(int* s){
  while(*s <=0);
  *s--
}
void up(int* s){
  *s++
}
```

The code to syncronize using a semaphore

```c
void producer(){
  while(true){
    item = produce.item();
    down(empty)
    lock(mutex)
    insert_item(item)
    unlock(mutex)
    up(full)
  }
}

void consumer(){
  while(true){
    down(full)
    lock(mutex)
    item= remove_item();
    unlock(mutex)
    up(empty)
    consume_item(item);
  }
}
```

Steps to create system V semaphore:
(The linux Programming Interface) TL PI - book

Create or open a semaphore set using semget

```c
int semget(key_t key, int nsems, int semflag);
```

- nsem is the number of semaphores in the set.

Initialize the semaphore in the set using semctl

```c
int semctl(int semid, semnum, int cmd, semun)
```

```c
union sermun{
  int val;
  struct semid_d s* buf;
  unsigned short* arr;
  struct semint * _buff;
}
struct semid{
  struct ipc_parm sem_parm;
  time_t sem_otime;
  time_t sem_ctime;
  unsigned long sem_nsend;
}
```

Perform operation on semaphore values using semop()

```c
int semop(int semid, struct sembuf* sups, unsigned int nsop);
```

- The sembuf is the array pointer to teh array that holds the operations to be performed

The struct for the sembuf looks like the following:

```c
struct sembuf{
  unsigned short serm_num; // the number for the semaphore you want to manipulate
  short semop; // the operation
  short sem_flg;
}
```

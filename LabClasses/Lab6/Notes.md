### Solutions for syncronization:

#### Review

In the last class we talked about syncronization issues, guiding principles to solve them (namely, musial exclusion, progress, and fairness), and some software solutions.

Today we will talk about hardware solutions for syncronization

#### Hardware Solutions for Syncronization

test_and_set -> (atomic)

usage:

```c
while(true){
  while(test_and_set(lock)==1);
  // CS
  lock=0
}
```

Equivalent code:
Xchg is the value responsible for managing the register values and memory

```c
int xchg(int* L, int v){
  int prev= *L;
  *L -v;
  return prev;
}

//1
int xchg(addr, value){
  %eax = value;
  xchg %eax, addr //inline assembly code
}

//2 Allows you to aquire the lock
void aquire(int* locked){
  while(1){
    if(xch(blocked,1)==0){
      break;
    }
  }
}

//3 Allows you to release the lock
void release(int* lock){
  lock=0;
}
```

The following is the underworkings of spinlocks, mutex, and semaphores.

- Spinlock: uses two functions aquire and release

| P1      | P2      |
| ------- | ------- |
| aquire  | aquire  |
| CS      | CS      |
| Release | Release |

One process aquires lock. The other process will wait in a loop repeatedly checking if the lock is available. The lock becomes available when the former process releases it.

- Register (Level 1)
- Cache
- Primary Memory
- Secondary Memory

##### Mutex:

How can we do better when we have busy waiting?

- Its critical section is locked then yield CPU
- Go to sleep
- When unlocking, wake up sleeping process

```c
// Abstract Implementation of Mutex
void lock(int* locked){
  while(1){
    if(xchg(locked,1)==0){
      break;
    }
    else{
      sleep();
    }
  }
}

voide unlock(int* locked){
  locked = 0;
  wakeup();
}
```

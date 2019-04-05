## Process Communication Using Shared Memory

#### (System V | Shared Memory)

- Allows two or more processes to share the same memory region
- Shared region becomes user space memory, so kernel internvension for PC
- So one process copies data to the shared memory, then data becomes available to all other processes sharing the smae segment.
- However system call to read/write and memory allocation is required.
- Syncronization between readers and writer is required.

### Steps

1. Call system shared memory get: shmget()

```c
int shmget(key_t key, size_t size, int shmflag)
```

2. Call system shared memory at: shmat()

```c
void * shmat(int shmod, const void shmaddr, int shmflg);
```

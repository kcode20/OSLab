# Threads

Suppose we want to find the sum of the first n consecutive numbers
Say n=1,000,000

```c
int addall(){
  counter=0;
  unsigned long sum=0;
  while{
    sum+=1;
    counter++;
  }
  return sum;
}
void main(){
  define sum;
  sum= addall();
  print(sum)
}
```

#### Processes vs Threads:

Although we can use processes to get the sum, there are some benefits of threads:

##### Threads:

- No unique heap section, data segment which the process has.
- Threads do not exist on it's own.
- More than one thread in a process and each thread has its own stack
- If thread dies, it's stack is reclaimed.

##### Process

- Has their own copy of the data section, stack and Heap section
- Process has itself as main thread and so has at least a thread
- Processes are independent entities and has their own memory area.
- All threads die when process die.

#### What happens if a thread calls fork()?

- A new process is created, it has the same amount of threads as the parent process.
- The only active thread in the newly created process will now be the thread that made the fork call. When you call fork() it starts the process from th at line.

#### Supplemental Exercise

In the exercise in the `thread_example.c` there are two functions that we call:

```c
int pthread_create(pthread_t *thread, void *(* start_routine)(void*), void *arg);

int pthread_join(pthread_t thread, void** retval)
```

- pthread_create: creates a new thread.
- pthread_join: this waits for the thread to be terminated.

#### Useful Links

http://man7.org/linux/man-pages/man3/pthread_create.3.html
http://man7.org/linux/man-pages/man3/pthread_join.3.html

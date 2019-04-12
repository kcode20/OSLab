# Thread Management

### User Threads vs Kernel Level Threads

- User Level
  - Thread management done by the user thread library
  - Kernel knows nothing about the thread
- Kernel Level
  - Threads directly supported by the kernel
  - Known as lightweight process

### Advantages of User Level Threads:

- No system calls to manage threads. The thread library does everything
- Can be implemented in the OS that doesn't support threading.
- Switching is fast. No need to switch from user to protected thread.

### Disadvantages of User Level Threads:

- Scheduling
- Lack of Coordination
- System Call

### Disadvantages of Kernel Level Threads:

- Kernel level threads are slow.
- Overheads in the Kernel. Since kernel has to manage and schedule threads as a well as processes it requires full thread control block (TCB), for each thread to maintain information about threads.

### Related Resources:

http://www.cs.iit.edu/~cs561/cs450/ChilkuriDineshThreads/dinesh's%20files/User%20and%20Kernel%20Level%20Threads.html

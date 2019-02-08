### Lab 2

Today we are going to go over the `fork()` function and how it relates to the file system

##### References:

- https://www.geeksforgeeks.org/fork-system-call/
- http://man7.org/linux/man-pages/man2/fork.2.html

##### What is Fork

A `fork()` creates a new process by duplicating the calling process. The new process is referred to as a `child` process. The calling process is referred to as a `parent`

```c
int main () {
  int a = 5;
  int rc = fork();
  if(rc==0){}
  else{}
}
```

The only difference between the `child` and the `parent` processes is the processID and the value of `rc`. The child will have a value of 5 as `rc`. The parent will always execute the else block, it will be returned the processID of the child.

Let's say that we add another fork:

```c
int main () {
  int a = 5;
  int rc = fork();
  int rc1 = fork();
}
```

Now there are 4 total processes, 2 parents and 3 children.

Checkout the Fork Exercise in fork.c

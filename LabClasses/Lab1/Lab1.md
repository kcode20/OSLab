#### The basics of C programming

The basic program looks like this:

```c
# include <stdio.h>
int main(){
  ...
}
```

To run the code:
gcc -ot

What is the difference between a program and a process:

- Our processes are stored in RAM
- Our program is stored in storage

```c
#include <stdio.h>
  int count = 3;
  void (){
    ...
  }

  int main(){
    int a, b;
    scanf(");
    b= malloc(size(int));
    func();
  }
```

Every process is given memory and
We will be doing paging / segmentation
printf() --> write --> trap handles --> implementation of write system call
between the write and trap handles is the change from user mode to kernel mode.

## The `chmod` Command

Let's say someone runs the command:

```
chmod 777 abc.txt
```

This command gives read, write, and execute permissions to the file abc.txt

```c
char b[100];
int fd=open("abc.txt", create , mode_t); // the mode is the permission level that you are going to give (ex. 0777), if the file doesn't exist create it.
read(fd, b, 10); // read file fd, with buffer b, only 10 characters
write(fd, b, 7);
```

It will return a unique number.

#### Lab 1 Assignment (Due Feb. 15)

You have:

- 0:
  - check the permission: source.txt
  - create a new file called destination.txt
- 1
  - mimic `cat` command
  - TIP: to write to the console : `write(1, _ , _)`
- 2
  - mimic cp command
  - TIP: read from one, write to the other
- 3
  - you have source (255 bytes) and a destination (0 bytes), you have to read from source/write to the destination by a 100 bytes at a time
  - TIP: you have to use a buffer and update the buffer as you read
  - TIP: when you read, assign the bytes you read, if it's less than 100bytes then return the read number to the write function

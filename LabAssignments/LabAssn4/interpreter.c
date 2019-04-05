/*

Recall: In Task 3, we worked with exec() system calls for specific commands such as date, and ls.
Write a special simple command interpreter that takes a command and its arguments. This interpreter is a program where the main process creates a child process to execute the command using exec() family functions. After executing the command, it asks for a new command input (i.e., parent
wait for child). The interpreter program will get terminated when the user enters quit.

*/

#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]){
  int rc = fork();
  if(rc == 0 ){
    printf("I am the child, my pid is: %d\n", getpid()); 
    execvp(argv[0], argv);
    printf ("EXECVP Failed\n");
    /* The above line will be printed only on error and not otherwise */
  }
}

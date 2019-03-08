/*
Write a program where a child is created to execute command that tells you the date and time in Unix.
Use execl(...).
Note, you need to specify the full path of the file name that gives you date and time information. Announce the successful forking of child process by displaying its PID.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main (int argc, char *argv[]){
  int rc = fork();
  if(rc == 0 ){
    printf("I am the child, my pid is: %d\n", getpid()); 
    execl("/bin/date", argv[0], NULL);
    printf ("EXECVP Failed\n");
  }
  
  /* The above line will be printed only on error and not otherwise */
}

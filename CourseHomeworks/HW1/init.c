/*
This file writes a program init.c, which will act as an init program and fork off two child processes. The two child processes will then be overwritten by a scheduler and cpu_emulator.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern int errno;

int main(int argc, char* argv[]){
  int rc = fork();  
  if(rc==0){
      printf("I am child one, my pid is: %d\n", getpid());
      execl("cpu_emulator.py", argv[0], NULL);
      printf("EXECL failed for child one\n"); 
      perror("");
  }
  else{
    int rx = fork();
    if(rx==0){
      printf("I am child two, my pid is: %d\n", getpid());
      execl("scheduler.py", argv[0], NULL);
      perror("EXECL failed for child two");
    }
    // int status;
    // waitpid(child1, &status, 0); // make sure parent terminates after child1
    // waitpid(child2, &status, 0); // make sure parent terminates after child2
  }
  return 0;
}

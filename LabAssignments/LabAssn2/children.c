/*
Write a program children.c, and let the parent process produce two child processes. One prints out "I am child one, my pid is: " PID, and the other prints out "I am child two, my pid is: " PID.
Guarantee that the parent terminates after the children terminate (Note, you need to wait for two child processes here). Use the getpid() function to retrieve the PID.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  int rc=2;
  int count = 0;
  int child1, child2;
  while(count++ < 2 && (rc = fork()));
  
  /*
    getpid - returns the process ID of the calling process
    getppid - return the parent process ID of the calling process
  */
  if(rc==0){
    if(count==1){
      child1 = getpid();
      printf("I am child one, my pid is: %d\n", child1);
    }
    if(count==2){
      child2 = getpid();
      printf("I am child two, my pid is: %d\n", child2);
    }
  }
  if(rc>0){
    int status;
    waitpid(child1, &status, 0); // make sure parent terminates after child1
    waitpid(child2, &status, 0); // make sure parent terminates after child2
  }
}

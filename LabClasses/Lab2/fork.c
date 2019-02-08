/*
Fork Exercise:
try to create a process that has 10 child processes with the same parent ID
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  int rc=2;
  int count = 0;
  while(count++ < 10 && (rc = fork()));
  
  /*
    getpid - returns the process ID of the calling process
    getppid - return the parent process ID of the calling process
  */
  if(rc==0){
    printf("%d. My id is %d and my parent is %d\n",count, getpid(),getppid());
  }
  else if(rc>0){
    printf("%d. I am the parent and my pid is %d\n",count, getpid());
  }
}


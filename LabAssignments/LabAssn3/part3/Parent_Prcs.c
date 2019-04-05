#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>

int main (int argc, char* argv[]){
  int rc1 = fork();
  if(rc1 == 0 ){
    printf("I am the child, my pid is: %d\n", getpid()); 
    execl("Prcs_P1", argv[0], NULL);
    printf ("EXECVP Failed Prcs_P1\n");
  }
  else{
    sleep(5);
    int rc2 = fork();
    if(rc2 == 0){
      printf("I am the child, my pid is: %d\n", getpid()); 
      execl("Prcs_P2", argv[0], NULL);
      printf("EXECVP Failed Prcs_P2\n");
    }
  }
  /* The above line will be printed only on error and not otherwise */
}

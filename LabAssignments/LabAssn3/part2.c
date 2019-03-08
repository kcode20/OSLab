#include <stdio.h>
#include <unistd.h>

int main (){
  int rc = fork();
  if(rc == 0 ){
    printf("I am the child, my pid is: %d\n", getpid());
    char *argv[]={"ls","-lah", NULL}; 
    printf("%s/n",argv[0]);
    execvp (argv[0], argv);
    printf ("EXECVP Failed\n");
    /* The above line will be printed only on error and not otherwise */
  }
}

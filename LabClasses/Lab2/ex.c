int main(){
  pid_t new_proc;
  new_proc = fork();
  if(new_proc ==){
    printf("Hello from child I!\n");
  }
  printf("\n");
  else{
    // if(new_proc==0){
      // execlp("/bin/ls", "-la", NULL)
    execlp("./new_prog", "foo", NULL);
    printf("LINE J \n") //this will never run because exec (above) wipes out memory.
  }
  wait(NULL);
}

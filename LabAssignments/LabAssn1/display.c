#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int display(char* filename){
  int fd;
  errno = 0;
  fd = open(filename,O_RDONLY);
  if(-1 == fd){
    printf("\n open() failed with error [%s]\n",strerror(errno));
    return 1;
  }
  else {
    char b[100];
    int readNum;
    readNum = read(fd, b, 1048); // read file fd, with buffer b
    write(1, b, readNum);
  }
  return 0; 
}
/*
* This function takes a filename and displays the content of the screen
* @param argc - the argument count
* @param argv - an array of all the arguments
*/
int main(int argc, char* argv[]){
  char* filepath = argv[1];
  return display(filepath);
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/*
* This function copies a file from one place over to another
* @param source - pointer to the source file
* @param destination - pointer to the destination file
*/
int cp(char* source, char* destination){
  errno = 0;
  int fd = open(source, O_RDONLY);
  int fd2 = open(destination, O_RDWR | O_CREAT);
  if(-1 == fd){
    printf("\n open() failed with error [%s]\n",strerror(errno));
    return 1;
  }
  else {
    char b[100];
    int readNum;
    readNum = read(fd, b, 1048); // read file fd, with buffer b
    write(fd2, b, readNum);
  }
  return 0;
}

/*
* This function takes a filename and displays the content of the screen
* @param argc - the argument count
* @param argv - an array of all the arguments
*/
int main(int argc, char* argv[]){
  char* source = argv[1];
  char* destination = argv[2];
  return cp(source, destination);
}

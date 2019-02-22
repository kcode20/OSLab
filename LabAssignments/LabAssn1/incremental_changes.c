#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/*
* This function copies a file from one place over to another
* @param argc - the argument count
* @param argv - an array of all the arguments
*/
int cp(char* source, char* destination){
  errno = 0;
  int sourced = open(source, O_RDONLY);
  int destinationd = open(destination, O_RDWR | O_CREAT, 0700);
  char b[100];

  if(-1 == sourced || -1 == destinationd){
    printf("\n open() failed with error [%s]\n",strerror(errno));
    return 1;
  }
  else {
    int size = 1;
    while (size != 0){
      size = read(sourced, b, 100);
      for(int i = 0; i <= 100; i++){
        if (b[i] == '1'){
          b[i] = 'A';
        }
      }
      write(destinationd, b, size);
      // add 'XYZ' after 100 bytes
      write(destinationd, "XYZ", 3);
    }
  }
  close(sourced);
  close(destinationd);
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

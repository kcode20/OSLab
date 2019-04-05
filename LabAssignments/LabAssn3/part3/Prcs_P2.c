/*
Create two files namely, destination1.txt and destination2.txt with read, write,
and execute permissions.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

/*
* This function copies a file from a source to two destinations
* In destination1, it reads 100 characters and changes the 1 values to A
* In destination2, it reads 50 characters and changes the 2 values to B
* @param source - the source file
* @param destination1 - the first destination file
* @param destination2 - the second destination file
*/
int cp(char* source){
  errno = 0;
  char b1[100];
  char b2[50];
  printf("I am going to open the files!\n");

  printf("first let me open: %s\n", source);
  int s = open("source.txt", O_RDONLY);
  int d1 = open("destination1.txt", O_RDWR, 0700);
  int d2 = open("destination2.txt", O_RDWR, 0700);
  
  if(s == -1){
    printf("You suck! And the source sucks too\n");
    printf("\n open() failed with error [%s]\n",strerror(errno));
  }
  else if (d1 == -1){
    printf("You suck! And the destination1 sucks too\n");
  }
  else if (d2 == -1){
    printf("You suck! And the destination2 sucks too\n");
  }

    int size = 1;
    bool toggle;
    toggle = true; // toggle copy destination
    while(size != 0){
      // While there is still more to read from the document and its destination1's turn
    while (toggle == true){
      size = read(s, b1, 100);
      for(int i = 0; i <= 100; i++){
        if (b1[i] == '1'){
          b1[i] = 'A';
        }
      }
      write(d1, b1, size);
      // switch toggle
      toggle = false;
    }

    // While there is still more to read from the document and its destination1's turn
    while (toggle == false){
      size = read(s, b2, 50);
      for(int i = 0; i <= 50; i++){
        if (b2[i] == '2'){
          b2[i] = 'B';
        }
      }
      write(d2, b2, size);
      // switch toggle
      toggle = true;
    }
    printf("This is my size: %d\n", size);
    }

  // Close documents
  close(s);
  close(d1);
  close(d2);

  return 0;
}

/*
* This function takes a filename and invokes cp function on it
* @param argc - the argument count
* @param argv - an array of all the arguments
*/
int main(int argc, char* argv[]){
  char* source = argv[1];
  return cp(source);
}

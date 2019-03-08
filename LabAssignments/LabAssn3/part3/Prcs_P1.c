#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

/*
Create two files namely, destination1.txt and destination2.txt with read, write,
and execute permissions.
*/

int main (){
  int destination1 = open("destination1.txt", O_RDWR | O_CREAT, 0700);
  int destination2 = open("destination2.txt", O_RDWR | O_CREAT, 0700);
}

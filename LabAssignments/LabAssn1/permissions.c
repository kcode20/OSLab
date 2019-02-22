#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


/*
* Checks existence of the specified file
* @param filepath - the file to check existence
*/
void file_exists(char* filepath){
  int returnval = access(filepath, F_OK);
  if (returnval == 0)
    printf ("%s exists\n", filepath);
  else { 
    if (errno == ENOENT)
      printf ("%s does not exist\n", filepath);
    else if (errno == EACCES)
      printf ("%s is not accessible\n", filepath);
  }
}

/*
* Checks read permissions of the specified file
* @param filepath - the file to check permissions
*/
void file_read_permissions(char* filepath){
  int read_returnval=access(filepath, R_OK);
  if(read_returnval == 0)
    printf("%s has read access\n", filepath);
  else { 
    if (errno == EACCES)
      printf ("%s read access denied\n", filepath);
  }
}

/*
* Checks the write permissions of the specified file
* @param filepath - the file to check permissions
*/
void file_write_permissions(char* filepath){
  int write_returnval=access(filepath, W_OK);
  if(write_returnval == 0)
    printf("%s has write access\n", filepath);
  else { 
    if (errno == EACCES)
      printf ("%s write access denied\n", filepath);
  }
}

/*
* Checks existence and read and write permissions of the specified file
* @param filepath - the file to check permissions
*/
void check_all_permissions(char* filepath){
  file_exists(filepath);
  file_read_permissions(filepath);
  file_write_permissions(filepath);
}

/*
* Creates and opens a new file.
*/
int new_destination(){
  int fd;
  errno = 0;
  char* destination = "destination.txt";
  fd = open(destination, O_RDONLY|O_CREAT);
  if(-1 == fd){
    printf("\n open() failed with error [%s]\n",strerror(errno));
    return 1;
  }
  else {
    printf("\n Successfully created and opened 'destination.txt'\n");
  }
  return 0;
}

/*
* Main function, runs during execution
* @param argc - the argument count
* @param argv - an array of all the arguments
*/
int main (int argc, char* argv[]) {
  char* filepath = argv[1];
  check_all_permissions(filepath);
  return new_destination();
}

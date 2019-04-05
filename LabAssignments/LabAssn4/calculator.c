#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
* This function takes in a string and seperates it by space delimiters and stores this value in an array.
* @param input - string to be seperated
* @return - an array of the elements of the given string.
*/
int* split(char *input, int students){
	char delim[] = " ";
    int count = 0;
    int grade[4];

	char *ptr = strtok(input, " \t");

	while (ptr != NULL)
	{
        grade[count] = atoi(ptr);
		ptr = strtok(NULL, delim);
        count ++;
	}
    for(int i = 0; i<4; i++)
        printf("%d\n", grade[i]);

   return grade;
}

/*
* This function reads the grades and puts them in an array
* @param argc - the amount of arguments passed to program
* @param argv - an array of all arguments passed
*/
int main (int argc, char *argv[]){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char c[1000];
    int* grades;
    int students = 10;
    int count=0;

    fp = fopen("quiz_grades.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        grades[count] = split(line, students);
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}

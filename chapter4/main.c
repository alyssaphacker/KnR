#include <stdio.h>
#define MAXLINE 1000 //max input line len

int getLine(char line[],int max);
int strIndex(char source[], char searchfor[]);

char pattern[] = "ould"; //pattern to search for

//find all lines matching pattern 
int main(void) {
	char line[MAXLINE];
	int found = 0;

	while(getLine(line, MAXLINE) > 0)
		if(strIndex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}	
	return found;
}

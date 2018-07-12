//print all input lines > 80 chars
#include <stdio.h>
#define MAXLINE 10
int currentLine[MAXLINE];
int currentIndex = 0;
int threshold = 8;
int i = 0;
int c;

int main(){
	while((c = getchar()) != EOF){
		if(c != '\n'){
			currentLine[currentIndex++] = c;
		}
		if(c == '\n'){
	 		if(currentIndex > threshold){
				for(i = 0; i <= currentIndex; putchar(currentLine[i++]));
				putchar('\n');
			}	
			currentIndex = 0;
		}		
	}	
}

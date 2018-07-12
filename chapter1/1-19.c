#include <stdio.h>
#define MAXLINE 80
int line[MAXLINE], length;

int getLine(void){
	int c, i = 0;
	while((c=getchar()) != EOF && c != '\n'){
		line[i++] = c;
	}
	return i;
}
int reverseLine(void){
	int temp;
	for(int i = 0; i <= length/2; i++){
		temp = line[i];
		line[i] = line[length-i];
		line[length-i] = temp;
	}	
}
int putLine(void){
	for(int i = 0; i <= length; putchar(line[i++])){;}
	putchar('\n');
}
int main(void){
	while(length = getLine()){
		reverseLine();
		putLine();
	}
}

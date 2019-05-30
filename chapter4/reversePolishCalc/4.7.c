#include<stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; //buff for ungetch()
int bufp = 0;
int getch(void);
void ungetch(int);
void ungets(char *);


int main(void){
	char * s = "aye mayne";
	ungets(s);
	printf("the string is also in buf: %s", buf);
}

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charz\n");
	else
		buf[bufp++] = c;
}

void ungets(char * s){
	while(*s)
		ungetch(*s++);
}


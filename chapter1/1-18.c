//remove trailing blanks and tabs, delete blank lines 
#include <stdio.h>
#define MAXLINE 10
int line[MAXLINE];
int c, j, i = -1; //-1 not 0 so index is never too large for array lookup

int main(void){
	while((c=getchar()) != EOF){
		if(c != '\n'){
			line[++i] = c;
		}
		if(c == '\n'){
			while(line[i] == ' ' || line[i] == '\t'){--i;}
			for(j = 0; j <= i; putchar(line[j++])){;}
			if(i>0){putchar('\n');}
			i = -1;
		}
	}
}

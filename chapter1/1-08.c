#include <stdio.h>

int main(void){
	int c, b, nl, t;
	b = nl = t = 0;
	while((c = getchar()) != EOF){
		if(' ' == c){++b;}
		if('\n'== c){++nl;}
		if('\t'== c){++t;}
	}
	printf("Blanks: %i\nNewlines: %i\nTabs: %i\n", b, nl, t); 
}

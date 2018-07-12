#include <stdio.h>


int main(void){
	int c, i, n, lens[20];
	n = 0;
	for(i = 1; i < 21; ++i){
		lens[i] = 0;
	}
	while((c = getchar()) != EOF){
		//if not white space, then ++n
		if(c != ' ' && c != '\t' && c != '\n'){++n;}
		//if white space && n >0, then ++lens[n+'0']; n = 0
		if((c == ' ' || c == '\t' || c == '\n') && n > 0){
			++lens[n];
			n = 0;
		}	 
	}
	for(i = 1; i < 21; ++i){
		for(int j = 0; j < lens[i]; ++j){
			putchar('|');
		} 
		putchar('\n');
	}
}

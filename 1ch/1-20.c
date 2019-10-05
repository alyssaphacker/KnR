//replace tabs with equiv. number of spaces

#include <stdio.h>

int putcharTimes(int n, int c){
	for(int i = 0; i <= n; i++){
		putchar(c);
	}
}

int main(void){
	int c;
	while((c=getchar()) != EOF){
		if(c == '\t'){
			putcharTimes(4,' ');
		}else{putchar(c);}
	}
}

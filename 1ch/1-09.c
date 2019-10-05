#include <stdio.h> 

int c;

int ignoreIfNextIsSpace(void){
	if((c = getchar()) == ' '){
		ignoreIfNextIsSpace();
	}else{putchar(c);}	
}

int main(void){
	while((c = getchar()) != EOF){
		putchar(c);
		if(' ' == c){ignoreIfNextIsSpace();}
	}
}

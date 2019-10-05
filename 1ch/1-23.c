//remove all comments from a C program. Unfortunately, this 'works' if the pattern appears in a legit string. Maybe fix this.
#include<stdio.h>
int c;
int recurEndCheck(void){
	while((c=getchar()) != '*'){;}
	if(c == '*'){
		if((c=getchar()) != '/'){recurEndCheck();}
	}	
}

int main(void){
	while((c=getchar()) != EOF){
		if(c!='/'){putchar(c);}
		else if((c=getchar()) == '/'){
			while((c=getchar()) != '\n'){;}
		}
		else if(c == '*'){recurEndCheck();}
		
	} 
}

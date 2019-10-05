//replace inline whitespace with least no. of tabs and spaces
#include <stdio.h>

int c, buff = 0;

int putws(void){
	for(int i = 0; i < buff/4; i++){
		putchar('\t');
	}
	for(int i = 0; i < buff%4; i++){
		putchar(' ');
	}
}

int incbuff(void){
	if(c == ' '){buff++;}
	if(c == '\t'){buff += 4;}	
}
 
int main(void){
	while((c=getchar()) != EOF){
		if(c != ' ' && c != '\t'){
			if(buff == 0){
				putchar(c);
			}else{
				putws();
				buff = 0;
				putchar(c);
			}
		}else{
			incbuff();
		}
	}
}	
		


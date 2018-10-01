#include<stdio.h>
#include<stdlib.h>

//copy string s to t and prints tab and newline escaped
int escape(char * s, char * t){
	//variables for l/r sides of equation
	//lookup and assign from different counters
	//escape chars use an extra space
	int si = 0;
	int ti = 0;
	while(*(s+si) != '\0'){
		
		if(*(s+si) == '\n'){
			*(t+ti++) = '\\';
			*(t+ti++) = 'n';
		}
		if(*(s+si) == '\t'){
			*(t+ti++) = '\\';
			*(t+ti++) = 't';
		}
		else if(*(s+si) == '\b'){
			*(t+ti++) = '\\';
			*(t+ti++) = 'b';
		}
		else{
			*(t+ti++) = *(s+si);
		}
		si++; //this was not done until now. don't forget.
	
	}
	*(t+ti) = '\0';   	
}
int main(void){
	char *s1 = "\tThe\bstory\bwas\bgood!\n";
	char *s2 = malloc(256);
	escape(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", s2);


}

//strend(s,t) returns 1 if t occurs at end of s, else 0.

#include<stdio.h>

int strend(char * s, char * t);

int main(void){
	char foo[100] = "I have at least one but probably more than one submarine.";
	char bar[] = "marine.";
	printf("strend ret'd %s", strend(foo, bar) ? "true" : "false");
}

int strend(char * s, char * t){
	int i = 0;
	int j = 0;
	while(*(s+i++))
		;	
	while(*(t+j++))
		;
	char * u = s + i - j;
	while(*u && *u++ == *t++)
		;
	return *t? 0 : 1;	
}

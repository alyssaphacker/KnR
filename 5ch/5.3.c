//strcat(s,t) using ptrs

#include<stdio.h>
void strcat(char * s, char * t);
int main(void){
	char s[100] = "this is ", t[] = "the end.";
	printf("%s%s\n", s, t);
	strcat(s, t);
	printf("%s\n", s);
}

void strcat(char * s, char * t){
	while(*s++)
		;
	s--;
	while(*s++ = *t++)
		;
}


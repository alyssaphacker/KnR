//write itoa recursively

#include <stdio.h>

void itoa(int, char *);

int main(void){
	int foo = 1234;
	char bar[1024];
	itoa(foo, bar);
	printf("Answer: %s\n", bar);
}


void itoa(int i, char * s){
	static int j = 0;
	if(!i){
		*(s + j) = '\0';
		return;
	}
	itoa(i/10, s);
	*(s + j++) = i % 10 + '0';
}


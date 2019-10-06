#include <stdio.h>

void rrev(char * s){
	static int m=0;
	static int n=0;
	char t;

	if(*(s+m) == '\0'){
		m--;
		return;
	}
	m++;
	rrev(s);
	if(m>n){
		t = *(s+n);		
		*(s+n) = *(s+m);
		*(s+m) = t;
		n++;
		m--;
	}
}

int main(void){
	char s[] = "hello worldlings";
	rrev(s); 
	printf("%s\n", s);
	return 0;
}

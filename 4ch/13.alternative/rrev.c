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
	}else{
		m = n = 0;
	}
}

int main(void){
	char s[] = "hello worldlings";
	char w[] = "hopethisworks";
	char q[] = "abc";
	rrev(s); 
	rrev(w);
	rrev(q);
	printf("%s\n", s);
	printf("%s\n", w);
	printf("%s\n", q);
	rrev(s);
	printf("%s\n", s);
	
	return 0;
}

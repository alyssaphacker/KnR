/* In a two's complement num representation, our version of itoa does not handle largest neg num, ie, val of n = -(2^(wordsize-1)). why? modify program.*/

#include <string.h>
#include <stdio.h>

void reverse(char s[]) {
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[]) {
	long i, sign, ln = n;
	if ((sign = ln) < 0){ //record sign
		ln = -ln;		//make n positive
	}
	i = 0;
	do {				//generate digits in rev
		s[i++] = ln % 10 + '0';
	} while ((ln /= (long) 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(void) {
	/* rusty with c, testing reverse proc
	char s[] = "Hello World.";
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	*/

	/* example with atoi:
	int num = 5;
	char s[10]; //zeroed out locals?
	printf("%s\n", s);
	itoa(num, s);
	printf("%s\n", s);
	*/
	
	/*
	//int constants need cast
	int n = (1 << 31)  ;
	long m = ((long) 1 << (long) 31); //no cast would make max neg int
	printf(" %d, %ld", n, m);
	*/
	
	int n = -((long) 1 << (long) 31);
	//int n = -100;

	printf("Going to call itoa with n=%d\n", n);
	char s[20];
	itoa(n, s);
	printf("\n%s", s);

	
	
	
}






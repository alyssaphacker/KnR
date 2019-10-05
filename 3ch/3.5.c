/* Write itob(n,s,b) that converts int n to a base b character representation in the string s. Ie, itob(n,s,16) formats n as hex integer in s */


#include <string.h>
#include <stdio.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(void) {
	char str[20];
	itob(15, str, 16);
	printf("%s", str); 
	
	
}

/////////////////////////////////////////////
void itob(int n, char s[], int b) {
	if(b > 36){
		printf("%d > 36 is too large. Can only encode in [0-9]|[A-Z]", b); 
		return ; 
	}
	long i = 0, ln = n, t, sign;	
	if((sign = ln) < 0){	//record sign
		ln = -ln;			//make n positive
	}

	do{						//generate digits in rev
		if((t = ln % b) > 9) 
			s[i++] = t - 10 + 'A'; 
		else
			s[i++] = ln % b + '0';
	} while ((ln /= b) > 0);
	
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

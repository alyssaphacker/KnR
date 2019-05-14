/*
Write a version of itoa that accepts 3 args instead of 2. the 3rd arg is a min field width; the converted num must be padded w blanks on left if necessary

itoa(14,s,5) ]=> "00014"

*/
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

void itoa(int n, char s[], int w) {
	long i, sign, ln = n;
	if ((sign = ln) < 0){ //record sign
		ln = -ln;		//make n positive
	}
	i = 0;
	do {				//generate digits in rev
		s[i++] = ln % 10 + '0';
	} while ((ln /= (long) 10) > 0);
	while(i < w)
		s[i++] = '0';
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(void) {
	int n = -34; 

	printf("Going to call itoa with n=%d\n", n);
	char s[20];
	itoa(n, s, 5);
	printf("\n%s", s);

	
	
	
}






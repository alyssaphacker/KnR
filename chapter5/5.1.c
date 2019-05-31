/* getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a char back on input */
#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int main(void){
	int foo;
	getint(&foo);
	printf("You got: %d\n", foo);
}
/* getint: get next integer from input into *pn */
int getint(int *pn){
	int c, sign;

	while (isspace(c = getch())) //skip ws
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); //its not a num
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		if(!isdigit(c = getch())){
			ungetch(c); //ok so i followed the directions but...
			return getint(pn); //might as well look again lol...
		}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch buffer is full");
	else
		buf[bufp++] = c;
}

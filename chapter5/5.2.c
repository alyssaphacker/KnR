//write getfloat

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

int main(void){
	float foo;
	getfloat(&foo);
	printf("You got: %f\n", foo);
}

int getfloat(float *pn){
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
			return getfloat(pn); //might as well look again lol...
		}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if(c == '.'){
		float part = 0;
		float scale = 0.1;
		for( ; isdigit(c); c = getch(), scale *= 0.1)
			part += scale * c;
		*pn += scale;	
	}
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

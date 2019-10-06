#include<stdio.h>
#include<stdlib.h> //atoi()
#include<math.h>

#define MAXOP 100 //max size operator/nd
#define NUMBER '0' //signal that a number found
#define VARIABLE 'A'

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void duplic(void);
void clearval(void);

int main(void){
	int type;
	double op2;
	char s[MAXOP];
	int X, Y, Z;
	int Xlock, Ylock, Zlock;
	Xlock = Ylock = Zlock = 0;

	while ((type=getop(s))!=EOF){
		switch (type){
		case NUMBER:
			push(atof(s)); 
			break;
		case '+':
			push(pop()+pop()); 
			break;
		case '*':
			push(pop()*pop()); 
			break;
		case '-':
			op2=pop();
			push(pop()-op2); 
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0) 
				push(pop()/op2);
			else 
				printf("error: zero div\n"); 
			break;
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push((int) pop() % (int) op2);
			else
				printf("error: zero div\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop()); 
			break;
		case 'p':
			printf("Peak\t%.8g\n", peek()); 
			break; 
		case 'd': 
			printf("duplic'd\n");
			duplic();
			break;
		case 'k': //clear
			printf("clearval'd\n");
			clearval();
			break;
		case 's': //sin
			push(sin(pop()));
			break;			
		case '^': //power
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case 'e': //e raised
			push(exp(pop()));
			break;
		case 'X': 
			if(!Xlock++)
				X = peek();
			push(X);
			break;
		case 'Y': 
			if(!Ylock++)
				Y = peek();
			push(Y);
			break;
		case 'Z': 
			if(!Zlock++)
				Z = peek();
			push(Z);
			break;	default:
			printf("error: unknown cmd: %s\n", s); 
			break;
		}
	}
}
	
#define MAXVAL 100 //max stack depth

int sp = 0; //next free stakc position, stack ptr?
double val[MAXVAL];

void push(double f){
	if(sp<MAXVAL)
		val[sp++] = f;
	else
		printf("error: stakc full\n");
}
double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stck empty\n");
		return 0.0;
	}
}

double peek(void) {
	if(sp > 0)
		return val[sp -1];
	else{
		printf("error: stack emptie\n");
		return 0.0;
	}
}

void duplic(void) {
	if(sp<MAXVAL){
		val[sp] = val[sp -1];
		sp++;
	}
	else
		printf("error: val arr full");
	}
void clearval(void) {
	for(int k = 0; k <= sp; k++)
		val[k] = 0;
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c; //not a num
	i = 0;
	if(isdigit(c)) //collect int part
		while(isdigit(s[++i] = c = getch ()))
			;
	if(c == '.') //collect fract
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
} 

#define BUFSIZE 100

char buf[BUFSIZE]; //buff for ungetch()
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charz\n");
	else
		buf[bufp++] = c;
}


//Write a program to determine the ranges of char, short, int, and long, signed and unsigned, by printing appropriate  values from stanard library headers and by direct computation. Harder if you computer them: determine the ranges of the various floating-point types

#include <stdio.h>


int main(void){
//	short char a;
	char b;
//	long char c;
	signed char d;
	unsigned char e;

	short int f;
	int g;
	long int h;
	signed int i;
	unsigned int j;

	b = 1;
	while(b>0){b++;} //this will find overflowed negative 
	printf("%d min char\n", b);
	b = -1;
	while(b<0){b--;}
	printf("%d max char\n", b);
	
	d = 1;
	while(d>0){d++;} //this will find overflowed negative 
	printf("%d min signed char\n", d);
	d = -1;
	while(d<0){d--;}
	printf("%d max signed char\n", d);

	e = 1;
	while(e>0){e++;} //this will find overflowed negative 
	printf("%d min unsigned char\n", e);
	e = -1;
	while(e<0){e--;}
	printf("%d max unsigned char\n", e);
	
	f = 1;
	while(f>0){f++;} //this will find overflowed negative 
	printf("%d min short int\n", f);
	f = -1;
	while(f<0){f--;}
	printf("%d max short int\n", f);

	g = 1;
	while(g>0){g++;} //this will find overflowed negative 
	printf("%d min int\n", g);
	g = -1;
	while(g<0){g--;}
	printf("%d max int\n", g);

	h = 1;
	while(h>0){h++;} //this will find overflowed negative 
	printf("%ld min long int\n", h);
	h = -1;
	while(h<0){h--;}
	printf("%ld max long int\n", h);
	
	i = 1;
	while(i>0){i++;} //this will find overflowed negative 
	printf("%d min signed int\n", i);
	i = -1;
	while(i<0){i--;}
	printf("%d max signed int\n", i);
	
	j = 1;
	while(j>0){j++;} //this will find overflowed negative 
	printf("%d min unsigned int\n", j);
	j = -1;
	while(j<0){j--;}
	printf("%d max unsigned int\n", j);

}



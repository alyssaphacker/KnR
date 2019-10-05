#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n) ;
}

int main(int argc, char * argv[]){
	printf("%o\n", getbits(0b00001111, atoi(argv[1]), atoi(argv[2])));
}

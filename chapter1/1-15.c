#include <stdio.h>

int convert(int f){return 5 * (f - 32) / 9;}

int main(void){
	int fahr = 0;
	int low = 0;
	int high = 300;
	int step = 20;
	
	while(fahr <= high){
		printf("%i\t%i\n", fahr, convert(fahr));
		fahr = fahr + step;
	}
}

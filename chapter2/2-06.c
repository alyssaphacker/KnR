#include<stdio.h>
 /*i think this soln counts up n times from the position
	KnR expects it to count down.	*/
int setbits1(int x, int p, int n, int y){
	//rightmost n bits of y
	int right_most_y = ((1<<n) - 1) & y;
	//shifted p positions
	right_most_y = right_most_y << p;

	//high-end of x
	int high_x = x >> (n+p);
	high_x = high_x << (n+p);

	//low-end of x
	int low_x = x & ((1<<p)-1);

	return right_most_y | high_x | low_x;
}
//////////////////////////////////////////////////////
// first term moves desired field to right end
//second term is string of 1 with n zeros, notted 
unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}
//////////////////////////////////////////////////////
// 	getbits is UNDEFINED behavior for n + 1 > p
//	CANNOT SHIFT BY NEG RIGHT OPERAND!!!!!!!!!!!!!1111
///////////////////use getbits!///////////////////////

unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned x_high, x_low, y_part;
	//extract from y
	y_part = getbits(y, n-1, n);
	//align 
	y_part  <<= (p+1-n);
	//from x
	x_high = x << p;
	x_low = getbits(x, p+1-n, p+2-n);
	printf("y_part %u\nx_high %u\nx_low %u\n",
		y_part, x_high, x_low);
	printf("%u\n",y_part | x_high | x_low);
	return y_part | x_high | x_low;
}

int main(int argc, char ** argv){
	setbits(0, 5, 1, 1);



}



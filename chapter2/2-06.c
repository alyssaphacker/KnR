#include<stdio.h>

int setbits(int x, int p, int n, int y){
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

int main(int argc, char ** argv){
	int x = 15; 
	int y = 0;
	int n = 2;
	int p = 0;
	printf("x is %d\ny is %d\nn is %d\np is %d\n", x, y, n, p);
	printf("sebits() is %d\n", setbits(x, p, n, y));  	






}



#include<stdio.h>
int power(int, int);
int mask1(int, int);

int main(void){
	int p = 5;
	int n = 4;
	int x = 0xffffffff;		
	printf("%x\n",x);
	printf("%x\n", ~0);

	printf("%x\n",~0<<(p+n-1));
	printf("%x\n", (1<<n)-1);
	printf("%x\n",(~0<<(p+n-1)) | ((1<<n)-1));

//

	int y = 
}





int power(int base, int exp){
	while(exp > 1){
		base *= base;
		--exp;
	}
}

int mask1(int p, int n){
	int mask = ((~0 << (p+n-1)) + (1 << p) - 1); 
	return mask;
}

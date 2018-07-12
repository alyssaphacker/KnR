/*write htoi which takes a string of hex digits (optionally prefixed 0x or 0X) and returns the integer value.

0xABC09 ]=> 10*10^4 + 11x10^3 + 12*10^2 ...
 */
#include <stdio.h>

int main(void){
	int c, t = 0;
	while((c=getchar()) != EOF){	
		if(c >='0' && c <='9'){t = t*16 + (c-'0');}
		if(c >='a' && c <='f'){t = t*16 + (c-'a'+10);}
		if(c >='A' && c <='F'){t = t*16 + (c-'A'+10);}
	}
	printf("%d\n", t);
}


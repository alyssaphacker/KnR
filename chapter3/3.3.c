#include<stdio.h>

int c, buf1, buf2, buf3;

void main(void){
/*
stage1
read into buf1.
 if not num or digit, put char, restart stage1
 if num or digit, start stage2
stage2
read into buf2.
 if not '-' put buf1, but buf2, restart stage1
 if '-', start stage 3
stage3
 read into buf3.
 

*/

//	while((buf1=getchar()) != EOF){
//		if((buf2=getchar()) = '-'){
//			if((buf3=getchar()) = 
//		}
//	}

printf("%x%x %x%x %x%x", 'a', 'z', 'A', 'Z', '0', '9');



}

//function that takes num or alpha and returns t/f 
	//cond buf3 is char in range
	//61-7a 41-5a 30-39

//function that either enumerates or prints bufs
	//cond on boolean arg
	//if arg is #f, print buf1, buf2, buf3
	//if arg is #t, enumerate range buf1-buf2

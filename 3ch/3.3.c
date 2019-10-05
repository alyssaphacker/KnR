#include<stdio.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0
char string1[] = "hello a-z world";
char string2[32];

int c, buf1, buf2, buf3, off1, off2;

char get(char * s1){return s1[off1++];}
char put(char c, char * s2){return s2[off2++] = c;}
int match(void){
	if(buf1 >= 0x61 && buf1 <= 0x7a){
		if(buf3 >= buf1 && buf3 <= 0x7a){
			return TRUE;
		}else{
			return FALSE;
		}
	}else if(buf1 >= 0x41 && buf1 <= 0x5a){
		if(buf3 >= buf1 && buf3 <= 0x5a){
			return TRUE;
		}else{
			return FALSE;
		}
	}else if(buf1 >= 0x30 && buf1 <= 0x39){
		if(buf3 >= buf1 && buf3 <= 0x39){
			return TRUE;
		}else{
			return FALSE;
		}
	}else{return FALSE;}
}
void enumerate(char * s2){
	do{put(buf1++, s2);}
	while(buf1 <= buf3);
}
//declare 2 and 3 before used 
int stage2(char * s1, char *s2);
int stage3(char * s1, char *s2);
int stage1(char * s1, char * s2){
	buf1 = get(s1);
	if(buf1 == '\0'){
		put(buf1, s2);
		return 0;
	}else if( !isalpha(buf1) && !isdigit(buf1)){
		put(buf1, s2);
		return stage1(s1, s2);
	}else{
		return stage2(s1, s2);
	}
}
int stage2(char * s1, char * s2){
	buf2 = get(s1);
	if(buf2 == '\0'){
		put(buf1, s2);
		put(buf2, s2);
		return 0;
	}else if(buf2 != '-'){
		put(buf1, s2);
		put(buf2, s2);
		return stage1(s1, s2);
	}else{
		return stage3(s1, s2);
	}
}
int stage3(char * s1, char * s2){
	buf3 = get(s1);
	if(buf3 == '\0'){
		put(buf1, s2);
		put(buf2, s2);
		put(buf3, s2);
		return 0;
	}else if(match()){
		enumerate(s2);
	}else{
		put(buf1, s2);
		put(buf2, s2);
		put(buf3, s2);
	}
	return stage1(s1, s2);
}
void main(void){
	stage1(string1, string2);
	printf("%s\n", string1);
	printf("%s\n", string2);
}
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
 read into
	//cond buf3 is char in range
	//61-7a 41-5a 30-39
*/

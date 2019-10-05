//Write strrindex(s,t) returning position of rightmost 
//occurrence of t in s or -1 if none.
#include<stdio.h>

int strrindex(char *s, char t){
	int length=0;//find this with loop
	while(*(s+length) != '\0') length++;
	for(int index = length-1; index >= 0; index--){
		if(*(s+index) == t){return index;}
	}
	return -1;
	
}


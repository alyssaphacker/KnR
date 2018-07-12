#include <stdio.h>
//write any which returns index in s1 of first occurance of any in s2
int any(char s1[],char s2[]){
	int i, j;
	for(i=0; s1[i] != '\0'; i++){
		for(j=0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j]){
				return i;
			}
		} 
	}
	return -1;
}

int main(void){
	char s1[10] = "asdfjkl";
	char s2[10] = "d";
	printf("first occurence in %s of any of %s at position %d\n", s1, s2, any(s1, s2));
}

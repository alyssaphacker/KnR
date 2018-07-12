/* write alternate version of squeeze(s1,s2) that deletes chars in s1 that are in s2 */

#include <stdio.h>

//this is just squeeze from p. 47
void smallSqueeze(char s[], int c){
	int i, j;
	for(i=j=0; s[i] != '\0'; i++){
		if(s[i] != c){
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
	printf("%s", s);
}

void squeeze(char s1[], char s2[]){	//delete all char in s1 occur in s2
	int i, j, k, match = 0;
	for(i=j=0; s1[i] != '\0'; i++){	//for each member of s1
		match = 0;
		for(k=0; s2[k] != '\0'; k++){	//loop through s2
			if(s1[i] == s2[k]){	//is there a match
				match = 1;	//mark it
				break;
			}
		}
		if(!match){
			s1[j++] = s1[i];
		}
	} 
	printf("%s\n", s1);
}

int main(void){
	char s1[4] = "asd";
	char s2[2] = "a";
	squeeze(s1, s2);
}

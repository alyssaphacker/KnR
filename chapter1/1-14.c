#include <stdio.h>

int main(void){
	int i, c, a_z[26];
	
	for(i = 0; i < 26; ++i){
		a_z[i] = 0;
	}
	while((c = getchar()) != EOF){
		if(c >= 'a' && c <= 'z'){
			++a_z[c-'a'];
		}
	}
	for(i = 0; i < 26; i++){
		for(int j = 0; j < a_z[i]; ++j){
			putchar('|');
		}
		putchar('\n');	
	}
}

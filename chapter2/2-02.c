/* write a loop without && or || equivalent to 
	for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i){
		s[i] = c;
	}
*/

#include <stdio.h>
#define LIM 999
int i, s[LIM];
int main(void){
	i = 0;
	while(i<lim-1){
		if{(c=getchar()) != '\n'){
			if(c != EOF){	
				s[i++] = c;
			}
		}
	}
}

//this makes sense but i haven't checked it

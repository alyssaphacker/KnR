//split a line into smaller lines after last non-blank before n-th input
#include <stdio.h>
#define MAXLINE 80
int line[MAXLINE];
int indx = 0;

int fetchline(void){
	int c;
	while((c=getchar()) != EOF && c != '\n'){
		if(indx >= MAXLINE){
			printf("Too long\n");
			return 0;
		}else{line[indx++] = c;}		
	}
	return c != EOF;
}
int splitline(int n){
	int i, j, k, l;
	for(i = 1; i <= (indx / n); i++){
		for(j = (n*i) - 1; j > n*(i-1)-1 && (line[j] == ' ' || line[j] == '\t'); j--){;}
		for(k = n*(i - 1); k <= j; putchar(line[k++])){;}
		if(j > n*(i-1)-1){putchar('\n');}
	}
	
	for(j = indx; j > n*i-1 && (line[j] == ' ' || line[j] == '\t'); j--){;}
	for(k = n*i; k <= j; putchar(line[k++])){;}
	putchar('\n');	
}

int main(void){
	while(fetchline()){
		splitline(2);
		indx = 0; //could move to end of splitline or start of fetchline
	}		
}

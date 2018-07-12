#include <stdio.h>
#define MAXLINE 10

int gitline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len, max; //current line length, max seen so far
	char line[MAXLINE], longest[MAXLINE]; //current input line, longest saved
	
	max = 0;
	while((len = gitline(line, MAXLINE)) > 0){
		if(len > max){
			max = len;
			copy(longest, line);
		}	
	}
	if (max>0){
		if(max > MAXLINE){
			printf("Line length of %i is too long by %i chars\n", max, max-MAXLINE);
		}
		printf("%s", longest);
		return 0;
	}
}

int gitline(char s[], int lim){
	int c, i;

	for(i=0; i<lim-1 && (c=getchar()) != EOF && c !='\n'; ++i){
		s[i] = c;
	}
	if(c == '\n'){
		s[i] = c;
		i++;
	}
	if(i == (lim-1)){
		while((c = getchar()) != '\n'){
			++i;
		}
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0'){i++;}
}

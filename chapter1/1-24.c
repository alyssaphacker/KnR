#include <stdio.h>
#define MAX 999

int c, escaped = 0;
int quote(int q){
	if(c == q){
		while(((c=getchar()) != q) || escaped){
			if(c == '\'' || c == '"'){escaped = 0;}
			else if(c == '\\'){escaped = 1;}
			else if(c == EOF){return 1;}
		}
	}else{ 
		if(c=='\\'){escaped = 1;}else{escaped = 0;}
		return 0;
	}	
}
//create stack structure to check the nestable gylphs
int stack[MAX], i = -1;
int push(int c){stack[++i] = c;}
int pop(void){return stack[i--];}
//openings can always be added, closings have to be checked
int nest(void){
	if(c=='(' || c=='[' || c=='{'){
		push(c);
		return 0;
	}else if(c==')'){
		if(pop() == '('){return 0;
		}else{return 1;}
	}else if(c==']'){
		if(pop() == '['){return 0;
		}else{return 1;}	
	}else if(c=='}'){
		if(pop() == '{'){return 0;
		}else{return 1;}
	}else{return 0;}	
}

//make sure a * alone is not in the comment before it is closed with */
int recurEndCheck(void){
	//if the comment is never closed, error
	while((c=getchar()) != '*'){if(c == EOF){return 1;}}
	if(c == '*'){
		if((c=getchar()) != '/'){
			if(c == EOF){return 1;}
			recurEndCheck();
		}else{return 0;}
	}
}
int comment(void){
	if(c!='/'){return 0;
	//single line won't return error but skip text so syntax errors are not identified erroneously
	}else if((c=getchar()) == '/'){
		while((c=getchar()) != '\n'){;}
		return 0;
	//recursively check to see if next cha
	}else if(c == '*'){return recurEndCheck();}
}


// each subroutine returns 1 if it found a syntax error
int main(void){
	while((c=getchar()) != EOF){
		if(quote('\'') || quote('\"')){
			printf("Unclosed '' or \"\"\n");
			return 1; //to return from while-loop
		}
		if(nest()){
			printf("Unclosed (), [], or {}\n");
			return 1;
		}
		if(comment()){
			printf("Unclosed multi-line comment\n");
			return 1;
		}
	}
	//need do make sure stack is empty at EOF!!!
	if(c==EOF && i >= 0){printf("Unclosed (), []. or {}\n");}
	return 1;
}



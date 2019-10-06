#include <stdio.h>

int main(int argc, char ** argv){
	if(argc == 1)
		return 1;
	for(int i=0; i < argc; i++){
		for(int j=0; argv[i][j] != '\0'; j++){
			putchar(argv[i][j]);
		}
		putchar('\n');
	}
}

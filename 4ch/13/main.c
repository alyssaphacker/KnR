#include <stdio.h>
#include <stdlib.h>
#include "rrev.h"

int main(int argc, char ** argv){
	
	if(argc == 1){
		printf("Usage: %s n1 [n2, n3, ...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for(int i=0; i<argc; i++){
		rrev(argv[i]);
		printf("%s ", argv[i]);
	}
	putchar('\n');

	exit(EXIT_SUCCESS);
}

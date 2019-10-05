#include <stdio.h>

int main(int argc, char ** argv){

	argv[1][0] = 'X';
	printf("%s\n", argv[1]);

	return 0;
}

/* verify the expression getchar() !=EOF is 0 or 1 */

#include <stdio.h>

int main(){
	printf("%i", getchar() != EOF);
}

/* convert from C to F instead of F to C */

#include <stdio.h>

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("%3c%6c\n", 'C', 'F');

	while(celsius <= upper){
		fahr = ((9.0/5.0) * celsius) + 32;
		printf("%3.0f %5.1f\n", celsius, fahr);
		celsius += step;
	}
}

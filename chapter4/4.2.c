#include<stdio.h>
#include<ctype.h>

//write atof that handles scientific notation
double atof(char s[]){
	double val, power;
	int i, sign, sci_mod, esign, tens = 0;

	for(i=0; isspace(s[i]); i++) 
		; //skip whitespace
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++){
			val = 10.0 * val + (s[i] - '0');		
			power *= 10.0;
	}
	if(s[i] == 'E' || s[i] == 'e'){
		i++;
		esign = (s[i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(tens= 0; isdigit(s[i]); i++){
			tens = 10*tens + (s[i] -'0');
		}
	}

	double temp_result = sign*val/power;
	//mul by ten to the n
	if(esign > 0){
		for(; tens > 0; --tens){
			temp_result *= 10;
		}
	}else{
		for(; tens > 0; --tens){
			temp_result /= 10;
		}
	}
	return temp_result;
}
int main(int argc, char *argv[]){
	char *this_string = "2.2E-3";
	double this_double = atof(this_string);
	printf("%s converts to %f\n", this_string, this_double);
}


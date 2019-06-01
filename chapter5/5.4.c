//strend(s,t) returns 1 if t occurs at end of s, else 0.

#include<stdio.h>

int strend(char * s, char * t);

int main(void){
	char foo[100] = "I have a at least one submarine.";
	char bar[] = "marine.";
	printf("strend ret'd %s", strend(foo, bar) ? "true" : "false");
}

int strend(char * s, char * t){
	int s_len = 0;
	int t_len = 0;
	char * tmp = s;
	while(*tmp++)
		s_len++;
	s_len++;
	tmp = t;
	while(*tmp++)
		t_len++;
	t_len++;
	char * ss = s + s_len - t_len;
	while(*ss++ == *t++) 
		;
	ss--;
	return (ss == s + s_len);
}

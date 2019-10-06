/* rrev.c */

char * findEnd(char *);
void recur(char *, char *);
void swap(char *, char *);


void rrev(char * start){
	if(*start == '\0')
		return;
	char * end = findEnd(start);
	recur(start, end);	
}


char * findEnd(char *s){
	if(*s == '\0')
		return s-1;
	else
		findEnd(s+1);
}
void recur(char * start, char * end){
	if(start > end)
		return;
	swap(start,end);
	recur(1+ start, end -1); 
}
void swap(char * a, char * b){
	char t = *a;
	*a = *b;
	*b = t;
}


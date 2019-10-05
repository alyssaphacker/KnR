#define BUFSIZE 100

char buf[BUFSIZE]; //buff for ungetch()
int bufp = 0;

int getch(void){
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
        if (bufp >= BUFSIZE)
                printf("ungetch: too many charz\n");
        else
                buf[bufp++] = c;
}

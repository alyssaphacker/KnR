#define MAXVAL 100 //max stack depth

int sp = 0; //next free stakc position, stack ptr?
double val[MAXVAL];

void push(double f){
        if(sp<MAXVAL)
                val[sp++] = f;
        else
                printf("error: stakc full\n");
}
double pop(void){
        if(sp > 0)
                return val[--sp];
        else{
                printf("error: stck empty\n");
                return 0.0;
        }
}

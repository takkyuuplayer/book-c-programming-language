#include <stdio.h>
int main()
{ 
    int c, nl, tb, bl;
    nl = 0;
    tb = 0;
    bl = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            ++nl;
        }
        if(c == ' ') {
            ++bl;
        }
        if(c == '\t') {
            ++tb;
        }
    }
    printf("nl = %d, tb = %d, bl = %d\n", nl, tb, bl);
}

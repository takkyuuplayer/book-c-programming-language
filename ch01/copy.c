#include <stdio.h>

int main()
{ 
    int c;
    while((c = getchar()) != EOF) {
        putchar(c);
        printf("\n%d", EOF);
        printf("\n%d", c != EOF);
    }
}
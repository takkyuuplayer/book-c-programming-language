#include <stdio.h>
int main()
{ 
    int c, prev;
    while((c = getchar()) != EOF) {
        if(prev != ' ' || c != ' ') {
            putchar(c);
        }
        prev = c;
    }
}

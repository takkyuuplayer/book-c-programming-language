// Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
// Kernighan, Brian W..C Programming Language(p.91).Pearson Education.Kindle Edition.
#include <stdio.h>

#define swap(type, x, y) \
    {                    \
        type tmp = x;    \
        x = y;           \
        y = tmp;         \
    }
int main()
{
    int x = 1;
    int y = 2;

    printf("x: %d, y: %d \n", x, y);
    swap(int, x, y);
    printf("x: %d, y: %d \n", x, y);

    return 0;
}
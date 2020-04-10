// Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
// Kernighan, Brian W.. C Programming Language (p. 88). Pearson Education. Kindle Edition.
#include <string.h>
#include <stdio.h>

void itoa(int, char[]);

int main()
{
    char s[1000];
    itoa(-1253, s);
    printf("%s\n", s);

    itoa(1253, s);
    printf("%s\n", s);
}

void itoa(int n, char s[])
{
    static int init = 1;
    static int idx = 0;
    if (init)
    {
        idx = 0;
        init = 0;
    }
    if (n < 0)
    {
        s[idx++] = '-';
        n = -n;
    }
    if (n / 10)
    {
        itoa(n / 10, s);
    }
    if (!init)
    {
        init = 1;
    }
    s[idx++] = n % 10 + '0';
    s[idx] = '\0';
}
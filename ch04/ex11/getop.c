// Exercise 4-11. Modify getop so that it doesn’t need to use ungetch. Hint: use an internal static variable.
// Kernighan, Brian W.. C Programming Language (p. 83). Pearson Education. Kindle Edition.
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;
    static char stack = EOF;
    if (stack != EOF)
    {
        s[0] = c = stack;
        stack = EOF;
        while (c == ' ' || c == '\t')
        {
            s[0] = c = getch();
        }
    }
    else
    {
        while ((s[0] = c = getch()) == ' ' || c == '\t')
        {
        }
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        return c;
    }
    i = 0;
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        stack = c;
    }
    return NUMBER;
}

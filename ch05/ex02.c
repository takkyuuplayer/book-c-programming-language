// Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
// Kernighan, Brian W.. C Programming Language (p. 97). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main()
{
    float r = 0.0;
    int s = getfloat(&r);

    printf("result: %d\n", s);
    printf("result: %3.6f\n", r);

    return 0;
}

int getfloat(float *pn)
{
    int c, sign;
    int wasSign = 0;
    double power;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        c = getch();
        wasSign = 1;
    }
    if (wasSign && !isdigit(c))
    {
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.')
    {
        c = getch();
    }
    for (power = 1; isdigit(c); c = getch())
    {
        power *= 10;
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int getch(void)    /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

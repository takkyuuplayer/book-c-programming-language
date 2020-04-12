// Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example, expr  2  3  4  +  * evaluates 2 × (3+4).
// Kernighan, Brian W.. C Programming Language (p. 118). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
int getop(char[]);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    double op2;

    while (--argc > 0)
    {
        switch (**(++argv))
        {
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        default:
            push(atof(*argv));
            break;
        }
    }
    printf("\t%.8g\n", pop());
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

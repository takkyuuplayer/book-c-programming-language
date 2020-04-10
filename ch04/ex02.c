// Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e−6 where a floating-point number may be followed by e or E and an optionally signed exponent.
// Kernighan, Brian W.. C Programming Language (p. 73). Pearson Education. Kindle Edition.

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100
//int _getline(char line[], int maxline);

int main(int argc, char const *argv[])
{
    double sum, atof(char[]);
    char line[MAXLINE];
    int _getline(char line[], int max);
    sum = 0;
    while (_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}

double atof(char s[])
{
    double val, power;
    int eSign;
    int ePower;
    int i, j, sign;

    for (i = 0; isspace(s[i]); i++)
    {
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    eSign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (ePower = 0; isdigit(s[i]); i++)
    {
        ePower = 10 * ePower + (s[i] - '0');
    }
    for (int ij = 0; ij < ePower; ij++)
    {
        if (eSign == -1)
        {
            power *= 10.0;
        }
        else
        {
            power /= 10.0;
        }
    }

    return sign * val / power;
}

int _getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
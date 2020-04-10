// Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
// Kernighan, Brian W.. C Programming Language (p. 88). Pearson Education. Kindle Edition.
#include <stdio.h>
#include <string.h>

void _reverse(char[]);

int main()
{
    char s[] = "abcde";
    _reverse(s);
    printf("%s\n", s);

    char t[] = "abcd";
    _reverse(t);
    printf("%s\n", t);
}

void _reverse(char s[])
{
    static int init = 1;
    static int idx = 0;
    if (init)
    {
        idx = 0;
        init = 0;
    }
    if (idx < strlen(s) / 2)
    {
        char tmp = s[idx];
        s[idx] = s[strlen(s) - 1 - idx];
        s[strlen(s) - 1 - idx] = tmp;
        idx++;
        _reverse(s);
    }
    if (!init)
    {
        init = 1;
    }
}
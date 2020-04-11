// Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
// Kernighan, Brian W.. C Programming Language (p. 107). Pearson Education. Kindle Edition.
#include <stdio.h>

void _strcat(char[], char[]);
int main()
{
    char to[1000];
    char *a = "Alice";
    char *b = "Bob";
    _strcat(to, a);
    _strcat(to, b);
    printf("%s\n", to);
}

void _strcat(char *s, char *t)
{
    int i, j;
    i = j = 0;
    while (*(s + i) != '\0') /* find end of s */
        i++;
    while ((*(s + i++) = *(t + j++)) != '\0') /* copy t */
        ;
}
